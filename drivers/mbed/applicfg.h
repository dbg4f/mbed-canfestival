/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): Edouard TISSERANT and Francis DUPIN
AVR Port: Andreas GLAUSER and Peter CHRISTEN
mbed port: sgrove

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __APPLICFG__
#define __APPLICFG__

#include <string.h>
#include <stdio.h>
#include <stdint.h>

// Integers
#define INTEGER8    signed char
#define INTEGER16   signed short int
#define INTEGER24
#define INTEGER32   signed int
#define INTEGER40
#define INTEGER48
#define INTEGER56
#define INTEGER64   signed __int64

// Unsigned integers
#define UNS8        unsigned char
#define UNS16       unsigned short int
#define UNS32         unsigned int
/*
#define UNS24
#define UNS40
#define UNS48
#define UNS56
#define UNS64
*/ 


// Reals
#define REAL32      float
#define REAL64        double



#define DEBUG_MSG_CONSOLE_ON


#include "canopen_can.h"

// MSG functions
// not finished, the strings have to be placed to the flash and printed out 
// using the printf_P function
/// Definition of MSG_ERR
// ---------------------
//#ifdef DEBUG_ERR_CONSOLE_ON
#define MSG_ERR(num, str, val)    \
    printf("%04x %s %d\n", num, str, val);

/*

\
          printf(num, ' ');       \
          printf(str);           \
          printf(val);           \
          printf('\n');
*/
//#else
//#    define MSG_ERR(num, str, val)
//#endif

/// Definition of MSG_WAR
// ---------------------
//#ifdef DEBUG_WAR_CONSOLE_ON
#define MSG_WAR(num, str, val)    \
    printf("%04x %s %d\n", num, str, val);


/*
\
          printf("%04x ", num);        \
          printf(str);            \
          printf("%d", val);            \
          printf('\n');
          */
//#else
//#    define MSG_WAR(num, str, val)
//#endif


#define MSG2(format, text) printf(format, text)



#define MSG(text)  printf(text)




typedef void* CAN_HANDLE;

typedef void* CAN_PORT;

#define CAN_BAUDRATE    1000000

// Needed defines by Canfestival lib
#define MAX_CAN_BUS_ID 1
#define SDO_MAX_LENGTH_TRANSFER 32
#define SDO_MAX_SIMULTANEOUS_TRANSFERS 1
#define SDO_BLOCK_SIZE 128
#define NMT_MAX_NODE_ID 128
#define SDO_TIMEOUT_MS 3000U
#define MAX_NB_TIMER 8

// CANOPEN_BIG_ENDIAN is not defined
#define CANOPEN_LITTLE_ENDIAN 1

#define REPEAT_SDO_MAX_SIMULTANEOUS_TRANSFERS_TIMES(repeat)\
repeat
#define REPEAT_NMT_MAX_NODE_ID_TIMES(repeat)\
repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat repeat

#define EMCY_MAX_ERRORS 8
#define REPEAT_EMCY_MAX_ERRORS_TIMES(repeat)\
repeat repeat repeat repeat repeat repeat repeat repeat

#endif


