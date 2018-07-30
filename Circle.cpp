#include "Circle.h"
#include "Segment.h"
#include "Line.h"
#include <cmath>
#define FLT_EPSILON 1.19209290E-07F
#define M_PI 3.14159265358979323846
using namespace std;

Circle::Circle(double r, Point center)
{
	setCircle(r, center);
}

Circle::Circle(Point A0, Point B0, Point C0)
{
	Segment t1 = Segment(A0, B0), t2 = Segment(B0, C0);
	Line ab = t1.MiddlePerpendicular();
	Line bc = t2.MiddlePerpendicular();
	/*
	cout << A0 << "\t" << B0 << endl;
	cout << t1 << endl;
	cout << "ab : " << ab << endl;
	cout << B0 << "\t" << C0 << endl;
	cout << t2 << endl;
	cout << "cb : " << bc << endl;
	*/
	Point o;
	if (ab.crossing(bc, o) == 0) R = 0;
	O = o;
	R = O.distance(A0);
}

Circle::Circle()
{
	R = 0;
}

void Circle::setCircle(double r, Point center)
{
	R = r;
	O = center;
}

void Circle::clear()
{
	O.clean();
	R = 0;
}

bool Circle::has_point(const Point & P)
{
	return (abs((P.x1() - O.x1())*(P.x1() - O.x1()) + (P.y1() - O.y1())*(P.y1() - O.y1()) - R*R) < FLT_EPSILON);
}

double Circle::C_area()
{
	return M_PI * R * R;
}

double Circle::C_lenght()
{
	return 2 * M_PI * R;
}

Point Circle::get_center() const
{
	return O;
}

double Circle::get_radius() const
{
	return R;
}


Circle::~Circle()
{
}

ostream & operator<<(ostream & output, Circle & C)
{
	output << "(x - " << C.O.x1() << ") + (y - " << C.O.y1() << ") = " << C.R * C.R;
	return output;
}
