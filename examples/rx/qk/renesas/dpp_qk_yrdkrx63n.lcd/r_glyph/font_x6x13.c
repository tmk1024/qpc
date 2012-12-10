/******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized.
* This software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY,
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY
* DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this
* software and to discontinue the availability of this software.
* By using this software, you agree to the additional terms and
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************/
/* Copyright (C) 2010 Renesas Electronics Corporation. All rights reserved. */
/* Code written for Renesas by Future Designs, Inc. www.teamfdi.com */

/******************************************************************************
* File Name : font_x6x13.c
* Version : 1.00
* Tool-Chain : Glyph - The Generic API for Graphics LCD API
* H/W Platform : RX62N Group
* Description : An 6 x 13 Font.
******************************************************************************
* History :
* : 21.07.2010 1.00 First Release
******************************************************************************/

/******************************************************************************
Includes �Glyph config Include�
******************************************************************************/
#include "..\Config.h"

const uint8_t Fontx6x13_char_0[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0x00,
    0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x00,
};
const uint8_t Fontx6x13_char_1[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0xC0, 0xE0, 0xC0, 0x80, 0x00,
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_2[] = {
    0x06, 0x0D, // width=6, height=13
    0x54, 0xAA, 0x54, 0xAA, 0x54, 0xAA,
    0x15, 0x0A, 0x15, 0x0A, 0x15, 0x0A,
};
const uint8_t Fontx6x13_char_3[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x40, 0xF0, 0x00, 0x00, 0x00,
    0x01, 0x02, 0x1F, 0x02, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_4[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x50, 0x10, 0x00, 0x00, 0x00,
    0x01, 0x1F, 0x05, 0x01, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_5[] = {
    0x06, 0x0D, // width=6, height=13
    0x60, 0x90, 0x90, 0x90, 0x00, 0x00,
    0x00, 0x1F, 0x05, 0x0D, 0x12, 0x00,
};
const uint8_t Fontx6x13_char_6[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x1F, 0x05, 0x01, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_7[] = {
    0x06, 0x0D, // width=6, height=13
    0x18, 0x24, 0x24, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_8[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0x40, 0xF0, 0x40, 0x40, 0x00,
    0x04, 0x04, 0x05, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_9[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x20, 0x40, 0x80, 0xF0, 0x00,
    0x01, 0x1E, 0x10, 0x10, 0x11, 0x00,
};
const uint8_t Fontx6x13_char_10[] = {
    0x06, 0x0D, // width=6, height=13
    0x30, 0x40, 0x80, 0x40, 0x30, 0x00,
    0x02, 0x02, 0x1E, 0x02, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_11[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_12[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_13[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_14[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0xFF, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_15[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0xFF, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_16[] = {
    0x06, 0x0D, // width=6, height=13
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_17[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_18[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_19[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
};
const uint8_t Fontx6x13_char_20[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
};
const uint8_t Fontx6x13_char_21[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0xFF, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_22[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_23[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0xFF, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_24[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_25[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_26[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x40, 0xA0, 0x10, 0x08, 0x00,
    0x04, 0x04, 0x04, 0x05, 0x06, 0x00,
};
const uint8_t Fontx6x13_char_27[] = {
    0x06, 0x0D, // width=6, height=13
    0x08, 0x10, 0xA0, 0x40, 0x00, 0x00,
    0x06, 0x05, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_28[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0xE0, 0x20, 0xE0, 0x20, 0x00,
    0x04, 0x03, 0x00, 0x07, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_29[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0x40, 0xC0, 0x40, 0x60, 0x00,
    0x03, 0x01, 0x01, 0x01, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_30[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0xF8, 0x44, 0x04, 0x08, 0x00,
    0x04, 0x03, 0x04, 0x04, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_31[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_32[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_33[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_34[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_35[] = {
    0x06, 0x0D, // width=6, height=13
    0xA0, 0xF8, 0xA0, 0xF8, 0xA0, 0x00,
    0x00, 0x03, 0x00, 0x03, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_36[] = {
    0x06, 0x0D, // width=6, height=13
    0x30, 0x48, 0xFC, 0x48, 0x88, 0x00,
    0x02, 0x02, 0x07, 0x02, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_37[] = {
    0x06, 0x0D, // width=6, height=13
    0x08, 0x94, 0x48, 0x30, 0x0C, 0x00,
    0x06, 0x01, 0x02, 0x05, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_38[] = {
    0x06, 0x0D, // width=6, height=13
    0xD8, 0x24, 0x58, 0x80, 0x80, 0x00,
    0x01, 0x02, 0x02, 0x01, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_39[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x10, 0x0C, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_40[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0xE0, 0x18, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_41[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x04, 0x18, 0xE0, 0x00, 0x00,
    0x00, 0x04, 0x03, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_42[] = {
    0x06, 0x0D, // width=6, height=13
    0xB0, 0xE0, 0xF8, 0xE0, 0xB0, 0x00,
    0x01, 0x00, 0x03, 0x00, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_43[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0x40, 0xF0, 0x40, 0x40, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_44[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x06, 0x02, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_45[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0x40, 0x40, 0x40, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_46[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x0E, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_47[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x80, 0x40, 0x30, 0x0C, 0x00,
    0x06, 0x01, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_48[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x08, 0x04, 0x08, 0xF0, 0x00,
    0x01, 0x02, 0x04, 0x02, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_49[] = {
    0x06, 0x0D, // width=6, height=13
    0x10, 0x08, 0xFC, 0x00, 0x00, 0x00,
    0x04, 0x04, 0x07, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_50[] = {
    0x06, 0x0D, // width=6, height=13
    0x18, 0x04, 0x84, 0x44, 0x38, 0x00,
    0x06, 0x05, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_51[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x44, 0x64, 0x54, 0x8C, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_52[] = {
    0x06, 0x0D, // width=6, height=13
    0x80, 0x60, 0x10, 0xFC, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x07, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_53[] = {
    0x06, 0x0D, // width=6, height=13
    0x7C, 0x44, 0x24, 0x24, 0xC4, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_54[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x44, 0x44, 0x44, 0x88, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_55[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x04, 0xC4, 0x34, 0x0C, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_56[] = {
    0x06, 0x0D, // width=6, height=13
    0xB8, 0x44, 0x44, 0x44, 0xB8, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_57[] = {
    0x06, 0x0D, // width=6, height=13
    0x38, 0x44, 0x44, 0x44, 0xF8, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_58[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x20, 0x70, 0x20, 0x00, 0x00,
    0x00, 0x04, 0x0E, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_59[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x20, 0x70, 0x20, 0x00, 0x00,
    0x00, 0x08, 0x06, 0x02, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_60[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0xA0, 0x10, 0x08, 0x04, 0x00,
    0x00, 0x00, 0x01, 0x02, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_61[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_62[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x08, 0x10, 0xA0, 0x40, 0x00,
    0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_63[] = {
    0x06, 0x0D, // width=6, height=13
    0x18, 0x04, 0x84, 0x44, 0x38, 0x00,
    0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_64[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x04, 0xC4, 0x24, 0xF8, 0x00,
    0x03, 0x04, 0x05, 0x05, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_65[] = {
    0x06, 0x0D, // width=6, height=13
    0xF0, 0x88, 0x84, 0x88, 0xF0, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_66[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0xFC, 0x44, 0x44, 0xB8, 0x00,
    0x04, 0x07, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_67[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x04, 0x04, 0x04, 0x08, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_68[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0xFC, 0x04, 0x04, 0xF8, 0x00,
    0x04, 0x07, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_69[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x44, 0x44, 0x44, 0x04, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_70[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x44, 0x44, 0x44, 0x04, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_71[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x04, 0x04, 0x84, 0x88, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_72[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x40, 0x40, 0x40, 0xFC, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_73[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x04, 0xFC, 0x04, 0x00, 0x00,
    0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_74[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x04, 0xFC, 0x04, 0x00,
    0x02, 0x04, 0x04, 0x03, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_75[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x40, 0xA0, 0x10, 0x0C, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x06, 0x00,
};
const uint8_t Fontx6x13_char_76[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_77[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x10, 0x60, 0x10, 0xFC, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_78[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x18, 0x60, 0x80, 0xFC, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_79[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x04, 0x04, 0x04, 0xF8, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_80[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_81[] = {
    0x06, 0x0D, // width=6, height=13
    0xF8, 0x04, 0x04, 0x04, 0xF8, 0x00,
    0x03, 0x04, 0x06, 0x04, 0x0B, 0x00,
};
const uint8_t Fontx6x13_char_82[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x44, 0xC4, 0x44, 0x38, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x06, 0x00,
};
const uint8_t Fontx6x13_char_83[] = {
    0x06, 0x0D, // width=6, height=13
    0x38, 0x44, 0x44, 0x44, 0x88, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_84[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x04, 0xFC, 0x04, 0x04, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_85[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x00, 0x00, 0x00, 0xFC, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_86[] = {
    0x06, 0x0D, // width=6, height=13
    0x3C, 0xC0, 0x00, 0xC0, 0x3C, 0x00,
    0x00, 0x01, 0x06, 0x01, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_87[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x00, 0xC0, 0x00, 0xFC, 0x00,
    0x07, 0x02, 0x01, 0x02, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_88[] = {
    0x06, 0x0D, // width=6, height=13
    0x0C, 0xB0, 0x40, 0xB0, 0x0C, 0x00,
    0x06, 0x01, 0x00, 0x01, 0x06, 0x00,
};
const uint8_t Fontx6x13_char_89[] = {
    0x06, 0x0D, // width=6, height=13
    0x0C, 0x30, 0xC0, 0x30, 0x0C, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_90[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x84, 0x44, 0x34, 0x0C, 0x00,
    0x06, 0x05, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_91[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0xFC, 0x04, 0x04, 0x00, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_92[] = {
    0x06, 0x0D, // width=6, height=13
    0x0C, 0x30, 0x40, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x06, 0x00,
};
const uint8_t Fontx6x13_char_93[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x04, 0x04, 0xFC, 0x00, 0x00,
    0x00, 0x04, 0x04, 0x07, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_94[] = {
    0x06, 0x0D, // width=6, height=13
    0x10, 0x08, 0x04, 0x08, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_95[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
};
const uint8_t Fontx6x13_char_96[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x04, 0x0C, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_97[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0xA0, 0xA0, 0xA0, 0xC0, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_98[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x20, 0x20, 0x20, 0xC0, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_99[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0x20, 0x20, 0x20, 0x40, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_100[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0x20, 0x20, 0x20, 0xFC, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_101[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0xA0, 0xA0, 0xA0, 0xC0, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_102[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0xF8, 0x44, 0x44, 0x08, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_103[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0x20, 0x20, 0x20, 0xC0, 0x00,
    0x09, 0x12, 0x12, 0x12, 0x0F, 0x00,
};
const uint8_t Fontx6x13_char_104[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x40, 0x20, 0x20, 0xC0, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_105[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x20, 0xE8, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_106[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0x20, 0xE8, 0x00, 0x00,
    0x0C, 0x10, 0x10, 0x0F, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_107[] = {
    0x06, 0x0D, // width=6, height=13
    0xFC, 0x80, 0x40, 0x20, 0x00, 0x00,
    0x07, 0x00, 0x01, 0x02, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_108[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x04, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x07, 0x04, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_109[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x20, 0xC0, 0x20, 0xC0, 0x00,
    0x07, 0x00, 0x03, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_110[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x40, 0x20, 0x20, 0xC0, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_111[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0x20, 0x20, 0x20, 0xC0, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_112[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x20, 0x20, 0x20, 0xC0, 0x00,
    0x1F, 0x02, 0x02, 0x02, 0x01, 0x00,
};
const uint8_t Fontx6x13_char_113[] = {
    0x06, 0x0D, // width=6, height=13
    0xC0, 0x20, 0x20, 0x20, 0xE0, 0x00,
    0x01, 0x02, 0x02, 0x02, 0x1F, 0x00,
};
const uint8_t Fontx6x13_char_114[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x40, 0x20, 0x20, 0x40, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_115[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0xA0, 0xA0, 0x20, 0x40, 0x00,
    0x02, 0x04, 0x04, 0x05, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_116[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0xF8, 0x20, 0x20, 0x00, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x02, 0x00,
};
const uint8_t Fontx6x13_char_117[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00,
    0x03, 0x04, 0x04, 0x02, 0x07, 0x00,
};
const uint8_t Fontx6x13_char_118[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00,
    0x00, 0x03, 0x04, 0x03, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_119[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x00, 0x80, 0x00, 0xE0, 0x00,
    0x03, 0x04, 0x03, 0x04, 0x03, 0x00,
};
const uint8_t Fontx6x13_char_120[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0x40, 0x80, 0x40, 0x20, 0x00,
    0x04, 0x02, 0x01, 0x02, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_121[] = {
    0x06, 0x0D, // width=6, height=13
    0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00,
    0x09, 0x12, 0x12, 0x11, 0x0F, 0x00,
};
const uint8_t Fontx6x13_char_122[] = {
    0x06, 0x0D, // width=6, height=13
    0x20, 0x20, 0xA0, 0x60, 0x20, 0x00,
    0x06, 0x05, 0x04, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_123[] = {
    0x06, 0x0D, // width=6, height=13
    0x40, 0x40, 0xB8, 0x04, 0x04, 0x00,
    0x00, 0x00, 0x03, 0x04, 0x04, 0x00,
};
const uint8_t Fontx6x13_char_124[] = {
    0x06, 0x0D, // width=6, height=13
    0x00, 0x00, 0xFC, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_125[] = {
    0x06, 0x0D, // width=6, height=13
    0x04, 0x04, 0xB8, 0x40, 0x40, 0x00,
    0x04, 0x04, 0x03, 0x00, 0x00, 0x00,
};
const uint8_t Fontx6x13_char_126[] = {
    0x06, 0x0D, // width=6, height=13
    0x18, 0x04, 0x08, 0x10, 0x0C, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// const uint8_t Fontx6x13_char_127[] = {};
// const uint8_t Fontx6x13_char_128[] = {};
// const uint8_t Fontx6x13_char_129[] = {};
// const uint8_t Fontx6x13_char_130[] = {};
// const uint8_t Fontx6x13_char_131[] = {};
// const uint8_t Fontx6x13_char_132[] = {};
// const uint8_t Fontx6x13_char_133[] = {};
// const uint8_t Fontx6x13_char_134[] = {};
// const uint8_t Fontx6x13_char_135[] = {};
// const uint8_t Fontx6x13_char_136[] = {};
// const uint8_t Fontx6x13_char_137[] = {};
// const uint8_t Fontx6x13_char_138[] = {};
// const uint8_t Fontx6x13_char_139[] = {};
// const uint8_t Fontx6x13_char_140[] = {};
// const uint8_t Fontx6x13_char_141[] = {};
// const uint8_t Fontx6x13_char_142[] = {};
// const uint8_t Fontx6x13_char_143[] = {};
// const uint8_t Fontx6x13_char_144[] = {};
// const uint8_t Fontx6x13_char_145[] = {};
// const uint8_t Fontx6x13_char_146[] = {};
// const uint8_t Fontx6x13_char_147[] = {};
// const uint8_t Fontx6x13_char_148[] = {};
// const uint8_t Fontx6x13_char_149[] = {};
// const uint8_t Fontx6x13_char_150[] = {};
// const uint8_t Fontx6x13_char_151[] = {};
// const uint8_t Fontx6x13_char_152[] = {};
// const uint8_t Fontx6x13_char_153[] = {};
// const uint8_t Fontx6x13_char_154[] = {};
// const uint8_t Fontx6x13_char_155[] = {};
// const uint8_t Fontx6x13_char_156[] = {};
// const uint8_t Fontx6x13_char_157[] = {};
// const uint8_t Fontx6x13_char_158[] = {};
// const uint8_t Fontx6x13_char_159[] = {};
// const uint8_t Fontx6x13_char_160[] = {};
// const uint8_t Fontx6x13_char_161[] = {};
// const uint8_t Fontx6x13_char_162[] = {};
// const uint8_t Fontx6x13_char_163[] = {};
// const uint8_t Fontx6x13_char_164[] = {};
// const uint8_t Fontx6x13_char_165[] = {};
// const uint8_t Fontx6x13_char_166[] = {};
// const uint8_t Fontx6x13_char_167[] = {};
// const uint8_t Fontx6x13_char_168[] = {};
// const uint8_t Fontx6x13_char_169[] = {};
// const uint8_t Fontx6x13_char_170[] = {};
// const uint8_t Fontx6x13_char_171[] = {};
// const uint8_t Fontx6x13_char_172[] = {};
// const uint8_t Fontx6x13_char_173[] = {};
// const uint8_t Fontx6x13_char_174[] = {};
// const uint8_t Fontx6x13_char_175[] = {};
// const uint8_t Fontx6x13_char_176[] = {};
// const uint8_t Fontx6x13_char_177[] = {};
// const uint8_t Fontx6x13_char_178[] = {};
// const uint8_t Fontx6x13_char_179[] = {};
// const uint8_t Fontx6x13_char_180[] = {};
// const uint8_t Fontx6x13_char_181[] = {};
// const uint8_t Fontx6x13_char_182[] = {};
// const uint8_t Fontx6x13_char_183[] = {};
// const uint8_t Fontx6x13_char_184[] = {};
// const uint8_t Fontx6x13_char_185[] = {};
// const uint8_t Fontx6x13_char_186[] = {};
// const uint8_t Fontx6x13_char_187[] = {};
// const uint8_t Fontx6x13_char_188[] = {};
// const uint8_t Fontx6x13_char_189[] = {};
// const uint8_t Fontx6x13_char_190[] = {};
// const uint8_t Fontx6x13_char_191[] = {};
// const uint8_t Fontx6x13_char_192[] = {};
// const uint8_t Fontx6x13_char_193[] = {};
// const uint8_t Fontx6x13_char_194[] = {};
// const uint8_t Fontx6x13_char_195[] = {};
// const uint8_t Fontx6x13_char_196[] = {};
// const uint8_t Fontx6x13_char_197[] = {};
// const uint8_t Fontx6x13_char_198[] = {};
// const uint8_t Fontx6x13_char_199[] = {};
// const uint8_t Fontx6x13_char_200[] = {};
// const uint8_t Fontx6x13_char_201[] = {};
// const uint8_t Fontx6x13_char_202[] = {};
// const uint8_t Fontx6x13_char_203[] = {};
// const uint8_t Fontx6x13_char_204[] = {};
// const uint8_t Fontx6x13_char_205[] = {};
// const uint8_t Fontx6x13_char_206[] = {};
// const uint8_t Fontx6x13_char_207[] = {};
// const uint8_t Fontx6x13_char_208[] = {};
// const uint8_t Fontx6x13_char_209[] = {};
// const uint8_t Fontx6x13_char_210[] = {};
// const uint8_t Fontx6x13_char_211[] = {};
// const uint8_t Fontx6x13_char_212[] = {};
// const uint8_t Fontx6x13_char_213[] = {};
// const uint8_t Fontx6x13_char_214[] = {};
// const uint8_t Fontx6x13_char_215[] = {};
// const uint8_t Fontx6x13_char_216[] = {};
// const uint8_t Fontx6x13_char_217[] = {};
// const uint8_t Fontx6x13_char_218[] = {};
// const uint8_t Fontx6x13_char_219[] = {};
// const uint8_t Fontx6x13_char_220[] = {};
// const uint8_t Fontx6x13_char_221[] = {};
// const uint8_t Fontx6x13_char_222[] = {};
// const uint8_t Fontx6x13_char_223[] = {};
// const uint8_t Fontx6x13_char_224[] = {};
// const uint8_t Fontx6x13_char_225[] = {};
// const uint8_t Fontx6x13_char_226[] = {};
// const uint8_t Fontx6x13_char_227[] = {};
// const uint8_t Fontx6x13_char_228[] = {};
// const uint8_t Fontx6x13_char_229[] = {};
// const uint8_t Fontx6x13_char_230[] = {};
// const uint8_t Fontx6x13_char_231[] = {};
// const uint8_t Fontx6x13_char_232[] = {};
// const uint8_t Fontx6x13_char_233[] = {};
// const uint8_t Fontx6x13_char_234[] = {};
// const uint8_t Fontx6x13_char_235[] = {};
// const uint8_t Fontx6x13_char_236[] = {};
// const uint8_t Fontx6x13_char_237[] = {};
// const uint8_t Fontx6x13_char_238[] = {};
// const uint8_t Fontx6x13_char_239[] = {};
// const uint8_t Fontx6x13_char_240[] = {};
// const uint8_t Fontx6x13_char_241[] = {};
// const uint8_t Fontx6x13_char_242[] = {};
// const uint8_t Fontx6x13_char_243[] = {};
// const uint8_t Fontx6x13_char_244[] = {};
// const uint8_t Fontx6x13_char_245[] = {};
// const uint8_t Fontx6x13_char_246[] = {};
// const uint8_t Fontx6x13_char_247[] = {};
// const uint8_t Fontx6x13_char_248[] = {};
// const uint8_t Fontx6x13_char_249[] = {};
// const uint8_t Fontx6x13_char_250[] = {};
// const uint8_t Fontx6x13_char_251[] = {};
// const uint8_t Fontx6x13_char_252[] = {};
// const uint8_t Fontx6x13_char_253[] = {};
// const uint8_t Fontx6x13_char_254[] = {};
// const uint8_t Fontx6x13_char_255[] = {};

const unsigned char *Fontx6x13_table[256] = {
    Fontx6x13_char_0,
    Fontx6x13_char_1,
    Fontx6x13_char_2,
    Fontx6x13_char_3,
    Fontx6x13_char_4,
    Fontx6x13_char_5,
    Fontx6x13_char_6,
    Fontx6x13_char_7,
    Fontx6x13_char_8,
    Fontx6x13_char_9,
    Fontx6x13_char_10,
    Fontx6x13_char_11,
    Fontx6x13_char_12,
    Fontx6x13_char_13,
    Fontx6x13_char_14,
    Fontx6x13_char_15,
    Fontx6x13_char_16,
    Fontx6x13_char_17,
    Fontx6x13_char_18,
    Fontx6x13_char_19,
    Fontx6x13_char_20,
    Fontx6x13_char_21,
    Fontx6x13_char_22,
    Fontx6x13_char_23,
    Fontx6x13_char_24,
    Fontx6x13_char_25,
    Fontx6x13_char_26,
    Fontx6x13_char_27,
    Fontx6x13_char_28,
    Fontx6x13_char_29,
    Fontx6x13_char_30,
    Fontx6x13_char_31,
    Fontx6x13_char_32,
    Fontx6x13_char_33,
    Fontx6x13_char_34,
    Fontx6x13_char_35,
    Fontx6x13_char_36,
    Fontx6x13_char_37,
    Fontx6x13_char_38,
    Fontx6x13_char_39,
    Fontx6x13_char_40,
    Fontx6x13_char_41,
    Fontx6x13_char_42,
    Fontx6x13_char_43,
    Fontx6x13_char_44,
    Fontx6x13_char_45,
    Fontx6x13_char_46,
    Fontx6x13_char_47,
    Fontx6x13_char_48,
    Fontx6x13_char_49,
    Fontx6x13_char_50,
    Fontx6x13_char_51,
    Fontx6x13_char_52,
    Fontx6x13_char_53,
    Fontx6x13_char_54,
    Fontx6x13_char_55,
    Fontx6x13_char_56,
    Fontx6x13_char_57,
    Fontx6x13_char_58,
    Fontx6x13_char_59,
    Fontx6x13_char_60,
    Fontx6x13_char_61,
    Fontx6x13_char_62,
    Fontx6x13_char_63,
    Fontx6x13_char_64,
    Fontx6x13_char_65,
    Fontx6x13_char_66,
    Fontx6x13_char_67,
    Fontx6x13_char_68,
    Fontx6x13_char_69,
    Fontx6x13_char_70,
    Fontx6x13_char_71,
    Fontx6x13_char_72,
    Fontx6x13_char_73,
    Fontx6x13_char_74,
    Fontx6x13_char_75,
    Fontx6x13_char_76,
    Fontx6x13_char_77,
    Fontx6x13_char_78,
    Fontx6x13_char_79,
    Fontx6x13_char_80,
    Fontx6x13_char_81,
    Fontx6x13_char_82,
    Fontx6x13_char_83,
    Fontx6x13_char_84,
    Fontx6x13_char_85,
    Fontx6x13_char_86,
    Fontx6x13_char_87,
    Fontx6x13_char_88,
    Fontx6x13_char_89,
    Fontx6x13_char_90,
    Fontx6x13_char_91,
    Fontx6x13_char_92,
    Fontx6x13_char_93,
    Fontx6x13_char_94,
    Fontx6x13_char_95,
    Fontx6x13_char_96,
    Fontx6x13_char_97,
    Fontx6x13_char_98,
    Fontx6x13_char_99,
    Fontx6x13_char_100,
    Fontx6x13_char_101,
    Fontx6x13_char_102,
    Fontx6x13_char_103,
    Fontx6x13_char_104,
    Fontx6x13_char_105,
    Fontx6x13_char_106,
    Fontx6x13_char_107,
    Fontx6x13_char_108,
    Fontx6x13_char_109,
    Fontx6x13_char_110,
    Fontx6x13_char_111,
    Fontx6x13_char_112,
    Fontx6x13_char_113,
    Fontx6x13_char_114,
    Fontx6x13_char_115,
    Fontx6x13_char_116,
    Fontx6x13_char_117,
    Fontx6x13_char_118,
    Fontx6x13_char_119,
    Fontx6x13_char_120,
    Fontx6x13_char_121,
    Fontx6x13_char_122,
    Fontx6x13_char_123,
    Fontx6x13_char_124,
    Fontx6x13_char_125,
    Fontx6x13_char_126,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
