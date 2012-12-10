/*****************************************************************************
* Product:  QF/C, Renesas RX, Vanilla port, Renesas compiler
* Last Updated for Version: 4.5.02
* Date of the Last Update:  Oct 17, 2012
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 2 of the License, or
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
* Quantum Leaps Web sites: http://www.quantum-leaps.com
*                          http://www.state-machine.com
* e-mail:                  info@quantum-leaps.com
*****************************************************************************/
#ifndef qf_port_h
#define qf_port_h

     /* The maximum number of active objects in the application, see NOTE01 */
#define QF_MAX_ACTIVE               32
                    /* The maximum number of event pools in the application */
#define QF_MAX_EPOOL                6
                                         /* QF interrupt disabling/enabling */
#define QF_INT_DISABLE()            clrpsw_i()
#define QF_INT_ENABLE()             setpsw_i()

                                          /* QF critical section entry/exit */
/* QF_CRIT_STAT_TYPE not defined: unconditional interrupt unlocking, NOTE02 */
#define QF_CRIT_ENTRY(dummy)        QF_INT_DISABLE()
#define QF_CRIT_EXIT(dummy)         QF_INT_ENABLE()

                                      /* QF ISR entry/exit, also see NOTE01 */
#define QF_ISR_ENTRY()              QF_INT_ENABLE()
#define QF_ISR_EXIT()               QF_INT_ENABLE()

                                                      /* inline definitions */
#pragma inline_asm clrpsw_i
static void clrpsw_i(void) { CLRPSW I }

#pragma inline_asm setpsw_i
static void setpsw_i(void) { SETPSW I }

#include "qep_port.h"                                           /* QEP port */
#include "qvanilla.h"                       /* "Vanilla" cooperative kernel */
#include "qf.h"                 /* QF platform-independent public interface */

/*****************************************************************************
* NOTE01:
* The maximum number of active objects QF_MAX_ACTIVE can be increased
* up to 63, if necessary. Here it is set to a lower level to save some RAM.
*
* NOTE02:
* This policy does not allow to nest critical sections. Therefore interrupts
* must be enabled in ISRs before calling any QP service. This should be no
* problem, because if interrupts nesting is not desired, the interrupts can
* always be prioritized at the same IPL.
*/

#endif                                                         /* qf_port_h */
