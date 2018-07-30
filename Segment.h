#include "Line.h"
#include <iostream>
class Segment :
	public Line
{
public:
	Segment();
	Segment(Point A0, Point B0);
	~Segment();

	virtual bool perpendicular(const Segment& L);
	virtual bool hasPoint(const Point& A);
	virtual bool crossing(Segment L, Point& intersect);
	virtual void setPoints(Point A, Point B);
	virtual bool CircleCross(const Circle& C, Point& x1, Point& x2);
	Segment operator=(const Segment& S);

	Point middle() const;
	Point getX() const;
	Point getY() const;
	virtual void clear();
	double S_length();
	
	friend ostream& operator<<(ostream& output, Segment& S);
	Line MiddlePerpendicular();

	//Segment normal(Point r);
private:
	Point A, B;
};
