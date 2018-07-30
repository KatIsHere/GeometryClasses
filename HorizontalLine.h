#pragma once
#include "Line.h"
class HorizontalLine :
	public Line
{
public:
	HorizontalLine();
	HorizontalLine(double y0): y(y0){}
	~HorizontalLine();
	void setHorizontal(double y0);
	double getHorizontal() const;
	bool above(const Point &h);
	bool y_above(const double & t);
	virtual bool hasPoint(const Point& A);
	
private:
	double y;
};

