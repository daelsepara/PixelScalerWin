#pragma once

#include "FilterCommon.h"
#include "Interpolate.h"

typedef int sPixel;

bool AllowAlphaBlending = true;
bool UseOriginalImplementation = false;

int AbsDifference(int pixel1, int pixel2) {
	
	static const unsigned char _LUMINANCE_TRIGGER = 48;
	static const unsigned char _CHROMA_U_TRIGGER = 7;
	static const unsigned char _CHROMA_V_TRIGGER = 6;

	return (
		_LUMINANCE_TRIGGER * std::abs(Luminance(pixel1) - Luminance(pixel2))
		+ _CHROMA_V_TRIGGER * std::abs(ChromaV(pixel1) - ChromaV(pixel2))
		+ _CHROMA_U_TRIGGER * std::abs(ChromaU(pixel1) - ChromaU(pixel2))
		);
}

int _YuvDifference(sPixel a, sPixel b) {
	return (AbsDifference(a, b));
}

bool _IsEqual(sPixel a, sPixel b) {
	return (IsLike(a, b));
}

void _AlphaBlend32W(sPixel* dst, sPixel src, bool blend) {
	if (blend)
		*dst = Interpolate(*dst, src, 7, 1);
}

void _AlphaBlend64W(sPixel* dst, sPixel src, bool blend) {
	if (blend)
		*dst = Interpolate(*dst, src, 3, 1);
}

void _AlphaBlend128W(sPixel* dst, sPixel src, bool blend) {
	if (blend)
		*dst = Interpolate(*dst, src);
}

void _AlphaBlend192W(sPixel* dst, sPixel src, bool blend) {
	*dst = blend ? Interpolate(*dst, src, 1, 3) : src;
}

void _AlphaBlend224W(sPixel* dst, sPixel src, bool blend) {
	*dst = blend ? Interpolate(*dst, src, 1, 7) : src;
}

void _Left2_2X(sPixel* n3, sPixel* n2, sPixel pixel, bool blend) {
	_AlphaBlend192W(n3, pixel, blend);
	_AlphaBlend64W(n2, pixel, blend);
}
void _Up2_2X(sPixel* n3, sPixel* n1, sPixel pixel, bool blend) {
	_AlphaBlend192W(n3, pixel, blend);
	_AlphaBlend64W(n1, pixel, blend);
}

void _Dia_2X(sPixel* n3, sPixel pixel, bool blend) {
	_AlphaBlend128W(n3, pixel, blend);
}

#pragma region 2x
void _Kernel2Xv5(sPixel pe, sPixel pi, sPixel ph, sPixel pf, sPixel pg, sPixel pc, sPixel pd, sPixel pb, sPixel f4, sPixel i4, sPixel h5, sPixel i5, sPixel* n1, sPixel* n2, sPixel* n3, bool blend) {
	auto ex = (pe != ph && pe != pf);
	if (!ex)
		return;
	auto e = (_YuvDifference(pe, pc) + _YuvDifference(pe, pg) + _YuvDifference(pi, h5) + _YuvDifference(pi, f4)) + (_YuvDifference(ph, pf) << 2);
	auto i = (_YuvDifference(ph, pd) + _YuvDifference(ph, i5) + _YuvDifference(pf, i4) + _YuvDifference(pf, pb)) + (_YuvDifference(pe, pi) << 2);
	auto px = (_YuvDifference(pe, pf) <= _YuvDifference(pe, ph)) ? pf : ph;
	if ((e < i) && (!_IsEqual(pf, pb) && !_IsEqual(ph, pd) || _IsEqual(pe, pi) && (!_IsEqual(pf, i4) && !_IsEqual(ph, i5)) || _IsEqual(pe, pg) || _IsEqual(pe, pc))) {
		auto ke = _YuvDifference(pf, pg);
		auto ki = _YuvDifference(ph, pc);
		auto ex2 = (pe != pc && pb != pc);
		auto ex3 = (pe != pg && pd != pg);
		if (((ke << 1) <= ki) && ex3 || (ke >= (ki << 1)) && ex2) {
			if (((ke << 1) <= ki) && ex3)
				_Left2_2X(n3, n2, px, blend);
			if ((ke >= (ki << 1)) && ex2)
				_Up2_2X(n3, n1, px, blend);
		}
		else
			_Dia_2X(n3, px, blend);

	}
	else if (e <= i) {
		_AlphaBlend64W(n3, px, blend);
	}
}
#pragma endregion

#pragma region 3x
void _LeftUp2_3X(sPixel* n7, sPixel* n5, sPixel* n6, sPixel* n2, sPixel* n8, sPixel pixel, bool blend) {
	_AlphaBlend192W(n7, pixel, blend);
	_AlphaBlend64W(n6, pixel, blend);
	n5 = n7;
	n2 = n6;
	*n8 = pixel;
}

void _Left2_3X(sPixel* n7, sPixel* n5, sPixel* n6, sPixel* n8, sPixel pixel, bool blend) {
	_AlphaBlend192W(n7, pixel, blend);
	_AlphaBlend64W(n5, pixel, blend);
	_AlphaBlend64W(n6, pixel, blend);
	*n8 = pixel;
}

void _Up2_3X(sPixel* n5, sPixel* n7, sPixel* n2, sPixel* n8, sPixel pixel, bool blend) {
	_AlphaBlend192W(n5, pixel, blend);
	_AlphaBlend64W(n7, pixel, blend);
	_AlphaBlend64W(n2, pixel, blend);
	*n8 = pixel;
}

void _Dia_3X(sPixel* n8, sPixel* n5, sPixel* n7, sPixel pixel, bool blend) {
	_AlphaBlend224W(n8, pixel, blend);
	_AlphaBlend32W(n5, pixel, blend);
	_AlphaBlend32W(n7, pixel, blend);
}

void _Kernel3X(sPixel pe, sPixel pi, sPixel ph, sPixel pf, sPixel pg, sPixel pc, sPixel pd, sPixel pb, sPixel f4, sPixel i4, sPixel h5, sPixel i5, sPixel* n2, sPixel* n5, sPixel* n6, sPixel* n7, sPixel* n8, bool blend, bool useOriginalImplementation) {
	auto ex = (pe != ph && pe != pf);
	if (!ex)
		return;

	auto e = (_YuvDifference(pe, pc) + _YuvDifference(pe, pg) + _YuvDifference(pi, h5) + _YuvDifference(pi, f4)) + (_YuvDifference(ph, pf) << 2);
	auto i = (_YuvDifference(ph, pd) + _YuvDifference(ph, i5) + _YuvDifference(pf, i4) + _YuvDifference(pf, pb)) + (_YuvDifference(pe, pi) << 2);

	bool state;
	if (useOriginalImplementation)
		state = ((e < i) && (!_IsEqual(pf, pb) && !_IsEqual(ph, pd) || _IsEqual(pe, pi) && (!_IsEqual(pf, i4) && !_IsEqual(ph, i5)) || _IsEqual(pe, pg) || _IsEqual(pe, pc)));
	else
		state = ((e < i) && (!_IsEqual(pf, pb) && !_IsEqual(pf, pc) || !_IsEqual(ph, pd) && !_IsEqual(ph, pg) || _IsEqual(pe, pi) && (!_IsEqual(pf, f4) && !_IsEqual(pf, i4) || !_IsEqual(ph, h5) && !_IsEqual(ph, i5)) || _IsEqual(pe, pg) || _IsEqual(pe, pc)));

	if (state) {
		auto ke = _YuvDifference(pf, pg);
		auto ki = _YuvDifference(ph, pc);
		auto ex2 = (pe != pc && pb != pc);
		auto ex3 = (pe != pg && pd != pg);
		auto px = (_YuvDifference(pe, pf) <= _YuvDifference(pe, ph)) ? pf : ph;
		if (((ke << 1) <= ki) && ex3 && (ke >= (ki << 1)) && ex2) {
			_LeftUp2_3X(n7, n5, n6, n2, n8, px, blend);
		}
		else if (((ke << 1) <= ki) && ex3) {
			_Left2_3X(n7, n5, n6, n8, px, blend);
		}
		else if ((ke >= (ki << 1)) && ex2) {
			_Up2_3X(n5, n7, n2, n8, px, blend);
		}
		else {
			_Dia_3X(n8, n5, n7, px, blend);
		}
	}
	else if (e <= i) {
		_AlphaBlend128W(n8, ((_YuvDifference(pe, pf) <= _YuvDifference(pe, ph)) ? pf : ph), blend);
	}
}
#pragma endregion

#pragma region 4x
void _LeftUp2(sPixel* n15, sPixel* n14, sPixel* n11, sPixel* n13, sPixel* n12, sPixel* n10, sPixel* n7, sPixel* n3, sPixel pixel, bool blend) {
	_AlphaBlend192W(n13, pixel, blend);
	_AlphaBlend64W(n12, pixel, blend);
	*n15 = *n14 = *n11 = pixel;
	n10 = n3 = n12;
	n7 = n13;
}

void _Left2(sPixel* n15, sPixel* n14, sPixel* n11, sPixel* n13, sPixel* n12, sPixel* n10, sPixel pixel, bool blend) {
	_AlphaBlend192W(n11, pixel, blend);
	_AlphaBlend192W(n13, pixel, blend);
	_AlphaBlend64W(n10, pixel, blend);
	_AlphaBlend64W(n12, pixel, blend);
	*n14 = pixel;
	*n15 = pixel;
}

void _Up2(sPixel* n15, sPixel* n14, sPixel* n11, sPixel* n3, sPixel* n7, sPixel* n10, sPixel pixel, bool blend) {
	_AlphaBlend192W(n14, pixel, blend);
	_AlphaBlend192W(n7, pixel, blend);
	_AlphaBlend64W(n10, pixel, blend);
	_AlphaBlend64W(n3, pixel, blend);
	*n11 = pixel;
	*n15 = pixel;
}

void _Dia(sPixel* n15, sPixel* n14, sPixel* n11, sPixel pixel, bool blend) {
	_AlphaBlend128W(n11, pixel, blend);
	_AlphaBlend128W(n14, pixel, blend);
	*n15 = pixel;
}

void _Kernel4Xv2(sPixel pe, sPixel pi, sPixel ph, sPixel pf, sPixel pg, sPixel pc, sPixel pd, sPixel pb, sPixel f4, sPixel i4, sPixel h5, sPixel i5, sPixel* n15, sPixel* n14, sPixel* n11, sPixel* n3, sPixel* n7, sPixel* n10, sPixel* n13, sPixel* n12, bool blend) {
	auto ex = (pe != ph && pe != pf);
	if (!ex)
		return;
	auto e = (_YuvDifference(pe, pc) + _YuvDifference(pe, pg) + _YuvDifference(pi, h5) + _YuvDifference(pi, f4)) + (_YuvDifference(ph, pf) << 2);
	auto i = (_YuvDifference(ph, pd) + _YuvDifference(ph, i5) + _YuvDifference(pf, i4) + _YuvDifference(pf, pb)) + (_YuvDifference(pe, pi) << 2);
	auto px = (_YuvDifference(pe, pf) <= _YuvDifference(pe, ph)) ? pf : ph;
	if ((e < i) && (!_IsEqual(pf, pb) && !_IsEqual(ph, pd) || _IsEqual(pe, pi) && (!_IsEqual(pf, i4) && !_IsEqual(ph, i5)) || _IsEqual(pe, pg) || _IsEqual(pe, pc))) {
		auto ke = _YuvDifference(pf, pg);
		auto ki = _YuvDifference(ph, pc);
		auto ex2 = (pe != pc && pb != pc);
		auto ex3 = (pe != pg && pd != pg);
		if (((ke << 1) <= ki) && ex3 || (ke >= (ki << 1)) && ex2) {
			if (((ke << 1) <= ki) && ex3)
				_Left2(n15, n14, n11, n13, n12, n10, px, blend);
			if ((ke >= (ki << 1)) && ex2)
				_Up2(n15, n14, n11, n3, n7, n10, px, blend);
		}
		else
			_Dia(n15, n14, n11, px, blend);

	}
	else if (e <= i) {
		_AlphaBlend128W(n15, px, blend);
	}
}
#pragma endregion