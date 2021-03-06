/*
 * Real Time Clock (MK48T08) for RTEMS on PPCn_60x
 *
 *  Based on MVME162 TOD by:
 *    COPYRIGHT (C) 1997
 *    by Katsutoshi Shibuya - BU Denken Co.,Ltd. - Sapporo - JAPAN
 *    ALL RIGHTS RESERVED
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id: tod.h,v 1.2 2001-09-27 12:00:50 chris Exp $
 */


#ifndef TOD_H
#define TOD_H

#ifdef __cplusplus
extern "C" {
#endif

extern void setRealTimeToRTEMS();
/* Read real time from RTC and set it to RTEMS' clock manager */

extern void setRealTimeFromRTEMS();
/* Read time from RTEMS' clock manager and set it to RTC */

extern int checkRealTime();
/* Return the difference between RTC and RTEMS' clock manager time in minutes.
   If the difference is greater than 1 day, this returns 9999. */

#ifdef __cplusplus
}
#endif

#endif
