//===-- ucmpti2.c - Implement __ucmpti2 -----------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements __ucmpti2 for the compiler_rt library.
//
//===----------------------------------------------------------------------===//

#if __x86_64

#include "int_lib.h"

// Returns:  if (a <  b) returns 0
//           if (a == b) returns 1
//           if (a >  b) returns 2

si_int
__ucmpti2(tu_int a, tu_int b)
{
    utwords x;
    x.all = a;
    utwords y;
    y.all = b;
    if (x.high < y.high)
        return 0;
    if (x.high > y.high)
        return 2;
    if (x.low < y.low)
        return 0;
    if (x.low > y.low)
        return 2;
    return 1;
}

#endif