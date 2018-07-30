#include "Parabola.h"


//	parabola with focus and directrix
Parabola::Parabola(Point & focus0, double L)
{
	//	y = a*(x - h)^2 + k
	//	vertex - V(h, k)
	//	p = 1/(4*a)
	//	focus - F(h, k+p)
	setFocusDirectrix(focus0, L);
}

Parabola::Parabola()
{
	setParabola(0., 0., 0.);
}

Parabola::Parabola(double a0, double b0, double c0)
{
	setParabola(a0, b0, c0);
}

void Parabola::setParabola(double a0, double b0, double c0)
{
	a = a0;
	b = b0;
	c = c0;
	//center.setValue(-(b0 / (2 * a0)), (c0 - b*b / (4 * a)));
}

double Parabola::y(double x)
{
	return a*x*x + b*x + c;
}

double Parabola::get_a() const
{
	return a;
}

double Parabola::get_b() const
{
	return b;
}

double Parabola::get_c() const
{
	return c;
}

Point Parabola::focus() const
{
	return Focus;
}

void Parabola::setFocusDirectrix(const Point & focus0, double L)
{
	Focus = focus0;
	double y = (focus0.y1() - L) / 2;
	a = 1 / (4 * focus0.y1() - 4 * y);
	b = -2 * a*focus0.x1();
	c = y - 1 / (4 * a) + b*b / (4 * a);

}



bool Parabola::intersect(const Parabola & P, Point & x1, Point & x2)
{
	double x0, y0, x3, y3;
	double D;
	bool flag = true;
	if (a == P.get_a() && b == P.get_b() && !(c == P.get_c())) return false;
	D = (b - P.get_b())*(b - P.get_b()) - 4 * (c - P.get_c())*(a - P.get_a());
	if (D < 0) flag = false;
	else {
		x0 = ((P.get_b() - b) - sqrt(D)) / (2 * (a - P.get_a()));
		y0 = y(x0);
		x3 = ((P.get_b() - b) + sqrt(D)) / (2 * (a - P.get_a()));
		y3 = y(x3);
		x1.setValue(x0, y0);
		x2.setValue(x3, y3);
	}
	return flag;
}

Parabola::~Parabola()
{
}

ostream & operator<<(ostream & output, Parabola P)
{
	output << "y = " << P.a << "*x*x + " << P.b << "*x + " << P.c;
	return output;
}


istream & operator >> (istream & input, Parabola P)
{
	double a0, b0, c0;
	input.ignore(1);

	input >> a0;
	input.ignore(1);
	input >> b0;
	input.ignore(1);
	input >> c0;
	input.ignore(1);
	P.setParabola(a0, b0, c0);
	return input;
}
