#pragma once

#include "FilterCommon.h"
#include "Interpolate.h"

typedef int sPixel;
typedef unsigned char byte;

#pragma region standard HQ2x casepath
void Hq2xKernel(byte pattern, sPixel c0, sPixel c1, sPixel c2, sPixel c3, sPixel c4, sPixel c5, sPixel c6, sPixel c7, sPixel c8, int* Pixel) {
	
	sPixel e01, e10, e11;
	
	auto  e00 = e01 = e10 = e11 = c4;
	
	switch (pattern) {
		#pragma region HQ2x PATTERNS

	case 0:
	case 1:
	case 4:
	case 5:
	case 32:
	case 33:
	case 36:
	case 37:
	case 128:
	case 129:
	case 132:
	case 133:
	case 160:
	case 161:
	case 164:
	case 165: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 2:
	case 34:
	case 130:
	case 162: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 3:
	case 35:
	case 131:
	case 163: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 6:
	case 38:
	case 134:
	case 166: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 7:
	case 39:
	case 135:
	case 167: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 8:
	case 12:
	case 136:
	case 140: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 9:
	case 13:
	case 137:
	case 141: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 10:
	case 138: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = IsNotLike(c1, c3) ? Interpolate(c4, c0, 3, 1) : Interpolate(c4, c1, c3, 2, 1, 1);
	}
			  break;
	case 11:
	case 139: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = IsNotLike(c1, c3) ? c4 : Interpolate(c4, c1, c3, 2, 1, 1);
	}
			  break;
	case 14:
	case 142: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 3, 1);
			e01 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
		}
	}
			  break;
	case 15:
	case 143: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
		}
	}
			  break;
	case 16:
	case 17:
	case 48:
	case 49: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 18:
	case 50: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e01 = IsNotLike(c1, c5) ? Interpolate(c4, c2, 3, 1) : Interpolate(c4, c1, c5, 2, 1, 1);
	}
			 break;
	case 19:
	case 51: {
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
		}
	}
			 break;
	case 20:
	case 21:
	case 52:
	case 53: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 22:
	case 54: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e01 = IsNotLike(c1, c5) ? c4 : Interpolate(c4, c1, c5, 2, 1, 1);
	}
			 break;
	case 23:
	case 55: {
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
		}
	}
			 break;
	case 24: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 25: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 26:
	case 31: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e00 = IsNotLike(c1, c3) ? c4 : Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = IsNotLike(c1, c5) ? c4 : Interpolate(c4, c1, c5, 2, 1, 1);
	}
			 break;
	case 27: {
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e00 = IsNotLike(c1, c3) ? c4 : Interpolate(c4, c1, c3, 2, 1, 1);
	}
			 break;
	case 28: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 29: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 30: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e01 = IsNotLike(c1, c5) ? c4 : Interpolate(c4, c1, c5, 2, 1, 1);
	}
			 break;
	case 40:
	case 44:
	case 168:
	case 172: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 41:
	case 45:
	case 169:
	case 173: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 42:
	case 170: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e10 = Interpolate(c4, c3, c7, 5, 2, 1);
		}
	}
			  break;
	case 43:
	case 171: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e10 = Interpolate(c4, c3, c7, 5, 2, 1);
		}
	}
			  break;
	case 46:
	case 174: {
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = IsNotLike(c1, c3) ? Interpolate(c4, c0, 3, 1) : Interpolate(c4, c1, c3, 6, 1, 1);
	}
			  break;
	case 47:
	case 175: {
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
	}
			  break;
	case 56: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 57: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 58: {
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			 break;
	case 59: {
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			 break;
	case 60: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 61: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
	}
			 break;
	case 62: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 63: {
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, c8, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 64:
	case 65:
	case 68:
	case 69: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 66: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 67: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 70: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 71: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 72:
	case 76: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			 break;
	case 73:
	case 77: {
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c3, c1, 5, 2, 1);
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
		}
	}
			 break;
	case 74:
	case 107: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 75: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			 break;
	case 78: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			 break;
	case 79: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			 break;
	case 80:
	case 81: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			 break;
	case 82:
	case 214: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 83: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			 break;
	case 84:
	case 85: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = Interpolate(c4, c8, 3, 1);
		}
		else {
			e01 = Interpolate(c4, c5, c1, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			 break;
	case 86: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 87: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 88:
	case 248: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 89: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			 break;
	case 90: {
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			 break;
	case 91: {
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			 break;
	case 92: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			 break;
	case 93: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			 break;
	case 94: {
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 95: {
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 96:
	case 97:
	case 100:
	case 101: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			  break;
	case 98: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 99: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			 break;
	case 102: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			  break;
	case 103: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
	}
			  break;
	case 104:
	case 108: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 105:
	case 109: {
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c3, c1, 5, 2, 1);
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 106: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 110: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 111: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, c8, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
	}
			  break;
	case 112:
	case 113: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		if (IsNotLike(c7, c5)) {
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = Interpolate(c4, c8, 3, 1);
		}
		else {
			e10 = Interpolate(c4, c7, c3, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 114: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 115: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 116:
	case 117: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			  break;
	case 118: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 119: {
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
		}
	}
			  break;
	case 120: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 121: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			  break;
	case 122: {
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 123: {
		e01 = Interpolate(c4, c2, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 124: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 125: {
		e01 = Interpolate(c4, c1, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c3, c1, 5, 2, 1);
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 126: {
		e00 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c8, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 127: {
		e11 = Interpolate(c4, c8, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 144:
	case 145:
	case 176:
	case 177: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 146:
	case 178: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 3, 1);
			e11 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
			e11 = Interpolate(c4, c5, c7, 5, 2, 1);
		}
	}
			  break;
	case 147:
	case 179: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 148:
	case 149:
	case 180:
	case 181: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 150:
	case 182: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
			e11 = Interpolate(c4, c5, c7, 5, 2, 1);
		}
	}
			  break;
	case 151:
	case 183: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 152: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 153: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 154: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 155: {
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 156: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 157: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 158: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 159: {
		e10 = Interpolate(c4, c6, c7, 2, 1, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 184: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 185: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 186: {
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 187: {
		e01 = Interpolate(c4, c2, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e10 = Interpolate(c4, c3, c7, 5, 2, 1);
		}
	}
			  break;
	case 188: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 189: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 190: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 3, 3, 2);
			e11 = Interpolate(c4, c5, c7, 5, 2, 1);
		}
	}
			  break;
	case 191: {
		e10 = Interpolate(c4, c7, 3, 1);
		e11 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 192:
	case 193:
	case 196:
	case 197: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 194: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 195: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 198: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 199: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 200:
	case 204: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		if (IsNotLike(c7, c3)) {
			e10 = Interpolate(c4, c6, 3, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
			e11 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			  break;
	case 201:
	case 205: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
	}
			  break;
	case 202: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 203: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 206: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 207: {
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 3, 3, 2);
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
		}
	}
			  break;
	case 208:
	case 209: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 210: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 211: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 212:
	case 213: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c5, c1, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 215: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, c6, 2, 1, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 216: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 217: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 218: {
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 219: {
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 220: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 221: {
		e00 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c5, c1, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 222: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 223: {
		e10 = Interpolate(c4, c6, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 224:
	case 225:
	case 228:
	case 229: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 226: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 227: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 230: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 231: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 232:
	case 236: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e11 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
			e11 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			  break;
	case 233:
	case 237: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
	}
			  break;
	case 234: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 235: {
		e01 = Interpolate(c4, c2, c5, 2, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 238: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e11 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c3, c7, c4, 3, 3, 2);
			e11 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			  break;
	case 239: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
	}
			  break;
	case 240:
	case 241: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		if (IsNotLike(c7, c5)) {
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		else {
			e10 = Interpolate(c4, c7, c3, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 242: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 243: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 3, 1);
		if (IsNotLike(c7, c5)) {
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		else {
			e10 = Interpolate(c4, c7, c3, 5, 2, 1);
			e11 = Interpolate(c5, c7, c4, 3, 3, 2);
		}
	}
			  break;
	case 244:
	case 245: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
	}
			  break;
	case 246: {
		e00 = Interpolate(c4, c0, c3, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 247: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
	case 249: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c2, 2, 1, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 250: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 251: {
		e01 = Interpolate(c4, c2, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 252: {
		e00 = Interpolate(c4, c0, c1, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
	}
			  break;
	case 253: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
	}
			  break;
	case 254: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 255: {
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 14, 1, 1));
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 14, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 14, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 14, 1, 1));
	}
			  break;
			  #pragma endregion
	}

	Pixel[1] = e00;
	Pixel[2] = e01;
	Pixel[3] = e10;
	Pixel[4] = e11;
}
#pragma endregion

#pragma region standard HQ2x3 casepath
void Hq2x3Kernel(byte pattern, sPixel c0, sPixel c1, sPixel c2, sPixel c3, sPixel c4, sPixel c5, sPixel c6, sPixel c7, sPixel c8, int* Pixel) {
	sPixel e01, e10, e11, e20, e21;
	auto e00 = e01 = e10 = e11 = e20 = e21 = c4;
	switch (pattern) {
		#pragma region HQ2x3 PATTERNS

	case 0:
	case 1:
	case 4:
	case 5:
	case 32:
	case 33:
	case 36:
	case 37:
	case 128:
	case 129:
	case 132:
	case 133:
	case 160:
	case 161:
	case 164:
	case 165: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 2:
	case 34:
	case 130:
	case 162: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 3:
	case 35:
	case 131:
	case 163: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 6:
	case 38:
	case 134:
	case 166: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 7:
	case 39:
	case 135:
	case 167: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 8:
	case 12:
	case 136:
	case 140: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 9:
	case 13:
	case 137:
	case 141: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 10:
	case 138: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			  break;
	case 11:
	case 139: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			  break;
	case 14:
	case 142: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = Interpolate(c4, c5, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 10, 5, 1);
			e01 = Interpolate(c4, c1, c5, 7, 6, 3);
			e10 = Interpolate(c4, c3, 13, 3);
		}
	}
			  break;
	case 15:
	case 143: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 10, 5, 1);
			e01 = Interpolate(c4, c1, c5, 7, 6, 3);
			e10 = Interpolate(c4, c3, 13, 3);
		}
	}
			  break;
	case 16:
	case 17:
	case 48:
	case 49: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 18:
	case 50: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = Interpolate(c4, c2, 13, 3);
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 19:
	case 51: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 13, 3);
			e01 = Interpolate(c4, c2, 13, 3);
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 7, 6, 3);
			e01 = Interpolate(c1, c5, c4, 10, 5, 1);
			e11 = Interpolate(c4, c5, 13, 3);
		}
	}
			 break;
	case 20:
	case 21:
	case 52:
	case 53: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 22:
	case 54: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 23:
	case 55: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 7, 6, 3);
			e01 = Interpolate(c1, c5, c4, 10, 5, 1);
			e11 = Interpolate(c4, c5, 13, 3);
		}
	}
			 break;
	case 24: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 25: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 26:
	case 31: {
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e10 = Interpolate(c4, c3, 15, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 27: {
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			 break;
	case 28: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 29: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 30: {
		e10 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 40:
	case 44:
	case 168:
	case 172: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 41:
	case 45:
	case 169:
	case 173: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 42:
	case 170: {
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 5, 4);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		}
	}
			  break;
	case 43:
	case 171: {
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 5, 4);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		}
	}
			  break;
	case 46:
	case 174: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 47:
	case 175: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 56: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 57: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 58: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			 break;
	case 59: {
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsLike(c1, c5)) {
			e01 = Interpolate(c4, c1, c5, 10, 3, 3);
		}
		if ((IsNotLike(c1, c5) && IsLike(c1, c3))) {
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e01 = Interpolate(c4, c2, 13, 3);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			 break;
	case 60: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 61: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
	}
			 break;
	case 62: {
		e10 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 63: {
		e10 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 64:
	case 65:
	case 68:
	case 69: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 66: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 67: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 70: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 71: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 72:
	case 76: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			 break;
	case 73:
	case 77: {
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 9, 4, 3);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c7, c3, c4, 7, 5, 4);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			 break;
	case 74:
	case 107: {
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
	}
			  break;
	case 75: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			 break;
	case 78: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			 break;
	case 79: {
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c5, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			 break;
	case 80:
	case 81: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			 break;
	case 82:
	case 214: {
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
		}
	}
			  break;
	case 83: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			 break;
	case 84:
	case 85: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 9, 4, 3);
			e11 = Interpolate(c4, c5, 1, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c7, c5, c4, 7, 5, 4);
		}
	}
			 break;
	case 86: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 87: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c3, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 88:
	case 248: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 89: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			 break;
	case 90: {
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			 break;
	case 91: {
		e11 = c4;
		if (IsLike(c1, c5)) {
			e01 = Interpolate(c4, c1, c5, 10, 3, 3);
		}
		if ((IsNotLike(c1, c5) && IsLike(c1, c3))) {
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e01 = Interpolate(c4, c2, 13, 3);
		}
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			 break;
	case 92: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			 break;
	case 93: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			 break;
	case 94: {
		e10 = c4;
		if (IsLike(c1, c3)) {
			e00 = Interpolate(c4, c1, c3, 10, 3, 3);
		}
		if ((IsLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = Interpolate(c4, c0, 13, 3);
		}
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 95: {
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e10 = Interpolate(c4, c3, 15, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			 break;
	case 96:
	case 97:
	case 100:
	case 101: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			  break;
	case 98: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 99: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			 break;
	case 102: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			  break;
	case 103: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
	}
			  break;
	case 104:
	case 108: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 105:
	case 109: {
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 9, 4, 3);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c7, c3, c4, 7, 5, 4);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 106: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 110: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 111: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 112:
	case 113: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c3, 13, 3);
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e11 = Interpolate(c4, c5, 13, 3);
			e20 = Interpolate(c7, c4, c3, 7, 6, 3);
			e21 = Interpolate(c7, c5, c4, 10, 5, 1);
		}
	}
			  break;
	case 114: {
		e00 = Interpolate(c4, c0, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 115: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 116:
	case 117: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 13, 3)) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			  break;
	case 118: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			  break;
	case 119: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 7, 6, 3);
			e01 = Interpolate(c1, c5, c4, 10, 5, 1);
			e11 = Interpolate(c4, c5, 13, 3);
		}
	}
			  break;
	case 120: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 121: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e11 = c4;
		if (IsLike(c7, c5)) {
			e21 = Interpolate(c4, c5, c7, 10, 3, 3);
		}
		if ((IsNotLike(c7, c5) && IsLike(c7, c3))) {
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e21 = Interpolate(c4, c8, 13, 3);
		}
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
	}
			  break;
	case 122: {
		e11 = c4;
		if (IsLike(c7, c5)) {
			e21 = Interpolate(c4, c5, c7, 10, 3, 3);
		}
		if ((IsNotLike(c7, c5) && IsLike(c7, c3))) {
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e21 = Interpolate(c4, c8, 13, 3);
		}
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 123: {
		e10 = c4;
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
	}
			  break;
	case 124: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 125: {
		e01 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 9, 4, 3);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c7, c3, c4, 7, 5, 4);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
	}
			  break;
	case 126: {
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			  break;
	case 127: {
		if (IsLike(c1, c5)) {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
		}
		if ((IsNotLike(c1, c5) && IsLike(c1, c3))) {
			e01 = Interpolate(c4, c1, 15, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e01 = c4;
		}
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = Interpolate(c4, c8, 13, 3);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c8, c7, 12, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 10, 3, 3);
			e10 = Interpolate(c4, c3, 15, 1);
		}
		e11 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c5, 15, 1));
	}
			  break;
	case 144:
	case 145:
	case 176:
	case 177: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 146:
	case 178: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = Interpolate(c4, c2, 13, 3);
			e11 = c4;
			e21 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c1, c5, c4, 7, 5, 4);
			e11 = Interpolate(c4, c5, 1, 1);
			e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		}
	}
			  break;
	case 147:
	case 179: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 148:
	case 149:
	case 180:
	case 181: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 150:
	case 182: {
		e10 = Interpolate(c4, c3, 13, 3);
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
			e21 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c1, c5, c4, 7, 5, 4);
			e11 = Interpolate(c4, c5, 1, 1);
			e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		}
	}
			  break;
	case 151:
	case 183: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		e21 = Interpolate(c4, c7, 3, 1);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 152: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 153: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 154: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 155: {
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			  break;
	case 156: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 157: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 158: {
		e10 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsLike(c1, c3)) {
			e00 = Interpolate(c4, c1, c3, 10, 3, 3);
		}
		if ((IsLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = Interpolate(c4, c0, 13, 3);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			  break;
	case 159: {
		e11 = c4;
		e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e10 = Interpolate(c4, c3, 15, 1);
		}
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 184: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 185: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 186: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 187: {
		e11 = c4;
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 5, 4);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c3, c4, 1, 1);
			e20 = Interpolate(c4, c7, c3, 9, 4, 3);
		}
	}
			  break;
	case 188: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 189: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 190: {
		e10 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
			e11 = c4;
			e21 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c1, c5, c4, 7, 5, 4);
			e11 = Interpolate(c4, c5, 1, 1);
			e21 = Interpolate(c4, c7, c5, 9, 4, 3);
		}
	}
			  break;
	case 191: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 192:
	case 193:
	case 196:
	case 197: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 194: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 195: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 198: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 199: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 200:
	case 204: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = Interpolate(c4, c5, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 13, 3);
			e20 = Interpolate(c7, c3, c4, 10, 5, 1);
			e21 = Interpolate(c7, c4, c5, 7, 6, 3);
		}
	}
			  break;
	case 201:
	case 205: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
	}
			  break;
	case 202: {
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 203: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			  break;
	case 206: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 13, 3)) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 207: {
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 10, 5, 1);
			e01 = Interpolate(c4, c1, c5, 7, 6, 3);
			e10 = Interpolate(c4, c3, 13, 3);
		}
	}
			  break;
	case 208:
	case 209: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 210: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 211: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 212:
	case 213: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 9, 4, 3);
			e11 = Interpolate(c4, c5, 1, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c7, c5, c4, 7, 5, 4);
		}
	}
			  break;
	case 215: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 216: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 217: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 218: {
		e10 = c4;
		if (IsLike(c7, c3)) {
			e20 = Interpolate(c4, c3, c7, 10, 3, 3);
		}
		if ((IsLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = Interpolate(c4, c6, 13, 3);
		}
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 219: {
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
			e10 = Interpolate(c4, c3, 15, 1);
		}
	}
			  break;
	case 220: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		if (IsLike(c7, c3)) {
			e20 = Interpolate(c4, c3, c7, 10, 3, 3);
		}
		if ((IsLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = Interpolate(c4, c6, 13, 3);
		}
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 221: {
		e00 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 3, 1);
			e11 = c4;
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 9, 4, 3);
			e11 = Interpolate(c4, c5, 1, 1);
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c7, c5, c4, 7, 5, 4);
		}
	}
			  break;
	case 222: {
		e10 = c4;
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
		}
	}
			  break;
	case 223: {
		if (IsLike(c1, c3)) {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
		}
		if ((IsLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = Interpolate(c4, c1, 15, 1);
		}
		if ((IsNotLike(c1, c5) && IsNotLike(c1, c3))) {
			e00 = c4;
		}
		if (IsNotLike(c7, c5)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e21 = c4;
		}
		else {
			e20 = Interpolate(c4, c6, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		e10 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c3, 15, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 10, 3, 3);
			e11 = Interpolate(c4, c5, 15, 1);
		}
	}
			  break;
	case 224:
	case 225:
	case 228:
	case 229: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 226: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 227: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 230: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 231: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
	}
			  break;
	case 232:
	case 236: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c5, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 13, 3);
			e20 = Interpolate(c7, c3, c4, 10, 5, 1);
			e21 = Interpolate(c7, c4, c5, 7, 6, 3);
		}
	}
			  break;
	case 233:
	case 237: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
	}
			  break;
	case 234: {
		e01 = Interpolate(c4, c2, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c5, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
			e21 = Interpolate(c4, c5, c7, 12, 3, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 13, 3)) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 235: {
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
	}
			  break;
	case 238: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c5, 13, 3);
		e11 = Interpolate(c4, c5, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = Interpolate(c4, c5, 13, 3);
		}
		else {
			e10 = Interpolate(c4, c3, 13, 3);
			e20 = Interpolate(c7, c3, c4, 10, 5, 1);
			e21 = Interpolate(c7, c4, c5, 7, 6, 3);
		}
	}
			  break;
	case 239: {
		e01 = Interpolate(c4, c5, 13, 3);
		e10 = c4;
		e11 = Interpolate(c4, c5, 13, 3);
		e21 = Interpolate(c4, c5, 13, 3);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
	}
			  break;
	case 240:
	case 241: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c3, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 13, 3);
			e20 = Interpolate(c7, c4, c3, 7, 6, 3);
			e21 = Interpolate(c7, c5, c4, 10, 5, 1);
		}
	}
			  break;
	case 242: {
		e00 = Interpolate(c4, c0, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c3, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e20 = Interpolate(c4, c3, c7, 12, 3, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		e01 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 13, 3)) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 243: {
		e00 = Interpolate(c4, c3, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e20 = Interpolate(c4, c3, 13, 3);
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 13, 3);
			e20 = Interpolate(c7, c4, c3, 7, 6, 3);
			e21 = Interpolate(c7, c5, c4, 10, 5, 1);
		}
	}
			  break;
	case 244:
	case 245: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			  break;
	case 246: {
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
		}
	}
			  break;
	case 247: {
		e00 = Interpolate(c4, c3, 13, 3);
		e10 = Interpolate(c4, c3, 13, 3);
		e11 = c4;
		e20 = Interpolate(c4, c3, 13, 3);
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
	case 249: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		e10 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 250: {
		e00 = Interpolate(c4, c0, 13, 3);
		e01 = Interpolate(c4, c2, 13, 3);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
	}
			  break;
	case 251: {
		if (IsLike(c7, c5)) {
			e21 = Interpolate(c4, c5, c7, 6, 5, 5);
		}
		if ((IsNotLike(c7, c5) && IsLike(c7, c3))) {
			e21 = Interpolate(c4, c7, 15, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e21 = c4;
		}
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 10, 3, 3);
		}
		e11 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, 15, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 6, 5, 5);
			e01 = Interpolate(c4, c2, c1, 12, 3, 1);
		}
	}
			  break;
	case 252: {
		e00 = Interpolate(c4, c0, c1, 12, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 15, 1);
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			  break;
	case 253: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
	}
			  break;
	case 254: {
		if (IsLike(c7, c3)) {
			e20 = Interpolate(c4, c3, c7, 6, 5, 5);
		}
		if ((IsLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = Interpolate(c4, c7, 15, 1);
		}
		if ((IsNotLike(c7, c5) && IsNotLike(c7, c3))) {
			e20 = c4;
		}
		e10 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, 15, 1));
		if (IsNotLike(c7, c5)) {
			e11 = c4;
			e21 = c4;
		}
		else {
			e11 = Interpolate(c4, c5, 15, 1);
			e21 = Interpolate(c4, c5, c7, 10, 3, 3);
		}
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c0, 13, 3);
			e01 = c4;
		}
		else {
			e00 = Interpolate(c4, c0, c1, 12, 3, 1);
			e01 = Interpolate(c4, c1, c5, 6, 5, 5);
		}
	}
			  break;
	case 255: {
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 10, 3, 3));
		e21 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 10, 3, 3));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 10, 3, 3));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 10, 3, 3));
	}
			  break;
			  #pragma endregion
	}

	Pixel[1] = (e00);
	Pixel[2] = (e01);
	Pixel[4] = (e10);
	Pixel[5] = (e11);
	Pixel[7] = (e20);
	Pixel[8] = (e21);
}
#pragma endregion

#pragma region standard HQ2x4 casepath
void Hq2x4Kernel(byte pattern, sPixel c0, sPixel c1, sPixel c2, sPixel c3, sPixel c4, sPixel c5, sPixel c6, sPixel c7, sPixel c8, int* Pixel) {
	sPixel e01, e10, e11, e20, e21, e30, e31;
	auto e00 = e01 = e10 = e11 = e20 = e21 = e30 = e31 = c4;
	switch (pattern) {
		#pragma region HQ2x4 PATTERNS

	case 0:
	case 1:
	case 4:
	case 5:
	case 32:
	case 33:
	case 36:
	case 37:
	case 128:
	case 129:
	case 132:
	case 133:
	case 160:
	case 161:
	case 164:
	case 165: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 2:
	case 34:
	case 130:
	case 162: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 3:
	case 35:
	case 131:
	case 163: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 6:
	case 38:
	case 134:
	case 166: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 7:
	case 39:
	case 135:
	case 167: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 8:
	case 12:
	case 136:
	case 140: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 9:
	case 13:
	case 137:
	case 141: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 10:
	case 138: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 11:
	case 139: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 14:
	case 142: {
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e01 = Interpolate(c4, c5, 3, 1);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c1, c3, 9, 7);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c4, c3, c1, 8, 5, 3);
		}
	}
			  break;
	case 15:
	case 143: {
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 9, 7);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c4, c3, c1, 8, 5, 3);
		}
	}
			  break;
	case 16:
	case 17:
	case 48:
	case 49: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 18:
	case 50: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 19:
	case 51: {
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e00 = Interpolate(c1, c4, 1, 1);
			e01 = Interpolate(c1, c5, 9, 7);
			e11 = Interpolate(c4, c5, c1, 8, 5, 3);
		}
	}
			 break;
	case 20:
	case 21:
	case 52:
	case 53: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 22:
	case 54: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 23:
	case 55: {
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c1, c4, 1, 1);
			e01 = Interpolate(c1, c5, 9, 7);
			e11 = Interpolate(c4, c5, c1, 8, 5, 3);
		}
	}
			 break;
	case 24: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 25: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 26:
	case 31: {
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 27: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			 break;
	case 28: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 29: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 30: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 40:
	case 44:
	case 168:
	case 172: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 41:
	case 45:
	case 169:
	case 173: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
	}
			  break;
	case 42:
	case 170: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 4, 3, 1);
			e10 = Interpolate(c3, c4, c1, 3, 3, 2);
			e20 = Interpolate(c4, c3, c7, 9, 6, 1);
			e30 = Interpolate(c4, c7, c3, 11, 3, 2);
		}
	}
			  break;
	case 43:
	case 171: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 4, 3, 1);
			e10 = Interpolate(c3, c4, c1, 3, 3, 2);
			e20 = Interpolate(c4, c3, c7, 9, 6, 1);
			e30 = Interpolate(c4, c7, c3, 11, 3, 2);
		}
	}
			  break;
	case 46:
	case 174: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 47:
	case 175: {
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c5, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, c5, 9, 4, 3);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 56: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 57: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 58: {
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 59: {
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 60: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 61: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
	}
			 break;
	case 62: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 63: {
		e10 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c8, c7, 5, 2, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 64:
	case 65:
	case 68:
	case 69: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 66: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 67: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 70: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 71: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 72:
	case 76: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			 break;
	case 73:
	case 77: {
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 11, 3, 2);
			e10 = Interpolate(c4, c3, c1, 9, 6, 1);
			e20 = Interpolate(c3, c4, c7, 3, 3, 2);
			e30 = Interpolate(c7, c3, c4, 4, 3, 1);
		}
	}
			 break;
	case 74:
	case 107: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 75: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			 break;
	case 78: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			 break;
	case 79: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			 break;
	case 80:
	case 81: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			 break;
	case 82:
	case 214: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 83: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 84:
	case 85: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 5, 3);
			e11 = Interpolate(c4, c1, 7, 1);
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 11, 3, 2);
			e11 = Interpolate(c4, c5, c1, 9, 6, 1);
			e21 = Interpolate(c4, c5, c7, 3, 3, 2);
			e31 = Interpolate(c7, c5, c4, 4, 3, 1);
		}
	}
			 break;
	case 86: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 87: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 88:
	case 248: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 89: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			 break;
	case 90: {
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 91: {
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 92: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			 break;
	case 93: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			 break;
	case 94: {
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 95: {
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 96:
	case 97:
	case 100:
	case 101: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			  break;
	case 98: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 99: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			 break;
	case 102: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			  break;
	case 103: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
	}
			  break;
	case 104:
	case 108: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 105:
	case 109: {
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = c4;
			e30 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 11, 3, 2);
			e10 = Interpolate(c4, c3, c1, 9, 6, 1);
			e20 = Interpolate(c3, c4, c7, 3, 3, 2);
			e30 = Interpolate(c7, c3, c4, 4, 3, 1);
		}
	}
			  break;
	case 106: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 110: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 111: {
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, c8, 6, 1, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 112:
	case 113: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e30 = Interpolate(c4, c3, 3, 1);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, c7, 8, 5, 3);
			e30 = Interpolate(c4, c7, 1, 1);
			e31 = Interpolate(c7, c5, 9, 7);
		}
	}
			  break;
	case 114: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 115: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 116:
	case 117: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			  break;
	case 118: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 119: {
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c1, c4, 1, 1);
			e01 = Interpolate(c1, c5, 9, 7);
			e11 = Interpolate(c4, c5, c1, 8, 5, 3);
		}
	}
			  break;
	case 120: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 121: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
	}
			  break;
	case 122: {
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = Interpolate(c4, c8, 13, 3);
			e31 = Interpolate(c4, c8, 11, 5);
		}
		else {
			e21 = Interpolate(c4, c5, 7, 1);
			e31 = Interpolate(c4, c7, c5, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 123: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 124: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 125: {
		e01 = Interpolate(c4, c1, 5, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = c4;
			e30 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 11, 3, 2);
			e10 = Interpolate(c4, c3, c1, 9, 6, 1);
			e20 = Interpolate(c3, c4, c7, 3, 3, 2);
			e30 = Interpolate(c7, c3, c4, 4, 3, 1);
		}
	}
			  break;
	case 126: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 127: {
		e10 = c4;
		e21 = Interpolate(c4, c8, 13, 3);
		e31 = Interpolate(c4, c8, 11, 5);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 144:
	case 145:
	case 176:
	case 177: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 146:
	case 178: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
			e21 = Interpolate(c4, c7, 7, 1);
			e31 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 4, 3, 1);
			e11 = Interpolate(c4, c5, c1, 3, 3, 2);
			e21 = Interpolate(c4, c5, c7, 9, 6, 1);
			e31 = Interpolate(c4, c7, c5, 11, 3, 2);
		}
	}
			  break;
	case 147:
	case 179: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 148:
	case 149:
	case 180:
	case 181: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 150:
	case 182: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
			e21 = Interpolate(c4, c7, 7, 1);
			e31 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 4, 3, 1);
			e11 = Interpolate(c4, c5, c1, 3, 3, 2);
			e21 = Interpolate(c4, c5, c7, 9, 6, 1);
			e31 = Interpolate(c4, c7, c5, 11, 3, 2);
		}
	}
			  break;
	case 151:
	case 183: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 11, 3, 2);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, c3, 9, 4, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 152: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 153: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 154: {
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 155: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 156: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 157: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 158: {
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 159: {
		e11 = c4;
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 184: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 185: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 186: {
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 187: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e21 = Interpolate(c4, c7, 7, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, c4, 4, 3, 1);
			e10 = Interpolate(c3, c4, c1, 3, 3, 2);
			e20 = Interpolate(c4, c3, c7, 9, 6, 1);
			e30 = Interpolate(c4, c7, c3, 11, 3, 2);
		}
	}
			  break;
	case 188: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 189: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 190: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
			e21 = Interpolate(c4, c7, 7, 1);
			e31 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e01 = Interpolate(c1, c5, c4, 4, 3, 1);
			e11 = Interpolate(c4, c5, c1, 3, 3, 2);
			e21 = Interpolate(c4, c5, c7, 9, 6, 1);
			e31 = Interpolate(c4, c7, c5, 11, 3, 2);
		}
	}
			  break;
	case 191: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 192:
	case 193:
	case 196:
	case 197: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 194: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 195: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 198: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 199: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 200:
	case 204: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
			e31 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 8, 5, 3);
			e30 = Interpolate(c7, c3, 9, 7);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 201:
	case 205: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
	}
			  break;
	case 202: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 203: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 206: {
		e01 = Interpolate(c4, c5, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 207: {
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = Interpolate(c4, c5, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 9, 7);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c4, c3, c1, 8, 5, 3);
		}
	}
			  break;
	case 208:
	case 209: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 210: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 211: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 212:
	case 213: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 5, 3);
			e11 = Interpolate(c4, c1, 7, 1);
			e21 = c4;
			e31 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 11, 3, 2);
			e11 = Interpolate(c4, c5, c1, 9, 6, 1);
			e21 = Interpolate(c4, c5, c7, 3, 3, 2);
			e31 = Interpolate(c7, c5, c4, 4, 3, 1);
		}
	}
			  break;
	case 215: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c6, 6, 1, 1);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 216: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 217: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 218: {
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 219: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 220: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 13, 3);
			e30 = Interpolate(c4, c6, 11, 5);
		}
		else {
			e20 = Interpolate(c4, c3, 7, 1);
			e30 = Interpolate(c4, c7, c3, 5, 2, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 221: {
		e00 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e01 = Interpolate(c4, c1, 5, 3);
			e11 = Interpolate(c4, c1, 7, 1);
			e21 = c4;
			e31 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, c5, 11, 3, 2);
			e11 = Interpolate(c4, c5, c1, 9, 6, 1);
			e21 = Interpolate(c4, c5, c7, 3, 3, 2);
			e31 = Interpolate(c7, c5, c4, 4, 3, 1);
		}
	}
			  break;
	case 222: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 223: {
		e11 = c4;
		e20 = Interpolate(c4, c6, 13, 3);
		e30 = Interpolate(c4, c6, 11, 5);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 224:
	case 225:
	case 228:
	case 229: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 226: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 227: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 230: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 231: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 232:
	case 236: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e21 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 8, 5, 3);
			e30 = Interpolate(c7, c3, 9, 7);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 233:
	case 237: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, c5, 9, 4, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c5, c1, 11, 3, 2);
		e20 = c4;
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
	}
			  break;
	case 234: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 11, 5);
			e10 = Interpolate(c4, c0, 13, 3);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 5, 2, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 235: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, c5, 6, 1, 1);
		e20 = c4;
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 238: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, c7, 8, 5, 3);
			e30 = Interpolate(c7, c3, 9, 7);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 239: {
		e01 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = Interpolate(c4, c5, 3, 1);
		e20 = c4;
		e21 = Interpolate(c4, c5, 3, 1);
		e31 = Interpolate(c4, c5, 3, 1);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
	}
			  break;
	case 240:
	case 241: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e30 = Interpolate(c4, c3, 3, 1);
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, c7, 8, 5, 3);
			e30 = Interpolate(c4, c7, 1, 1);
			e31 = Interpolate(c7, c5, 9, 7);
		}
	}
			  break;
	case 242: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e30 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = Interpolate(c4, c2, 11, 5);
			e11 = Interpolate(c4, c2, 13, 3);
		}
		else {
			e01 = Interpolate(c4, c1, c5, 5, 2, 1);
			e11 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 243: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e30 = Interpolate(c4, c3, 3, 1);
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, c7, 8, 5, 3);
			e30 = Interpolate(c4, c7, 1, 1);
			e31 = Interpolate(c7, c5, 9, 7);
		}
	}
			  break;
	case 244:
	case 245: {
		e00 = Interpolate(c4, c1, c3, 9, 4, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 11, 3, 2);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			  break;
	case 246: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, c3, 6, 1, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 247: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e30 = Interpolate(c4, c3, 3, 1);
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
	case 249: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c2, c1, 5, 2, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 250: {
		e00 = Interpolate(c4, c0, 11, 5);
		e01 = Interpolate(c4, c2, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c2, 13, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
	}
			  break;
	case 251: {
		e01 = Interpolate(c4, c2, 11, 5);
		e11 = Interpolate(c4, c2, 13, 3);
		e20 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e31 = c4;
		}
		else {
			e21 = Interpolate(c4, c5, 3, 1);
			e31 = Interpolate(c7, c4, c5, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 252: {
		e00 = Interpolate(c4, c0, c1, 5, 2, 1);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 13, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			  break;
	case 253: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e20 = c4;
		e21 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
	}
			  break;
	case 254: {
		e00 = Interpolate(c4, c0, 11, 5);
		e10 = Interpolate(c4, c0, 13, 3);
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e30 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e11 = c4;
		}
		else {
			e01 = Interpolate(c1, c4, c5, 2, 1, 1);
			e11 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 255: {
		e10 = c4;
		e11 = c4;
		e20 = c4;
		e21 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 6, 1, 1));
		e31 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 6, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 6, 1, 1));
		e01 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 6, 1, 1));
	}
			  break;
			  #pragma endregion
	}

	Pixel[1] = (e00);
	Pixel[2] = (e01);
	Pixel[5] = (e10);
	Pixel[6] = (e11);
	Pixel[9] = (e20);
	Pixel[10] = (e21);
	Pixel[13] = (e30);
	Pixel[14] = (e31);
}
#pragma endregion

#pragma region standard HQ3x casepath
void Hq3xKernel(byte pattern, sPixel c0, sPixel c1, sPixel c2, sPixel c3, sPixel c4, sPixel c5, sPixel c6, sPixel c7, sPixel c8, int* Pixel) {
	sPixel e01, e02, e10, e11, e12, e20, e21, e22;
	auto e00 = e01 = e02 = e10 = e11 = e12 = e20 = e21 = e22 = c4;
	switch (pattern) {
		#pragma region HQ3x PATTERNS

	case 0:
	case 1:
	case 4:
	case 5:
	case 32:
	case 33:
	case 36:
	case 37:
	case 128:
	case 129:
	case 132:
	case 133:
	case 160:
	case 161:
	case 164:
	case 165: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 2:
	case 34:
	case 130:
	case 162: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 3:
	case 35:
	case 131:
	case 163: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 6:
	case 38:
	case 134:
	case 166: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 7:
	case 39:
	case 135:
	case 167: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 8:
	case 12:
	case 136:
	case 140: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 9:
	case 13:
	case 137:
	case 141: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 10:
	case 138: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 3, 1);
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 11:
	case 139: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 14:
	case 142: {
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 3, 1);
			e01 = c4;
			e02 = Interpolate(c4, c5, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 15:
	case 143: {
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e02 = Interpolate(c4, c5, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 16:
	case 17:
	case 48:
	case 49: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 18:
	case 50: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = Interpolate(c4, c2, 3, 1);
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 19:
	case 51: {
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
			e02 = Interpolate(c4, c2, 3, 1);
			e12 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 20:
	case 21:
	case 52:
	case 53: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 22:
	case 54: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 23:
	case 55: {
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 24: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 25: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 26:
	case 31: {
		e01 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e12 = c4;
		}
		else {
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 27: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			 break;
	case 28: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 29: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 30: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 40:
	case 44:
	case 168:
	case 172: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 41:
	case 45:
	case 169:
	case 173: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 42:
	case 170: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 3, 1);
			e01 = c4;
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		}
	}
			  break;
	case 43:
	case 171: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		}
	}
			  break;
	case 46:
	case 174: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 47:
	case 175: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 56: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 57: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 58: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 59: {
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 60: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 61: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 62: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 63: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e12 = c4;
		}
		else {
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 64:
	case 65:
	case 68:
	case 69: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 66: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 67: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 70: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 71: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 72:
	case 76: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			 break;
	case 73:
	case 77: {
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c4, c7, 3, 1);
		}
	}
			 break;
	case 74:
	case 107: {
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
		}
		else {
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
		}
	}
			  break;
	case 75: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			 break;
	case 78: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			 break;
	case 79: {
		e02 = Interpolate(c4, c5, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			 break;
	case 80:
	case 81: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = Interpolate(c4, c8, 3, 1);
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			 break;
	case 82:
	case 214: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e22 = c4;
		}
		else {
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
		}
	}
			  break;
	case 83: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 84:
	case 85: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e02 = Interpolate(c4, c1, 3, 1);
			e12 = c4;
			e21 = c4;
			e22 = Interpolate(c4, c8, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e21 = Interpolate(c4, c7, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			 break;
	case 86: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 87: {
		e00 = Interpolate(c4, c3, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 88:
	case 248: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 89: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			 break;
	case 90: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 91: {
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			 break;
	case 92: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			 break;
	case 93: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			 break;
	case 94: {
		e10 = c4;
		e11 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 95: {
		e01 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e12 = c4;
		}
		else {
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			 break;
	case 96:
	case 97:
	case 100:
	case 101: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			  break;
	case 98: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 99: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			 break;
	case 102: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			  break;
	case 103: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
	}
			  break;
	case 104:
	case 108: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			  break;
	case 105:
	case 109: {
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 106: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			  break;
	case 110: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			  break;
	case 111: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
		}
		else {
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 112:
	case 113: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e22 = Interpolate(c4, c8, 3, 1);
		}
		else {
			e12 = Interpolate(c4, c5, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 114: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 115: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 116:
	case 117: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 118: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 119: {
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 3, 1);
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 120: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			  break;
	case 121: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 122: {
		e01 = c4;
		e11 = c4;
		e12 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		e22 = (IsNotLike(c7, c5)) ? (Interpolate(c4, c8, 3, 1)) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 123: {
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
		}
		else {
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
		}
	}
			  break;
	case 124: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		e12 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
	}
			  break;
	case 125: {
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		e12 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 3, 1);
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 126: {
		e00 = Interpolate(c4, c0, 3, 1);
		e11 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 127: {
		e11 = c4;
		e22 = Interpolate(c4, c8, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
		}
		else {
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e12 = c4;
		}
		else {
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 144:
	case 145:
	case 176:
	case 177: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 146:
	case 178: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = Interpolate(c4, c2, 3, 1);
			e12 = c4;
			e22 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c4, c1, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 147:
	case 179: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 148:
	case 149:
	case 180:
	case 181: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 150:
	case 182: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
			e22 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c4, c1, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 151:
	case 183: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 152: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 153: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 154: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 155: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 156: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 157: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 158: {
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 159: {
		e01 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 184: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 185: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 186: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 187: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = c4;
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
			e20 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
		}
	}
			  break;
	case 188: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 189: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
	}
			  break;
	case 190: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
			e22 = Interpolate(c4, c7, 3, 1);
		}
		else {
			e01 = Interpolate(c4, c1, 3, 1);
			e02 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 191: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 3, 1);
		e21 = Interpolate(c4, c7, 3, 1);
		e22 = Interpolate(c4, c7, 3, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 192:
	case 193:
	case 196:
	case 197: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 194: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 195: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 198: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 199: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 200:
	case 204: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = c4;
			e22 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c4, c3, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 201:
	case 205: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 202: {
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 203: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 206: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 207: {
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e02 = Interpolate(c4, c5, 3, 1);
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e10 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 208:
	case 209: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 210: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 211: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 212:
	case 213: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e02 = Interpolate(c4, c1, 3, 1);
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e21 = Interpolate(c4, c7, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 215: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e22 = c4;
		}
		else {
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 216: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 217: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 218: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 219: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
			e10 = Interpolate(c4, c3, 7, 1);
		}
	}
			  break;
	case 220: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = (IsNotLike(c7, c3)) ? (Interpolate(c4, c6, 3, 1)) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 221: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e02 = Interpolate(c4, c1, 3, 1);
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = Interpolate(c5, c4, 3, 1);
			e21 = Interpolate(c4, c7, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 222: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e22 = c4;
		}
		else {
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
		}
	}
			  break;
	case 223: {
		e11 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e21 = c4;
			e22 = c4;
		}
		else {
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e10 = Interpolate(c4, c3, 7, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
			e12 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = Interpolate(c4, c5, 7, 1);
		}
	}
			  break;
	case 224:
	case 225:
	case 228:
	case 229: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 226: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 227: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 230: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 231: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
	}
			  break;
	case 232:
	case 236: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
			e22 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c4, c3, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 233:
	case 237: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 234: {
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e22 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (Interpolate(c4, c0, 3, 1)) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 235: {
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
		}
	}
			  break;
	case 238: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
			e22 = Interpolate(c4, c5, 3, 1);
		}
		else {
			e10 = Interpolate(c4, c3, 3, 1);
			e20 = Interpolate(c3, c7, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 239: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 3, 1);
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 240:
	case 241: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 242: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		e02 = (IsNotLike(c1, c5)) ? (Interpolate(c4, c2, 3, 1)) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 243: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 3, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
			e21 = Interpolate(c7, c4, 3, 1);
			e22 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 244:
	case 245: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 246: {
		e00 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
		}
	}
			  break;
	case 247: {
		e00 = Interpolate(c4, c3, 3, 1);
		e01 = c4;
		e10 = Interpolate(c4, c3, 3, 1);
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c3, 3, 1);
		e21 = c4;
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 249: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e10 = c4;
		e11 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 250: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = c4;
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
	}
			  break;
	case 251: {
		e02 = Interpolate(c4, c2, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
			e21 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c4, c3, c7, 2, 1, 1);
			e21 = Interpolate(c4, c7, 7, 1);
		}
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e22 = Interpolate(c5, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, c4, 7, 7, 2);
			e01 = Interpolate(c4, c1, 7, 1);
		}
	}
			  break;
	case 252: {
		e00 = Interpolate(c4, c0, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e11 = c4;
		e12 = c4;
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
		}
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 253: {
		e00 = Interpolate(c4, c1, 3, 1);
		e01 = Interpolate(c4, c1, 3, 1);
		e02 = Interpolate(c4, c1, 3, 1);
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 254: {
		e00 = Interpolate(c4, c0, 3, 1);
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e10 = c4;
			e20 = c4;
		}
		else {
			e10 = Interpolate(c4, c3, 7, 1);
			e20 = Interpolate(c3, c7, c4, 7, 7, 2);
		}
		if (IsNotLike(c7, c5)) {
			e12 = c4;
			e21 = c4;
			e22 = c4;
		}
		else {
			e12 = Interpolate(c4, c5, 7, 1);
			e21 = Interpolate(c4, c7, 7, 1);
			e22 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e01 = c4;
			e02 = c4;
		}
		else {
			e01 = Interpolate(c4, c1, 7, 1);
			e02 = Interpolate(c1, c5, c4, 7, 7, 2);
		}
	}
			  break;
	case 255: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e20 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e22 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e02 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
			  #pragma endregion
	}
	Pixel[1] = (e00);
	Pixel[2] = (e01);
	Pixel[3] = (e02);
	Pixel[4] = (e10);
	Pixel[5] = (e11);
	Pixel[6] = (e12);
	Pixel[7] = (e20);
	Pixel[8] = (e21);
	Pixel[9] = (e22);
}

#pragma region standard HQ4x casepath
void Hq4xKernel(byte pattern, sPixel c0, sPixel c1, sPixel c2, sPixel c3, sPixel c4, sPixel c5, sPixel c6, sPixel c7, sPixel c8, int* Pixel) {
	sPixel e01, e02, e03, e10, e11, e12, e13, e20, e21, e22, e23, e30, e31, e32, e33;
	auto e00 = e01 = e02 = e03 = e10 = e11 = e12 = e13 = e20 = e21 = e22 = e23 = e30 = e31 = e32 = e33 = c4;
	switch (pattern) {
		#pragma region HQ4x PATTERNS

	case 0:
	case 1:
	case 4:
	case 5:
	case 32:
	case 33:
	case 36:
	case 37:
	case 128:
	case 129:
	case 132:
	case 133:
	case 160:
	case 161:
	case 164:
	case 165: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 2:
	case 34:
	case 130:
	case 162: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 3:
	case 35:
	case 131:
	case 163: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 6:
	case 38:
	case 134:
	case 166: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 7:
	case 39:
	case 135:
	case 167: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 8:
	case 12:
	case 136:
	case 140: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 9:
	case 13:
	case 137:
	case 141: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 10:
	case 138: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
			e11 = c4;
		}
	}
			  break;
	case 11:
	case 139: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 14:
	case 142: {
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e02 = Interpolate(c4, c5, 7, 1);
			e03 = Interpolate(c4, c5, 5, 3);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, 5, 3);
			e02 = Interpolate(c1, c4, 3, 1);
			e03 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c1, c4, 2, 1, 1);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		}
	}
			  break;
	case 15:
	case 143: {
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e02 = Interpolate(c4, c5, 7, 1);
			e03 = Interpolate(c4, c5, 5, 3);
			e10 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, 5, 3);
			e02 = Interpolate(c1, c4, 3, 1);
			e03 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c1, c4, 2, 1, 1);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		}
	}
			  break;
	case 16:
	case 17:
	case 48:
	case 49: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 18:
	case 50: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 19:
	case 51: {
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 5, 3);
			e01 = Interpolate(c4, c3, 7, 1);
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c1, 3, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 5, 3);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, c4, 2, 1, 1);
		}
	}
			 break;
	case 20:
	case 21:
	case 52:
	case 53: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 22:
	case 54: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 23:
	case 55: {
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 5, 3);
			e01 = Interpolate(c4, c3, 7, 1);
			e02 = c4;
			e03 = c4;
			e12 = c4;
			e13 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, 3, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 5, 3);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, c4, 2, 1, 1);
		}
	}
			 break;
	case 24: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 25: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 26:
	case 31: {
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 27: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			 break;
	case 28: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 29: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 30: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 40:
	case 44:
	case 168:
	case 172: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 41:
	case 45:
	case 169:
	case 173: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
	}
			  break;
	case 42:
	case 170: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c3, c1, 5, 3);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
			e20 = Interpolate(c3, c4, 3, 1);
			e30 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 43:
	case 171: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
			e11 = c4;
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c3, c1, 5, 3);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
			e20 = Interpolate(c3, c4, 3, 1);
			e30 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 46:
	case 174: {
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
	}
			  break;
	case 47:
	case 175: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c5, c7, 6, 1, 1);
		e23 = Interpolate(c4, c5, c7, 5, 2, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c5, 5, 2, 1);
		e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 56: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 57: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 58: {
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 59: {
		e11 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 60: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 61: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 62: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 63: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, c8, 5, 2, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 64:
	case 65:
	case 68:
	case 69: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 66: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 67: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 70: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 71: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 72:
	case 76: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e21 = c4;
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			 break;
	case 73:
	case 77: {
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e00 = Interpolate(c4, c3, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 5, 3);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			 break;
	case 74:
	case 107: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 75: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			 break;
	case 78: {
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
	}
			 break;
	case 79: {
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			 break;
	case 80:
	case 81: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			 break;
	case 82:
	case 214: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 83: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 84:
	case 85: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e03 = Interpolate(c4, c1, 5, 3);
			e13 = Interpolate(c4, c1, 7, 1);
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e03 = Interpolate(c4, c5, 3, 1);
			e13 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c7, 5, 3);
			e32 = Interpolate(c7, c4, c5, 2, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			 break;
	case 86: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 87: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 88:
	case 248: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = c4;
		e22 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 89: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			 break;
	case 90: {
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 91: {
		e11 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			 break;
	case 92: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			 break;
	case 93: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			 break;
	case 94: {
		e12 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 95: {
		e11 = c4;
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			 break;
	case 96:
	case 97:
	case 100:
	case 101: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			  break;
	case 98: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 99: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			 break;
	case 102: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			  break;
	case 103: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
	}
			  break;
	case 104:
	case 108: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 105:
	case 109: {
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = c4;
			e21 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e00 = Interpolate(c4, c3, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 5, 3);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 106: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 110: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 111: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c5, c8, 5, 2, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 112:
	case 113: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e30 = Interpolate(c4, c3, 5, 3);
			e31 = Interpolate(c4, c3, 7, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c4, c7, 2, 1, 1);
			e30 = Interpolate(c4, c7, 3, 1);
			e31 = Interpolate(c7, c4, 3, 1);
			e32 = Interpolate(c7, c5, 5, 3);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 114: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 115: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 116:
	case 117: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 118: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 119: {
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c1, c5)) {
			e00 = Interpolate(c4, c3, 5, 3);
			e01 = Interpolate(c4, c3, 7, 1);
			e02 = c4;
			e03 = c4;
			e12 = c4;
			e13 = c4;
		}
		else {
			e00 = Interpolate(c4, c1, 3, 1);
			e01 = Interpolate(c1, c4, 3, 1);
			e02 = Interpolate(c1, c5, 5, 3);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, c4, 2, 1, 1);
		}
	}
			  break;
	case 120: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 121: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
	}
			  break;
	case 122: {
		e21 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e22 = Interpolate(c4, c8, 7, 1);
			e23 = Interpolate(c4, c8, 3, 1);
			e32 = Interpolate(c4, c8, 3, 1);
			e33 = Interpolate(c4, c8, 5, 3);
		}
		else {
			e22 = c4;
			e23 = Interpolate(c4, c5, 3, 1);
			e32 = Interpolate(c4, c7, 3, 1);
			e33 = Interpolate(c4, c5, c7, 2, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 123: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 124: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
	}
			  break;
	case 125: {
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e00 = Interpolate(c4, c1, 5, 3);
			e10 = Interpolate(c4, c1, 7, 1);
			e20 = c4;
			e21 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e00 = Interpolate(c4, c3, 3, 1);
			e10 = Interpolate(c3, c4, 3, 1);
			e20 = Interpolate(c3, c7, 5, 3);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, c4, 2, 1, 1);
		}
	}
			  break;
	case 126: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 127: {
		e01 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e21 = c4;
		e22 = Interpolate(c4, c8, 7, 1);
		e23 = Interpolate(c4, c8, 3, 1);
		e32 = Interpolate(c4, c8, 3, 1);
		e33 = Interpolate(c4, c8, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 144:
	case 145:
	case 176:
	case 177: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 146:
	case 178: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
			e23 = Interpolate(c4, c7, 7, 1);
			e33 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e02 = Interpolate(c1, c4, c5, 2, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, 5, 3);
			e23 = Interpolate(c5, c4, 3, 1);
			e33 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 147:
	case 179: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 148:
	case 149:
	case 180:
	case 181: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 150:
	case 182: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e12 = c4;
			e13 = c4;
			e23 = Interpolate(c4, c7, 7, 1);
			e33 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e02 = Interpolate(c1, c4, c5, 2, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, 5, 3);
			e23 = Interpolate(c5, c4, 3, 1);
			e33 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 151:
	case 183: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = c4;
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c3, c7, 5, 2, 1);
		e21 = Interpolate(c4, c3, c7, 6, 1, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c3, c7, 2, 1, 1);
		e31 = Interpolate(c4, c7, c3, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 152: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 153: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 154: {
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 155: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 156: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 157: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 158: {
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 159: {
		e02 = c4;
		e11 = c4;
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c7, c6, 5, 2, 1);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 184: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 185: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 186: {
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 187: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
			e11 = c4;
			e20 = Interpolate(c4, c7, 7, 1);
			e30 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, c4, 2, 1, 1);
			e10 = Interpolate(c3, c1, 5, 3);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
			e20 = Interpolate(c3, c4, 3, 1);
			e30 = Interpolate(c4, c3, 3, 1);
		}
	}
			  break;
	case 188: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 189: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
	}
			  break;
	case 190: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e12 = c4;
			e13 = c4;
			e23 = Interpolate(c4, c7, 7, 1);
			e33 = Interpolate(c4, c7, 5, 3);
		}
		else {
			e02 = Interpolate(c1, c4, c5, 2, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e12 = Interpolate(c4, c1, c5, 6, 1, 1);
			e13 = Interpolate(c5, c1, 5, 3);
			e23 = Interpolate(c5, c4, 3, 1);
			e33 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 191: {
		e01 = c4;
		e02 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c7, 7, 1);
		e21 = Interpolate(c4, c7, 7, 1);
		e22 = Interpolate(c4, c7, 7, 1);
		e23 = Interpolate(c4, c7, 7, 1);
		e30 = Interpolate(c4, c7, 5, 3);
		e31 = Interpolate(c4, c7, 5, 3);
		e32 = Interpolate(c4, c7, 5, 3);
		e33 = Interpolate(c4, c7, 5, 3);
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 192:
	case 193:
	case 196:
	case 197: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 194: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 195: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 198: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 199: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 200:
	case 204: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
			e32 = Interpolate(c4, c5, 7, 1);
			e33 = Interpolate(c4, c5, 5, 3);
		}
		else {
			e20 = Interpolate(c3, c4, c7, 2, 1, 1);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, 5, 3);
			e32 = Interpolate(c7, c4, 3, 1);
			e33 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 201:
	case 205: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 202: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
	}
			  break;
	case 203: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 206: {
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
	}
			  break;
	case 207: {
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e02 = Interpolate(c4, c5, 7, 1);
			e03 = Interpolate(c4, c5, 5, 3);
			e10 = c4;
			e11 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c3, 5, 3);
			e02 = Interpolate(c1, c4, 3, 1);
			e03 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c3, c1, c4, 2, 1, 1);
			e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		}
	}
			  break;
	case 208:
	case 209: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 210: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 211: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 212:
	case 213: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e03 = Interpolate(c4, c1, 5, 3);
			e13 = Interpolate(c4, c1, 7, 1);
			e22 = c4;
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e03 = Interpolate(c4, c5, 3, 1);
			e13 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c7, 5, 3);
			e32 = Interpolate(c7, c4, c5, 2, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 215: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = c4;
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c3, c6, 5, 2, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 216: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 217: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 218: {
		e22 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 219: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 220: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e22 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = Interpolate(c4, c6, 3, 1);
			e21 = Interpolate(c4, c6, 7, 1);
			e30 = Interpolate(c4, c6, 5, 3);
			e31 = Interpolate(c4, c6, 3, 1);
		}
		else {
			e20 = Interpolate(c4, c3, 3, 1);
			e21 = c4;
			e30 = Interpolate(c4, c3, c7, 2, 1, 1);
			e31 = Interpolate(c4, c7, 3, 1);
		}
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 221: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e03 = Interpolate(c4, c1, 5, 3);
			e13 = Interpolate(c4, c1, 7, 1);
			e22 = c4;
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e03 = Interpolate(c4, c5, 3, 1);
			e13 = Interpolate(c5, c4, 3, 1);
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c7, 5, 3);
			e32 = Interpolate(c7, c4, c5, 2, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 222: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 223: {
		e02 = c4;
		e11 = c4;
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c6, 3, 1);
		e21 = Interpolate(c4, c6, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c6, 5, 3);
		e31 = Interpolate(c4, c6, 3, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 224:
	case 225:
	case 228:
	case 229: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 226: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 227: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 230: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 231: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
	}
			  break;
	case 232:
	case 236: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
			e30 = c4;
			e31 = c4;
			e32 = Interpolate(c4, c5, 7, 1);
			e33 = Interpolate(c4, c5, 5, 3);
		}
		else {
			e20 = Interpolate(c3, c4, c7, 2, 1, 1);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, 5, 3);
			e32 = Interpolate(c7, c4, 3, 1);
			e33 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 233:
	case 237: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c5, 5, 2, 1);
		e03 = Interpolate(c4, c1, c5, 2, 1, 1);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, c5, 6, 1, 1);
		e13 = Interpolate(c4, c5, c1, 5, 2, 1);
		e20 = c4;
		e21 = c4;
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e31 = c4;
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
	}
			  break;
	case 234: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e21 = c4;
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = Interpolate(c4, c0, 5, 3);
			e01 = Interpolate(c4, c0, 3, 1);
			e10 = Interpolate(c4, c0, 3, 1);
			e11 = Interpolate(c4, c0, 7, 1);
		}
		else {
			e00 = Interpolate(c4, c1, c3, 2, 1, 1);
			e01 = Interpolate(c4, c1, 3, 1);
			e10 = Interpolate(c4, c3, 3, 1);
			e11 = c4;
		}
	}
			  break;
	case 235: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c5, c2, 5, 2, 1);
		e20 = c4;
		e21 = c4;
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e31 = c4;
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 238: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e21 = c4;
			e30 = c4;
			e31 = c4;
			e32 = Interpolate(c4, c5, 7, 1);
			e33 = Interpolate(c4, c5, 5, 3);
		}
		else {
			e20 = Interpolate(c3, c4, c7, 2, 1, 1);
			e21 = Interpolate(c4, c3, c7, 6, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c7, c3, 5, 3);
			e32 = Interpolate(c7, c4, 3, 1);
			e33 = Interpolate(c4, c7, 3, 1);
		}
	}
			  break;
	case 239: {
		e01 = c4;
		e02 = Interpolate(c4, c5, 7, 1);
		e03 = Interpolate(c4, c5, 5, 3);
		e10 = c4;
		e11 = c4;
		e12 = Interpolate(c4, c5, 7, 1);
		e13 = Interpolate(c4, c5, 5, 3);
		e20 = c4;
		e21 = c4;
		e22 = Interpolate(c4, c5, 7, 1);
		e23 = Interpolate(c4, c5, 5, 3);
		e31 = c4;
		e32 = Interpolate(c4, c5, 7, 1);
		e33 = Interpolate(c4, c5, 5, 3);
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
	}
			  break;
	case 240:
	case 241: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = c4;
			e23 = c4;
			e30 = Interpolate(c4, c3, 5, 3);
			e31 = Interpolate(c4, c3, 7, 1);
			e32 = c4;
			e33 = c4;
		}
		else {
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c4, c7, 2, 1, 1);
			e30 = Interpolate(c4, c7, 3, 1);
			e31 = Interpolate(c7, c4, 3, 1);
			e32 = Interpolate(c7, c5, 5, 3);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 242: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = c4;
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c5)) {
			e02 = Interpolate(c4, c2, 3, 1);
			e03 = Interpolate(c4, c2, 5, 3);
			e12 = Interpolate(c4, c2, 7, 1);
			e13 = Interpolate(c4, c2, 3, 1);
		}
		else {
			e02 = Interpolate(c4, c1, 3, 1);
			e03 = Interpolate(c4, c1, c5, 2, 1, 1);
			e12 = c4;
			e13 = Interpolate(c4, c5, 3, 1);
		}
	}
			  break;
	case 243: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		if (IsNotLike(c7, c5)) {
			e22 = c4;
			e23 = c4;
			e30 = Interpolate(c4, c3, 5, 3);
			e31 = Interpolate(c4, c3, 7, 1);
			e32 = c4;
			e33 = c4;
		}
		else {
			e22 = Interpolate(c4, c5, c7, 6, 1, 1);
			e23 = Interpolate(c5, c4, c7, 2, 1, 1);
			e30 = Interpolate(c4, c7, 3, 1);
			e31 = Interpolate(c7, c4, 3, 1);
			e32 = Interpolate(c7, c5, 5, 3);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 244:
	case 245: {
		e00 = Interpolate(c4, c1, c3, 2, 1, 1);
		e01 = Interpolate(c4, c1, c3, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c3, c1, 5, 2, 1);
		e11 = Interpolate(c4, c1, c3, 6, 1, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = c4;
		e23 = c4;
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = c4;
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 246: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c3, c0, 5, 2, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = c4;
		e23 = c4;
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = c4;
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 247: {
		e00 = Interpolate(c4, c3, 5, 3);
		e01 = Interpolate(c4, c3, 7, 1);
		e02 = c4;
		e10 = Interpolate(c4, c3, 5, 3);
		e11 = Interpolate(c4, c3, 7, 1);
		e12 = c4;
		e13 = c4;
		e20 = Interpolate(c4, c3, 5, 3);
		e21 = Interpolate(c4, c3, 7, 1);
		e22 = c4;
		e23 = c4;
		e30 = Interpolate(c4, c3, 5, 3);
		e31 = Interpolate(c4, c3, 7, 1);
		e32 = c4;
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
	case 249: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, c2, 5, 2, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = c4;
		e21 = c4;
		e22 = c4;
		e31 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 250: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e21 = c4;
		e22 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
	}
			  break;
	case 251: {
		e02 = Interpolate(c4, c2, 3, 1);
		e03 = Interpolate(c4, c2, 5, 3);
		e11 = c4;
		e12 = Interpolate(c4, c2, 7, 1);
		e13 = Interpolate(c4, c2, 3, 1);
		e20 = c4;
		e21 = c4;
		e22 = c4;
		e31 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		if (IsNotLike(c7, c5)) {
			e23 = c4;
			e32 = c4;
			e33 = c4;
		}
		else {
			e23 = Interpolate(c4, c5, 1, 1);
			e32 = Interpolate(c4, c7, 1, 1);
			e33 = Interpolate(c5, c7, 1, 1);
		}
		if (IsNotLike(c1, c3)) {
			e00 = c4;
			e01 = c4;
			e10 = c4;
		}
		else {
			e00 = Interpolate(c1, c3, 1, 1);
			e01 = Interpolate(c1, c4, 1, 1);
			e10 = Interpolate(c3, c4, 1, 1);
		}
	}
			  break;
	case 252: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c1, c0, 5, 2, 1);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e21 = c4;
		e22 = c4;
		e23 = c4;
		e32 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 253: {
		e00 = Interpolate(c4, c1, 5, 3);
		e01 = Interpolate(c4, c1, 5, 3);
		e02 = Interpolate(c4, c1, 5, 3);
		e03 = Interpolate(c4, c1, 5, 3);
		e10 = Interpolate(c4, c1, 7, 1);
		e11 = Interpolate(c4, c1, 7, 1);
		e12 = Interpolate(c4, c1, 7, 1);
		e13 = Interpolate(c4, c1, 7, 1);
		e20 = c4;
		e21 = c4;
		e22 = c4;
		e23 = c4;
		e31 = c4;
		e32 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
	}
			  break;
	case 254: {
		e00 = Interpolate(c4, c0, 5, 3);
		e01 = Interpolate(c4, c0, 3, 1);
		e10 = Interpolate(c4, c0, 3, 1);
		e11 = Interpolate(c4, c0, 7, 1);
		e12 = c4;
		e21 = c4;
		e22 = c4;
		e23 = c4;
		e32 = c4;
		if (IsNotLike(c7, c3)) {
			e20 = c4;
			e30 = c4;
			e31 = c4;
		}
		else {
			e20 = Interpolate(c3, c4, 1, 1);
			e30 = Interpolate(c3, c7, 1, 1);
			e31 = Interpolate(c4, c7, 1, 1);
		}
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		if (IsNotLike(c1, c5)) {
			e02 = c4;
			e03 = c4;
			e13 = c4;
		}
		else {
			e02 = Interpolate(c1, c4, 1, 1);
			e03 = Interpolate(c1, c5, 1, 1);
			e13 = Interpolate(c4, c5, 1, 1);
		}
	}
			  break;
	case 255: {
		e01 = c4;
		e02 = c4;
		e10 = c4;
		e11 = c4;
		e12 = c4;
		e13 = c4;
		e20 = c4;
		e21 = c4;
		e22 = c4;
		e23 = c4;
		e31 = c4;
		e32 = c4;
		e30 = (IsNotLike(c7, c3)) ? (c4) : (Interpolate(c4, c3, c7, 2, 1, 1));
		e33 = (IsNotLike(c7, c5)) ? (c4) : (Interpolate(c4, c5, c7, 2, 1, 1));
		e00 = (IsNotLike(c1, c3)) ? (c4) : (Interpolate(c4, c1, c3, 2, 1, 1));
		e03 = (IsNotLike(c1, c5)) ? (c4) : (Interpolate(c4, c1, c5, 2, 1, 1));
	}
			  break;
			  #pragma endregion
	}
	
	Pixel[1] = (e00);
	Pixel[2] = (e01);
	Pixel[3] = (e02);
	Pixel[4] = (e03);
	Pixel[5] = (e10);
	Pixel[6] = (e11);
	Pixel[7] = (e12);
	Pixel[8] = (e13);
	Pixel[9] = (e20);
	Pixel[10] = (e21);
	Pixel[11] = (e22);
	Pixel[12] = (e23);
	Pixel[13] = (e30);
	Pixel[14] = (e31);
	Pixel[15] = (e32);
	Pixel[16] = (e33);
}
#pragma endregion
