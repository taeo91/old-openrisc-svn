/*
 *  16.1.1 Thread Creation Attributes, P1003.1c/Draft 10, p, 140
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.OARcorp.com/rtems/license.html.
 *
 *  $Id: pthreadattrsetstacksize.c,v 1.2 2001-09-27 11:59:17 chris Exp $
 */

#include <pthread.h>
#include <errno.h>

#include <rtems/system.h>
#include <rtems/posix/pthread.h>

int pthread_attr_setstacksize(
  pthread_attr_t  *attr,
  size_t           stacksize
)
{
  if ( !attr || !attr->is_initialized )
    return EINVAL;

  if (stacksize < PTHREAD_MINIMUM_STACK_SIZE)
    attr->stacksize = PTHREAD_MINIMUM_STACK_SIZE;
  else
    attr->stacksize = stacksize;
  return 0;
}
