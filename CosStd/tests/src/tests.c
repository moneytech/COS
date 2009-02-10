/*
 o---------------------------------------------------------------------o
 |
 | COS testsuites - tests suite
 |
 o---------------------------------------------------------------------o
 |
 | C Object System
 |
 | Copyright (c) 2006+ Laurent Deniau, laurent.deniau@cern.ch
 |
 | For more information, see:
 | http://cern.ch/laurent.deniau/cos.html
 |
 o---------------------------------------------------------------------o
 |
 | This file is part of the C Object System framework.
 |
 | The C Object System is free software; you can redistribute it and/or
 | modify it under the terms of the GNU Lesser General Public License
 | as published by the Free Software Foundation; either version 3 of
 | the License, or (at your option) any later version.
 |
 | The C Object System is distributed in the hope that it will be
 | useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 | of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 |
 | See <http://www.gnu.org/licenses> for more details.
 |
 o---------------------------------------------------------------------o
 |
 | $Id: tests.c,v 1.5 2009/02/10 13:03:22 ldeniau Exp $
 |
*/

#include <cos/Object.h>
#include <cos/debug.h>
#include <cos/signal.h>
#include <cos/gen/object.h>
#include <cos/utest.h>

#include "tests.h"

#include <string.h>
#include <stdlib.h>

static void
on_exit(void)
{
  printf("\n** COS deinit duration: %.3f s\n", cos_deinitDuration());
}

int main(int argc, char *argv[])
{
  enum { bits = CHAR_BIT*sizeof(void*) };
  int init_time = NO;
  int speed_test = NO;
  int i;

  cos_logmsg_set(COS_LOGMSG_DEBUG);

  for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-i"))
      init_time = YES;
    if (!strcmp(argv[i], "-s"))
      speed_test = YES;
    if (!strcmp(argv[i], "-t"))
      cos_logmsg_set(COS_LOGMSG_TRACE);
  }

  if (init_time) {
    // must be loaded before first message is sent
    atexit(on_exit);
    cos_init(); // explicit initialization for measurement
    printf("** COS init duration: %.3f s\n", cos_initDuration());
  }
   
  // convert signal to exception
  cos_signal_std();

  // testsuites
  printf("\n** C Object System Testsuite (%d bits) **\n", bits);
  // ut_autoconst();
  // ut_autovector();

  cos_utest_stat();

  // speed testsuites
  if (!speed_test) return EXIT_SUCCESS;
  
  printf("\n** C Object System Speed Testsuite (%d bits) **\n", bits);

  cos_stest_stat();

  return EXIT_SUCCESS;
}
