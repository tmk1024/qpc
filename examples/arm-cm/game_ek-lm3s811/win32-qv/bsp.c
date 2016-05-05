/*****************************************************************************
* Product: "Fly 'n' Shoot" game example, Win32-GUI
* Last updated for version 5.6.4
* Last updated on  2016-05-04
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Alternatively, this program may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GNU General Public License and are specifically designed for
* licensees interested in retaining the proprietary status of their code.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* Contact information:
* http://www.state-machine.com
* mailto:info@state-machine.com
*****************************************************************************/
#include "qpc.h"
#include "game.h"
#include "bsp.h"

#include "qwin_gui.h" /* QWIN GUI */
#include "resource.h" /* GUI resource IDs generated by the resource editior */

#include <stdio.h>    /* for _snprintf() */
#include <stdlib.h>

#ifdef Q_SPY
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>  /* Win32 API for multithreading */
    #include <winsock2.h> /* for Windows network facilities */
#endif


Q_DEFINE_THIS_FILE

/* local variables ---------------------------------------------------------*/
static HINSTANCE l_hInst;   /* this application instance */
static HWND      l_hWnd;    /* main window handle */
static LPSTR     l_cmdLine; /* the command line string */

static GraphicDisplay   l_oled; /* the OLED display of the EK-LM3S811 board */
static SegmentDisplay   l_userLED;  /* USER LED of the EK-LM3S811 board */
static SegmentDisplay   l_scoreBoard; /* segment display for the score */
static OwnerDrawnButton l_userBtn; /* USER button of the EK-LM3S811 board */

/* (R,G,B) colors for the OLED display */
static BYTE const c_onColor [3] = { 255U, 255U, 255U }; /* white */
static BYTE const c_offColor[3] = {  15U,  15U,  15U }; /* very dark grey */

static BYTE l_ship_pos = GAME_SHIP_Y; /* the current ship Y-position */

#ifdef Q_SPY
    enum QSUserRecords {
        PLAYER_TRIGGER = QS_USER,
        COMMAND_STAT
    };
    static SOCKET l_sock = INVALID_SOCKET;
    static uint8_t const l_clock_tick = 0U;
    static uint8_t const l_mouse      = 0U;
#endif

/* Local functions ---------------------------------------------------------*/
static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg,
                                WPARAM wParam, LPARAM lParam);

/*..........................................................................*/
static void playerTrigger(void) {
    static QEvt const fireEvt = { PLAYER_TRIGGER_SIG, 0U, 0U };
    QF_PUBLISH(&fireEvt, (void*)0);
}
/*..........................................................................*/
static void moveShipUp(void) {
    ObjectPosEvt *ope;
    if (l_ship_pos > 0U) {
        --l_ship_pos;
    }
    ope = Q_NEW(ObjectPosEvt, PLAYER_SHIP_MOVE_SIG);
    ope->x = (uint8_t)GAME_SHIP_X;
    ope->y = (uint8_t)l_ship_pos;
    QACTIVE_POST(AO_Ship, (QEvt *)ope, &l_mouse);
}
//............................................................................
static void moveShipDown(void) {
    ObjectPosEvt *ope;
    if (l_ship_pos < (GAME_SCREEN_HEIGHT - 3U)) {
        ++l_ship_pos;
    }
    ope = Q_NEW(ObjectPosEvt, PLAYER_SHIP_MOVE_SIG);
    ope->x = (uint8_t)GAME_SHIP_X;
    ope->y = (uint8_t)l_ship_pos;
    QACTIVE_POST(AO_Ship, (QEvt *)ope, &l_mouse);
}
/*..........................................................................*/
/* thread function for running the application main_gui() */
static DWORD WINAPI appThread(LPVOID par) {
    (void)par; /* unused parameter */
    return (DWORD)main_gui(); /* run the QF-nano application */
}

/*--------------------------------------------------------------------------*/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   LPSTR cmdLine, int iCmdShow)
{
    HWND hWnd;
    MSG  msg;

    (void)hPrevInst; /* unused parameter */

    l_hInst   = hInst;   /* save the application instance */
    l_cmdLine = cmdLine; /* save the command line string */

    /* create the main custom dialog window */
    hWnd = CreateCustDialog(hInst, IDD_APPLICATION, NULL,
                            &WndProc, "QP_APP");
    ShowWindow(hWnd, iCmdShow);  /* show the main window */

    /* enter the message loop... */
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

/*..........................................................................*/
static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg,
                                WPARAM wParam, LPARAM lParam)
{
    switch (iMsg) {

        /* Perform initialization upon cration of the main dialog window
        * NOTE: Any child-windows are NOT created yet at this time, so
        * the GetDlgItem() function can't be used (it will return NULL).
        */
        case WM_CREATE: {
            l_hWnd = hWnd; /* save the window handle */

            /* initialize the owner-drawn buttons...
            * NOTE: must be done *before* the first drawing of the buttons,
            * so WM_INITDIALOG is too late.
            */
            OwnerDrawnButton_init(&l_userBtn,
                       LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_BTN_UP)),
                       LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_BTN_DWN)),
                       LoadCursor(NULL, IDC_HAND));
            return 0;
        }

        /* Perform initialization after all child windows have been created */
        case WM_INITDIALOG: {
            GraphicDisplay_init(&l_oled,
                       BSP_SCREEN_WIDTH,  2U, /* scale horizontally by 2 */
                       BSP_SCREEN_HEIGHT, 2U, /* scale vertically by 2 */
                       GetDlgItem(hWnd, IDC_LCD), c_offColor);

            SegmentDisplay_init(&l_userLED,
                                1U,  /* 1 "segment" (the LED itself) */
                                2U); /* 2 bitmaps (for LED OFF/ON states) */
            SegmentDisplay_initSegment(&l_userLED,
                 0U, GetDlgItem(hWnd, IDC_LED));
            SegmentDisplay_initBitmap(&l_userLED,
                 0U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_LED_OFF)));
            SegmentDisplay_initBitmap(&l_userLED,
                 1U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_LED_ON)));

            SegmentDisplay_init(&l_scoreBoard,
                                4U,   /* 4 "segments" (digits 0-3) */
                                10U); /* 10 bitmaps (for 0-9 states) */
            SegmentDisplay_initSegment(&l_scoreBoard,
                 0U, GetDlgItem(hWnd, IDC_SEG0));
            SegmentDisplay_initSegment(&l_scoreBoard,
                 1U, GetDlgItem(hWnd, IDC_SEG1));
            SegmentDisplay_initSegment(&l_scoreBoard,
                 2U, GetDlgItem(hWnd, IDC_SEG2));
            SegmentDisplay_initSegment(&l_scoreBoard,
                 3U, GetDlgItem(hWnd, IDC_SEG3));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 0U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG0)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 1U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG1)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 2U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG2)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 3U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG3)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 4U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG4)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 5U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG5)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 6U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG6)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 7U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG7)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 8U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG8)));
            SegmentDisplay_initBitmap(&l_scoreBoard,
                 9U, LoadBitmap(l_hInst, MAKEINTRESOURCE(IDB_SEG9)));

            BSP_updateScore(0U);

            /* --> QP: spawn the application thread to run main() */
            Q_ALLEGE(CreateThread(NULL, 0, &appThread, NULL, 0, NULL)
                     != (HANDLE)0);
            return 0;
        }

        case WM_DESTROY: {
            BSP_terminate(0);
            return 0;
        }

        /* commands from regular buttons and menus... */
        case WM_COMMAND: {
            SetFocus(hWnd);
            switch (wParam) {
                case IDOK:
                case IDCANCEL: {
                    BSP_terminate(0);
                    break;
                }
            }
            return 0;
        }

        /* owner-drawn buttons... */
        case WM_DRAWITEM: {
            LPDRAWITEMSTRUCT pdis = (LPDRAWITEMSTRUCT)lParam;
            switch (pdis->CtlID) {
                case IDC_USER: {  /* USER owner-drawn button */
                    switch (OwnerDrawnButton_draw(&l_userBtn, pdis)) {
                        case BTN_DEPRESSED: {
                            playerTrigger();
                            SegmentDisplay_setSegment(&l_userLED, 0U, 1U);
                            break;
                        }
                        case BTN_RELEASED: {
                            SegmentDisplay_setSegment(&l_userLED, 0U, 0U);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                    break;
                }
            }
            return 0;
        }

        /* mouse input... */
        case WM_MOUSEWHEEL: {
            if ((HIWORD(wParam) & 0x8000U) == 0U) {/* wheel turned forward? */
                moveShipUp();
            }
            else { /* the wheel was turned backwards */
                moveShipDown();
            }
            return 0;
        }

        /* keyboard input... */
        case WM_KEYDOWN: {
            switch (wParam) {
                case VK_UP:
                    moveShipUp();
                    break;
                case VK_DOWN:
                    moveShipDown();
                    break;
                case VK_SPACE:
                    playerTrigger();
                    break;
            }
            return 0;
        }

    }
    return DefWindowProc(hWnd, iMsg, wParam, lParam) ;
}

/*--------------------------------------------------------------------------*/
void QF_onStartup(void) {
    QF_setTickRate(BSP_TICKS_PER_SEC); /* set the desired tick rate */
}
/*..........................................................................*/
void QF_onCleanup(void) {
}
/*..........................................................................*/
void QF_onClockTick(void) {
    static QEvt const tickEvt = { TIME_TICK_SIG, 0U, 0U };
    QF_TICK_X(0U, &l_clock_tick);  /* process time events for rate 0 */
    QF_PUBLISH(&tickEvt, &l_clock_tick); /* publish the tick event */
}

/*..........................................................................*/
void Q_onAssert(char const * const module, int_t loc) {
    char message[80];
    QF_stop(); /* stop ticking */
    QS_ASSERTION(module, loc, (uint32_t)10000U); /* report assertion to QS */
    SNPRINTF_S(message, Q_DIM(message) - 1,
               "Assertion failed in module %s location %d", module, loc);
    MessageBox(l_hWnd, message, "!!! ASSERTION !!!",
               MB_OK | MB_ICONEXCLAMATION | MB_APPLMODAL);
    BSP_terminate(-1);
}

/*..........................................................................*/
void BSP_init(void) {
    if (QS_INIT(l_cmdLine) == (uint8_t)0) { /* QS initialization failed? */
        MessageBox(l_hWnd,
                   "Cannot connect to QSPY via TCP/IP\n"
                   "Please make sure that 'qspy -t' is running",
                   "QS_INIT() Error",
                   MB_OK | MB_ICONEXCLAMATION | MB_APPLMODAL);
    }
    QS_OBJ_DICTIONARY(&l_clock_tick);
    QS_USR_DICTIONARY(PLAYER_TRIGGER);
    QS_USR_DICTIONARY(COMMAND_STAT);
}
/*..........................................................................*/
void BSP_terminate(int16_t result) {
#ifdef Q_SPY
    if (l_sock != INVALID_SOCKET) {
        closesocket(l_sock);
        l_sock = INVALID_SOCKET;
    }
#endif
    QF_stop(); /* stop the main QF application and the ticker thread */
    PostQuitMessage(result); /* post the Quit message to the GUI */

    GraphicDisplay_xtor(&l_oled);       /* cleanup the l_oled    resources */
    OwnerDrawnButton_xtor(&l_userBtn);  /* cleanup the l_userBtn resources */
    SegmentDisplay_xtor(&l_userLED);    /* cleanup the l_userLED resources */
    SegmentDisplay_xtor(&l_scoreBoard); /* cleanup the scoreBoard resources */
}
/*..........................................................................*/
void BSP_drawBitmap(uint8_t const *bitmap) {
    UINT x, y;
    /* map the EK-LM3S811 OLED pixels to the GraphicDisplay pixels... */
    for (y = 0; y < BSP_SCREEN_HEIGHT; ++y) {
        for (x = 0; x < BSP_SCREEN_WIDTH; ++x) {
            uint8_t bits = bitmap[x + (y/8U)*BSP_SCREEN_WIDTH];
            if ((bits & (1U << (y & 0x07U))) != 0U) {
                GraphicDisplay_setPixel(&l_oled, x, y, c_onColor);
            }
            else {
                GraphicDisplay_clearPixel(&l_oled, x, y);
            }
        }
    }
    GraphicDisplay_redraw(&l_oled); /* redraw the updated display */
}
/*..........................................................................*/
void BSP_drawNString(uint8_t x, uint8_t y, char const *str) {
    static uint8_t const font5x7[95][5] = {
        { 0x00U, 0x00U, 0x00U, 0x00U, 0x00U }, /* ' ' */
        { 0x00U, 0x00U, 0x4FU, 0x00U, 0x00U }, /* ! */
        { 0x00U, 0x07U, 0x00U, 0x07U, 0x00U }, /* " */
        { 0x14U, 0x7FU, 0x14U, 0x7FU, 0x14U }, /* # */
        { 0x24U, 0x2AU, 0x7FU, 0x2AU, 0x12U }, /* $ */
        { 0x23U, 0x13U, 0x08U, 0x64U, 0x62U }, /* % */
        { 0x36U, 0x49U, 0x55U, 0x22U, 0x50U }, /* & */
        { 0x00U, 0x05U, 0x03U, 0x00U, 0x00U }, /* ' */
        { 0x00U, 0x1CU, 0x22U, 0x41U, 0x00U }, /* ( */
        { 0x00U, 0x41U, 0x22U, 0x1CU, 0x00U }, /* ) */
        { 0x14U, 0x08U, 0x3EU, 0x08U, 0x14U }, /* * */
        { 0x08U, 0x08U, 0x3EU, 0x08U, 0x08U }, /* + */
        { 0x00U, 0x50U, 0x30U, 0x00U, 0x00U }, /* , */
        { 0x08U, 0x08U, 0x08U, 0x08U, 0x08U }, /* - */
        { 0x00U, 0x60U, 0x60U, 0x00U, 0x00U }, /* . */
        { 0x20U, 0x10U, 0x08U, 0x04U, 0x02U }, /* / */
        { 0x3EU, 0x51U, 0x49U, 0x45U, 0x3EU }, /* 0 */
        { 0x00U, 0x42U, 0x7FU, 0x40U, 0x00U }, /* 1 */
        { 0x42U, 0x61U, 0x51U, 0x49U, 0x46U }, /* 2 */
        { 0x21U, 0x41U, 0x45U, 0x4BU, 0x31U }, /* 3 */
        { 0x18U, 0x14U, 0x12U, 0x7FU, 0x10U }, /* 4 */
        { 0x27U, 0x45U, 0x45U, 0x45U, 0x39U }, /* 5 */
        { 0x3CU, 0x4AU, 0x49U, 0x49U, 0x30U }, /* 6 */
        { 0x01U, 0x71U, 0x09U, 0x05U, 0x03U }, /* 7 */
        { 0x36U, 0x49U, 0x49U, 0x49U, 0x36U }, /* 8 */
        { 0x06U, 0x49U, 0x49U, 0x29U, 0x1EU }, /* 9 */
        { 0x00U, 0x36U, 0x36U, 0x00U, 0x00U }, /* : */
        { 0x00U, 0x56U, 0x36U, 0x00U, 0x00U }, /* ; */
        { 0x08U, 0x14U, 0x22U, 0x41U, 0x00U }, /* < */
        { 0x14U, 0x14U, 0x14U, 0x14U, 0x14U }, /* = */
        { 0x00U, 0x41U, 0x22U, 0x14U, 0x08U }, /* > */
        { 0x02U, 0x01U, 0x51U, 0x09U, 0x06U }, /* ? */
        { 0x32U, 0x49U, 0x79U, 0x41U, 0x3EU }, /* @ */
        { 0x7EU, 0x11U, 0x11U, 0x11U, 0x7EU }, /* A */
        { 0x7FU, 0x49U, 0x49U, 0x49U, 0x36U }, /* B */
        { 0x3EU, 0x41U, 0x41U, 0x41U, 0x22U }, /* C */
        { 0x7FU, 0x41U, 0x41U, 0x22U, 0x1CU }, /* D */
        { 0x7FU, 0x49U, 0x49U, 0x49U, 0x41U }, /* E */
        { 0x7FU, 0x09U, 0x09U, 0x09U, 0x01U }, /* F */
        { 0x3EU, 0x41U, 0x49U, 0x49U, 0x7AU }, /* G */
        { 0x7FU, 0x08U, 0x08U, 0x08U, 0x7FU }, /* H */
        { 0x00U, 0x41U, 0x7FU, 0x41U, 0x00U }, /* I */
        { 0x20U, 0x40U, 0x41U, 0x3FU, 0x01U }, /* J */
        { 0x7FU, 0x08U, 0x14U, 0x22U, 0x41U }, /* K */
        { 0x7FU, 0x40U, 0x40U, 0x40U, 0x40U }, /* L */
        { 0x7FU, 0x02U, 0x0CU, 0x02U, 0x7FU }, /* M */
        { 0x7FU, 0x04U, 0x08U, 0x10U, 0x7FU }, /* N */
        { 0x3EU, 0x41U, 0x41U, 0x41U, 0x3EU }, /* O */
        { 0x7FU, 0x09U, 0x09U, 0x09U, 0x06U }, /* P */
        { 0x3EU, 0x41U, 0x51U, 0x21U, 0x5EU }, /* Q */
        { 0x7FU, 0x09U, 0x19U, 0x29U, 0x46U }, /* R */
        { 0x46U, 0x49U, 0x49U, 0x49U, 0x31U }, /* S */
        { 0x01U, 0x01U, 0x7FU, 0x01U, 0x01U }, /* T */
        { 0x3FU, 0x40U, 0x40U, 0x40U, 0x3FU }, /* U */
        { 0x1FU, 0x20U, 0x40U, 0x20U, 0x1FU }, /* V */
        { 0x3FU, 0x40U, 0x38U, 0x40U, 0x3FU }, /* W */
        { 0x63U, 0x14U, 0x08U, 0x14U, 0x63U }, /* X */
        { 0x07U, 0x08U, 0x70U, 0x08U, 0x07U }, /* Y */
        { 0x61U, 0x51U, 0x49U, 0x45U, 0x43U }, /* Z */
        { 0x00U, 0x7FU, 0x41U, 0x41U, 0x00U }, /* [ */
        { 0x02U, 0x04U, 0x08U, 0x10U, 0x20U }, /* \ */
        { 0x00U, 0x41U, 0x41U, 0x7FU, 0x00U }, /* ] */
        { 0x04U, 0x02U, 0x01U, 0x02U, 0x04U }, /* ^ */
        { 0x40U, 0x40U, 0x40U, 0x40U, 0x40U }, /* _ */
        { 0x00U, 0x01U, 0x02U, 0x04U, 0x00U }, /* ` */
        { 0x20U, 0x54U, 0x54U, 0x54U, 0x78U }, /* a */
        { 0x7FU, 0x48U, 0x44U, 0x44U, 0x38U }, /* b */
        { 0x38U, 0x44U, 0x44U, 0x44U, 0x20U }, /* c */
        { 0x38U, 0x44U, 0x44U, 0x48U, 0x7FU }, /* d */
        { 0x38U, 0x54U, 0x54U, 0x54U, 0x18U }, /* e */
        { 0x08U, 0x7EU, 0x09U, 0x01U, 0x02U }, /* f */
        { 0x0CU, 0x52U, 0x52U, 0x52U, 0x3EU }, /* g */
        { 0x7FU, 0x08U, 0x04U, 0x04U, 0x78U }, /* h */
        { 0x00U, 0x44U, 0x7DU, 0x40U, 0x00U }, /* i */
        { 0x20U, 0x40U, 0x44U, 0x3DU, 0x00U }, /* j */
        { 0x7FU, 0x10U, 0x28U, 0x44U, 0x00U }, /* k */
        { 0x00U, 0x41U, 0x7FU, 0x40U, 0x00U }, /* l */
        { 0x7CU, 0x04U, 0x18U, 0x04U, 0x78U }, /* m */
        { 0x7CU, 0x08U, 0x04U, 0x04U, 0x78U }, /* n */
        { 0x38U, 0x44U, 0x44U, 0x44U, 0x38U }, /* o */
        { 0x7CU, 0x14U, 0x14U, 0x14U, 0x08U }, /* p */
        { 0x08U, 0x14U, 0x14U, 0x18U, 0x7CU }, /* q */
        { 0x7CU, 0x08U, 0x04U, 0x04U, 0x08U }, /* r */
        { 0x48U, 0x54U, 0x54U, 0x54U, 0x20U }, /* s */
        { 0x04U, 0x3FU, 0x44U, 0x40U, 0x20U }, /* t */
        { 0x3CU, 0x40U, 0x40U, 0x20U, 0x7CU }, /* u */
        { 0x1CU, 0x20U, 0x40U, 0x20U, 0x1CU }, /* v */
        { 0x3CU, 0x40U, 0x30U, 0x40U, 0x3CU }, /* w */
        { 0x44U, 0x28U, 0x10U, 0x28U, 0x44U }, /* x */
        { 0x0CU, 0x50U, 0x50U, 0x50U, 0x3CU }, /* y */
        { 0x44U, 0x64U, 0x54U, 0x4CU, 0x44U }, /* z */
        { 0x00U, 0x08U, 0x36U, 0x41U, 0x00U }, /* { */
        { 0x00U, 0x00U, 0x7FU, 0x00U, 0x00U }, /* | */
        { 0x00U, 0x41U, 0x36U, 0x08U, 0x00U }, /* } */
        { 0x02U, 0x01U, 0x02U, 0x04U, 0x02U }, /* ~ */
    };
    UINT dx, dy;

    while (*str != '\0') {
        uint8_t const *ch = &font5x7[*str - ' '][0];
        for (dx = 0U; dx < 5U; ++dx) {
            for (dy = 0U; dy < 8U; ++dy) {
                if ((ch[dx] & (1U << dy)) != 0U) {
                    GraphicDisplay_setPixel(&l_oled, (UINT)(x + dx),
                                         (UINT)(y*8U + dy), c_onColor);
                }
                else {
                    GraphicDisplay_clearPixel(&l_oled, (UINT)(x + dx),
                                           (UINT)(y*8U + dy));
                }
            }
        }
        ++str;
        x += 6;
    }
    GraphicDisplay_redraw(&l_oled); /* redraw the updated display */
}
/*..........................................................................*/
void BSP_updateScore(uint16_t score) {
    /* update the score in the l_scoreBoard SegmentDisplay */
    SegmentDisplay_setSegment(&l_scoreBoard, 0U, (UINT)(score % 10U));
    score /= 10U;
    SegmentDisplay_setSegment(&l_scoreBoard, 1U, (UINT)(score % 10U));
    score /= 10U;
    SegmentDisplay_setSegment(&l_scoreBoard, 2U, (UINT)(score % 10U));
    score /= 10U;
    SegmentDisplay_setSegment(&l_scoreBoard, 3U, (UINT)(score % 10U));
}
/*..........................................................................*/
void BSP_displayOn(void) {
    SegmentDisplay_setSegment(&l_userLED, 0U, 1U);
}
/*..........................................................................*/
void BSP_displayOff(void) {
    SegmentDisplay_setSegment(&l_userLED, 0U, 0U);
    GraphicDisplay_clear(&l_oled);
    GraphicDisplay_redraw(&l_oled);
}


/*--------------------------------------------------------------------------*/
#ifdef Q_SPY /* define QS callbacks */

#include <time.h>

/*
* In this demo, the QS software tracing output is sent out of the application
* through a TCP/IP socket. This requires the QSPY host application to
* be started first to open a server socket (qspy -t ...) to wait for the
* incoming TCP/IP connection from the DPP demo.
*
* In an embedded target, the QS software tracing output can be sent out
* using any method available, such as a UART. This would require changing
* the implementation of the functions in this section, but the rest of the
* application code does not "know" (and should not care) how the QS ouptut
* is actually performed. In other words, the rest of the application does NOT
* need to change in any way to produce QS output.
*/

/*..........................................................................*/
static DWORD WINAPI idleThread(LPVOID par) {/* signature for CreateThread() */
    (void)par;
    while (l_sock != INVALID_SOCKET) {
        uint16_t nBytes;
        uint8_t const *block;

        /* try to receive bytes from the QS socket... */
        nBytes = QS_rxGetNfree();
        if (nBytes > 0U) {
            uint8_t buf[64];
            int status;

            if (nBytes > sizeof(buf)) {
                nBytes = sizeof(buf);
            }
            status = recv(l_sock, (char *)buf, (int)nBytes, 0);
            if (status != SOCKET_ERROR) {
                uint16_t i;
                nBytes = (uint16_t)status;
                for (i = 0U; i < nBytes; ++i) {
                    QS_RX_PUT(buf[i]);
                }
            }
        }
        QS_rxParse();  /* parse all the received bytes */

        nBytes = 1024U;
        QF_CRIT_ENTRY(dummy);
        block = QS_getBlock(&nBytes);
        QF_CRIT_EXIT(dummy);

        if (block != (uint8_t *)0) {
            send(l_sock, (char const *)block, nBytes, 0);
        }
        Sleep(20); /* sleep for xx milliseconds */
    }
    return (DWORD)0; /* return success */
}
/*..........................................................................*/
uint8_t QS_onStartup(void const *arg) {
    static uint8_t qsBuf[1024];  /* buffer for QS output */
    static uint8_t qsRxBuf[100]; /* buffer for QS receive channel */
    static WSADATA wsaData;
    char hostName[64];
    char const *src;
    char *dst;
    USHORT port = 6601; /* default QSPY server port */
    ULONG ioctl_opt = 1;
    struct sockaddr_in sockAddr;
    struct hostent *server;

    QS_initBuf(qsBuf, sizeof(qsBuf));
    QS_rxInitBuf(qsRxBuf, sizeof(qsRxBuf));

    /* initialize Windows sockets */
    if (WSAStartup(MAKEWORD(2,0), &wsaData) == SOCKET_ERROR) {
        printf("Windows Sockets cannot be initialized.");
        return (uint8_t)0;
    }

    src = (arg != (void const *)0)
          ? (char const *)arg
          : "localhost";
    dst = hostName;
    while ((*src != '\0')
           && (*src != ':')
           && (dst < &hostName[sizeof(hostName)]))
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    if (*src == ':') {
        port = (USHORT)strtoul(src + 1, NULL, 10);
    }

    l_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); /* TCP socket */
    if (l_sock == INVALID_SOCKET){
        printf("Socket cannot be created; error 0x%08X\n",
               WSAGetLastError());
        return (uint8_t)0; /* failure */
    }

    server = gethostbyname(hostName);
    if (server == NULL) {
        printf("QSpy host name %s cannot be resolved; error 0x%08X\n",
               hostName, WSAGetLastError());
        return (uint8_t)0;
    }

    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    memcpy(&sockAddr.sin_addr, server->h_addr, server->h_length);
    sockAddr.sin_port = htons(port);
    if (connect(l_sock, (struct sockaddr *)&sockAddr, sizeof(sockAddr))
        == SOCKET_ERROR)
    {
        printf("Cannot connect to the QSPY server; error 0x%08X\n",
               WSAGetLastError());
        QS_EXIT();
        return (uint8_t)0; /* failure */
    }

    /* Set the socket to non-blocking mode. */
    if (ioctlsocket(l_sock, FIONBIO, &ioctl_opt) == SOCKET_ERROR) {
        printf("Socket configuration failed.\n"
               "Windows socket error 0x%08X.",
               WSAGetLastError());
        QS_EXIT();
        return (uint8_t)0; /* failure */
    }

    /* set up the QS filters... */
    QS_FILTER_ON(QS_QEP_STATE_ENTRY);
    QS_FILTER_ON(QS_QEP_STATE_EXIT);
    QS_FILTER_ON(QS_QEP_STATE_INIT);
    QS_FILTER_ON(QS_QEP_INIT_TRAN);
    QS_FILTER_ON(QS_QEP_INTERN_TRAN);
    QS_FILTER_ON(QS_QEP_TRAN);
    QS_FILTER_ON(QS_QEP_IGNORED);
    QS_FILTER_ON(QS_QEP_DISPATCH);
    QS_FILTER_ON(QS_QEP_UNHANDLED);

    QS_FILTER_ON(QS_QF_ACTIVE_POST_FIFO);
    QS_FILTER_ON(QS_QF_ACTIVE_POST_LIFO);
    QS_FILTER_ON(QS_QF_PUBLISH);

    QS_FILTER_ON(PLAYER_TRIGGER);
    QS_FILTER_ON(COMMAND_STAT);

    /* return the status of creating the idle thread */
    return (CreateThread(NULL, 1024, &idleThread, (void *)0, 0, NULL)
            != (HANDLE)0) ? (uint8_t)1 : (uint8_t)0;
}
/*..........................................................................*/
void QS_onCleanup(void) {
    if (l_sock != INVALID_SOCKET) {
        closesocket(l_sock);
        l_sock = INVALID_SOCKET;
    }
    WSACleanup();
}
/*..........................................................................*/
void QS_onFlush(void) {
    uint16_t nBytes = 1000;
    uint8_t const *block;
    while ((block = QS_getBlock(&nBytes)) != (uint8_t *)0) {
        send(l_sock, (char const *)block, nBytes, 0);
        nBytes = 1000;
    }
}
/*..........................................................................*/
QSTimeCtr QS_onGetTime(void) {
    return (QSTimeCtr)clock();
}
/*..........................................................................*/
/*! callback function to reset the target (to be implemented in the BSP) */
void QS_onReset(void) {
    //TBD
}
/*..........................................................................*/
/*! callback function to execute a uesr command (to be implemented in BSP) */
void QS_onCommand(uint8_t cmdId, uint32_t param) {
    (void)cmdId;
    (void)param;
    QS_BEGIN(COMMAND_STAT, (void *)0) /* application-specific record begin */
        QS_U8(2, cmdId);
        QS_U32(8, param);
    QS_END()

    if (cmdId == 10U) {
        Q_onAssert("command", 10);
    }
}

#endif /* Q_SPY */
/*--------------------------------------------------------------------------*/
