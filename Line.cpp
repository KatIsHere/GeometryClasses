#include "Line.h"
#include <cmath>
using namespace std;
#define FLT_EPSILON 1.19209290E-07F

Line::Line()
{
}


Line::~Line()
{
}

Line::Line(const Line & L)
{
	setLine(L.getA(), L.getB(), L.getC());
}

Line::Line(Point X0, Point Y0)
{
	setPoints(X0, Y0);
}

Line::Line(double A0, double B0, double C0): A(A0), B(B0), C(C0)
{
}

Line & Line::operator=(const Line & L)
{
	setLine(L.getA(), L.getB(), L.getC());
	return *this;
}


bool Line::parallel(const Line & L)
{
	return (A / L.getA() == B / L.getB());
}

bool Line::operator==(const Line & L)
{
	return (A == L.getA() && B == L.getB() && C == L.getC());
}

bool Line::perpendicular(const Line & L)
{
	return (A * L.getA() + B* L.getB() == 0);
}

bool Line::hasPoint(const Point & A)
{
	return (distancePoint(A) < FLT_EPSILON);
}


bool Line::crossing(const Line & L, Point& intersect)
{
	if (parallel(L)) return false;
	double x, y;
	x = -((C*L.getB() - L.getC() * B) / (A*L.getB() - L.getA() * B));
	y = -((A*L.getC() - L.getA() * C) / (A*L.getB() - L.getA() * B));
	intersect.setValue(x, y);
	return true;
}

void Line::setPoints(Point A0, Point B0)
{
	if (A0.x1() == B0.x1()) {
		A = 1; B = 0; C = (-1) * A0.x1();
	}
	else if (A0.y1() == B0.y1()) {
		A = 0; B = 1; C = (-1)*A0.y1();

	}
	else {
		A = (B0.y1() - A0.y1());
		B = (A0.x1() - B0.x1());
		C = (A0.y1() * B0.x1() - A0.x1() * B0.y1());
	}
}

bool Line::CircleCross(const Circle & C0, Point & x1, Point & x2)
	//	ax + by + z == 0
	//	(x - x0)^2 + (y - y0)^2 == r^2
{
	bool flag = true;
	if (distancePoint(C0.get_center()) > C0.get_radius()) flag = false;
	if (flag) {
		double a, b, c;
		a = 1 + (A / B)*(A / B);
		b = (2 * A*C) / (B*B) - 2 * C0.get_center().x1() + 2 * C0.get_center().y1()*(A / B);
		c = C0.get_center().x1()*C0.get_center().x1() + (C / B)*(C / B) + 2 * C0.get_center().y1()*(C / B) +
			C0.get_center().y1()*C0.get_center().y1() - C0.get_radius()*C0.get_radius();
		double D;
		D = b*b - 4 * a*c;
		if (D < 0) flag = false;
		if (flag) {
			double X1, X2, Y1, Y2;
			X1 = ((-1)*b + sqrt(D)) / (2 * a);
			X2 = ((-1)*b - sqrt(D)) / (2 * a);
			Y1 = (-1)*(A / B) * X1 - C / B;
			Y2 = (-1)*(A / B) * X2 - C / B;
			x1.setValue(X1, Y1); x2.setValue(X2, Y2);
		}
		else {
			x1.clean(); x2.clean();
		}
	}
	else {
		x1.clean(); x2.clean();
	}
	return flag;
}

void Line::setLine(double A0, double B0, double C0)
{
	A = A0; B = B0; C = C0;
}

double Line::getA() const
{
	return A;
}

double Line::getB() const
{
	return B;
}

double Line::getC() const
{
	return C;
}



void Line::clear()
{
	A = 0; B = 0; C = 0;
}

double Line::Angle(const Line & L)
{
	return acos((A*L.getA() + B*L.getB()) / (sqrt(A*A + B*B)*sqrt(L.getA()*L.getA() + L.getB()*L.getB())));
}

double Line::distancePoint(const Point & Z)
{
	return (abs(A*Z.x1() + B*Z.y1() + C) / sqrt(A*A + B*B));
}

ostream & operator<<(ostream & output, Line L)
{
	output << "(" << L.A << ")*x + (" << L.B << ")*y + (" << L.C << ") = 0";
	return output;
}
