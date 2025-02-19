/*-*- mode:c;indent-tabs-mode:t;c-basic-offset:8;tab-width:8;coding:utf-8   -*-│
│vi: set et ft=c ts=8 tw=8 fenc=utf-8                                       :vi│
╚──────────────────────────────────────────────────────────────────────────────╝
│                                                                              │
│  Musl Libc                                                                   │
│  Copyright © 2005-2014 Rich Felker, et al.                                   │
│                                                                              │
│  Permission is hereby granted, free of charge, to any person obtaining       │
│  a copy of this software and associated documentation files (the             │
│  "Software"), to deal in the Software without restriction, including         │
│  without limitation the rights to use, copy, modify, merge, publish,         │
│  distribute, sublicense, and/or sell copies of the Software, and to          │
│  permit persons to whom the Software is furnished to do so, subject to       │
│  the following conditions:                                                   │
│                                                                              │
│  The above copyright notice and this permission notice shall be              │
│  included in all copies or substantial portions of the Software.             │
│                                                                              │
│  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,             │
│  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF          │
│  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.      │
│  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY        │
│  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,        │
│  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE           │
│  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                      │
│                                                                              │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/math.h"
#include "libc/tinymath/expo.internal.h"
#include "libc/tinymath/ldshape.internal.h"

asm(".ident\t\"\\n\\n\
Musl libc (MIT License)\\n\
Copyright 2005-2014 Rich Felker, et. al.\"");
asm(".include \"libc/disclaimer.inc\"");
/* clang-format off */

/**
 * Returns hyperbolic sine of 𝑥.
 *
 *     sinh(x) = (exp(x) - 1/exp(x))/2
 *             = (exp(x)-1 + (exp(x)-1)/exp(x))/2
 *             = x + x^3/6 + o(x^5)
 */
long double sinhl(long double x) {
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
	return sinh(x);
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
	union ldshape u = {x};
	unsigned ex = u.i.se & 0x7fff;
	long double h, t, absx;

	h = 0.5;
	if (u.i.se & 0x8000)
		h = -h;
	/* |x| */
	u.i.se = ex;
	absx = u.f;

	/* |x| < log(LDBL_MAX) */
	if (ex < 0x3fff+13 || (ex == 0x3fff+13 && u.i.m>>32 < 0xb17217f7)) {
		t = expm1l(absx);
		if (ex < 0x3fff) {
			if (ex < 0x3fff-32)
				return x;
			return h*(2*t - t*t/(1+t));
		}
		return h*(t + t/(t+1));
	}

	/* |x| > log(LDBL_MAX) or nan */
	t = expl(0.5*absx);
	return h*t*t;
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
// TODO: broken implementation to make things compile
	return sinh(x);
#else
#error "architecture unsupported"
#endif
}
