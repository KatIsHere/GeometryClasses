#pragma once
#include "Point.h"
class Circle
{
public:
	Circle(double r, Point center);
	Circle(Point A0, Point B0, Point C0);
	Circle();
	void setCircle(double r, Point center);
	void clear();
	bool has_point(const Point& P);
	double C_area();
	double C_lenght();
	Point get_center() const;
	double get_radius() const;
	~Circle();

	friend ostream& operator<<(ostream& output, Circle& S);
private:
	double R;
	Point O;
};

