#include "Segment.h"

#define FLT_EPSILON 1.19209290E-07F


Segment::Segment()
{
}

Segment::Segment(Point A0, Point B0)
{
	A = A0;
	B = B0;
}


Segment::~Segment()
{
}

bool Segment::perpendicular(const Segment& S)
{
	Point X(0., 0.);
	if (!crossing(S, X)) return false;
	else
		return (abs(A.distance(X)*A.distance(X) + X.distance(S.getX())*X.distance(S.getX()) 
			- A.distance(S.getX())*A.distance(S.getX())) < FLT_EPSILON);
}

bool Segment::hasPoint(const Point & X0)
{
	return (abs(A.distance(X0) + B.distance(X0) - S_length()) < FLT_EPSILON);
}

bool Segment::crossing(Segment L, Point & intersect)
{
	if (!(Line::Line(A, B).crossing(Line(L.getX(), L.getY()), intersect))) { intersect.clean(); return false; }	//	lines don't cross
	else {
		bool flag1, flag2;
		flag1 = hasPoint(intersect);
		flag2 = L.hasPoint(intersect);
		if (!(flag1 && flag2)) intersect.clean();
		return (flag1 && flag2);
	}
}

void Segment::setPoints(Point A0, Point B0)
{
	A = A0; B = B0;
}

bool Segment::CircleCross(const Circle & C, Point & x1, Point & x2)
{
	Line L(A, B);
	bool flag = L.CircleCross(C, x1, x2);
	if (flag) {
		bool flag1 = hasPoint(x1), flag2 = hasPoint(x2);
		if (!flag1 && !flag2) { 
			flag = false; 
			x1.clean(); x2.clean();
		}
		else if (!flag1 && flag2) x1 = x2;
		else if (flag1 && !flag2) x2 = x1;
	}
	return flag;
}

Segment Segment::operator=(const Segment & S)
{
	return Segment(S.getX(), S.getY());
}

Point Segment::middle() const
{
	return Point((A.x1() + B.x1()) / 2, (A.y1() + B.y1()) / 2);
}

Point Segment::getX() const
{
	return A;
}

Point Segment::getY() const
{
	return B;
}

void Segment::clear()
{
	A.clean(); B.clean();
}

double Segment::S_length()
{
	return A.distance(B);
}

Line Segment::MiddlePerpendicular()
{
	Point M = middle();
	if (A.x1() == B.x1())
		return Line(1., 0., (-1) * M.x1());
	if (A.y1() == B.y1())
		return Line(0., 1., (-1) * M.y1());
	Line a0 = Line(A, B), a1 = Line(A, B);
	double b = a0.getB(), a = a1.getA();
	double k = (b / a);
	double B = 1., A = (-1) * k, C;
	C = k*M.x1() - M.y1();
	return Line(A, B, C);
}

//Segment Segment::normal(Point r)
//{
//	double D, E, F;
//	double A = (*this).getA(), B = (*this).getB(), C = (*this).getC();
//	D = l.getX.x1() - l.getY.x1();
//	E = l.getX.y1() - l.getY.y1();
//	F = r.x1() * (-D) + r.y1()*(-E);
//	double p1, p2;
//	p2 = (C*D - F*A) / (E*A - D*B);
//	p1 = -(C + B*p2) / A;
//	Point p(p1, p2);
//	return Segment(p, r);
//}


ostream & operator<<(ostream & output, Segment & S)
{
	output << "[" << S.A << "; " << S.B << "]";
	return output;
}
