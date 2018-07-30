#pragma once
#include "Point.h"
#include <iostream>
#include "Circle.h"
class Line
{
public:
	Line();
	~Line();
	Line(const Line& L);
	Line(Point X0, Point Y0);
	Line(double A0, double B0, double C0);
	Line & operator=(const Line& L);
	bool parallel(const Line& L);
	bool operator==(const Line& L);
	virtual bool perpendicular(const Line& L);
	virtual bool hasPoint(const Point& A);
	virtual bool crossing(const Line & L, Point& intersect);
	virtual void setPoints(Point A, Point B);
	virtual bool CircleCross(const Circle& C, Point& x1, Point& x2);
	void setLine(double A0, double B0, double C0);
	
	double getA() const;
	double getB() const;
	double getC() const;

	virtual void clear();
	double Angle(const Line& L);
	double distancePoint(const Point & Z);

	friend ostream& operator<<(ostream& output, Line L);
private:
	double A, B, C;	// Ax + By + C = 0
};

