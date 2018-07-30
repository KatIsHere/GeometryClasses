#pragma once
#include "Point.h"
#include <iostream>
class Parabola
{
public:
	Parabola(Point& start, double L);	//	L - sweep line
	Parabola();
	Parabola(double a0, double b0, double c0);
	void setParabola(double a0, double b0, double c0);
	double y(double x);
	double get_a() const;
	double get_b() const; // b()
	double get_c() const;
	Point focus() const ;
	void setFocusDirectrix(const Point& start, double L);

	bool intersect(const Parabola& P, Point& x1, Point& x2);
	~Parabola();

	friend ostream& operator<<(ostream& output, Parabola P);
	friend istream& operator>> (istream& input, Parabola P);
protected:
	double a, b, c;		// y = a*x*x + b*x + c - parabola
	Point Focus;
};

