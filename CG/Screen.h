#pragma once

#include "Point.h"

struct Screen : public Point {

	inline Screen() = default;
	inline Screen(Point p) : Point(p) {}
	inline Screen(int x, int y) : Point(x, y) {}
	inline const int &operator[](const short i) const { return (&x)[i]; }
	inline int &operator[](const short i) { return (&x)[i]; }
	inline friend Screen operator+(const Screen &lhs, const Screen &rhs) { return Screen(lhs.x + rhs.x, lhs.y + rhs.y); }
	inline friend Screen operator-(const Screen &lhs, const Screen &rhs) { return Screen(lhs.x - rhs.x, lhs.y - rhs.y); }

	inline Point mid_point() const { return Screen(x / 2, y / 2); }
	inline int mid_x_int() const { return x / 2; }
	inline int mid_y_int() const { return y / 2; }
	inline double mid_x_double() const { return x / 2.0; }
	inline double mid_y_double() const { return y / 2.0; }
	inline double aspect_ratio() const { return (double)x / (double)y; }
};