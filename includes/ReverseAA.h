#pragma once

int clamp(int v, int min, int max) {
	return (v < min ? min : v > max ? max : v);
}

unsigned char _FullClamp(int value) {
	return (unsigned char)(value > 255 ? 255 : value < 0 ? 0 : (unsigned char)value);
}

void _ReverseAntiAlias(int b1, int b, int d, int e, int f, int h, int h5, int d0, int f4, int *rd, int *gn, int *bl, int *alpha) {

	auto n1 = b1;
	auto n2 = b;
	auto s = e;
	auto n3 = h;
	auto n4 = h5;
	auto aa = n2 - n1;
	auto bb = s - n2;
	auto cc = n3 - s;
	auto dd = n4 - n3;

	auto tilt = (7 * (bb + cc) - 3 * (aa + dd)) / 16;

	auto m = (s < 128) ? 2 * s : 2 * (255 - s);

	m = min(m, 2 * abs(bb));
	m = min(m, 2 * abs(cc));

	tilt = clamp(tilt, -m, m);

	auto s1 = s + tilt / 2;
	auto s0 = s1 - tilt;

	n1 = d0;
	n2 = d;
	s = s0;
	n3 = f;
	n4 = f4;
	aa = n2 - n1;
	bb = s - n2;
	cc = n3 - s;
	dd = n4 - n3;

	tilt = (7 * (bb + cc) - 3 * (aa + dd)) / 16;

	m = (s < 128) ? 2 * s : 2 * (255 - s);

	m = min(m, 2 * abs(bb));
	m = min(m, 2 * abs(cc));

	tilt = clamp(tilt, -m, m);

	auto e1 = s + tilt / 2;
	auto e0 = e1 - tilt;

	s = s1;
	bb = s - n2;
	cc = n3 - s;

	tilt = (7 * (bb + cc) - 3 * (aa + dd)) / 16;

	m = (s < 128) ? 2 * s : 2 * (255 - s);

	m = min(m, 2 * abs(bb));
	m = min(m, 2 * abs(cc));

	tilt = clamp(tilt, -m, m);

	auto e3 = s + tilt / 2;
	auto e2 = e3 - tilt;

	*rd = e0;
	*gn = e1;
	*bl = e2;
	*alpha = e3;
}