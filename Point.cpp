#include "Point.h"
#include<cmath>

#define FLT_EPSILON 1.19209290E-07F


Point::Point() : x(.0), y(.0) { }

Point::Point(double x0, double y0) :x(x0), y(y0) { }

Point::Point(const Point & B) : x(B.x), y(B.y) { }


void Point::setValue(const double& x0, const double& y0)
{
	x = x0; y = y0;
}

Point::~Point()
{
}

Point& Point::operator=(const Point & B)
{
	setValue(B.x1(), B.y1());
	return *this;
}

bool Point::operator==(const Point & B) const
{
	return (x == B.x1() && y == B.y1());
}

//	compares by y then by x
bool Point::operator>(const Point & B) const
{
	return (y > B.y1() + FLT_EPSILON || (y == B.y1() && x > B.x1() + FLT_EPSILON));
}

bool Point::operator<(const Point & B) const
{
	return (y + FLT_EPSILON < B.y1() || (y == B.y1() && x + FLT_EPSILON < B.x1()));
}

bool Point::operator>=(const Point & B) const
{
	return (*this > B) || (*this == B);
}

bool Point::operator<=(const Point & B) const
{
	return (*this < B) || (*this == B);
}

ostream & operator<<(ostream & output, Point & z)
{
	output << "(" << z.x << ", " << z.y << ")";
	return output;
}

istream & operator >> (istream & input, Point & z)
{
	input >> z.x >> z.y;
	return input;
}

Point Point::operator+(const Point & B)
{
	return{ x + B.x1(), y + B.y1() };
}

Point Point::operator+=(const Point & B)
{
	return *this + B;
}

Point Point::operator-(const Point & B)
{
	return Point(x - B.x1(), y - B.y1());
}

Point Point::operator-=(const Point & B)
{
	return *this - B;
}

Point Point::operator*(const Point & B)
{
	return Point(x * B.x1(), y * B.y1());
}

Point Point::operator*=(const Point & B)
{
	return (*this) * B;
}

double 
inline Point::distance(const Point & B) const
{
	return sqrt((x - B.x1())*(x - B.x1()) + (y - B.y1())*(y - B.y1()));
}

void Point::clean()
{
	x = 0.0; y = 0.0;
}

