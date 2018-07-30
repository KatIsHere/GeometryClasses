#include "HorizontalLine.h"




HorizontalLine::HorizontalLine()
{
	y = 0;
}

HorizontalLine::~HorizontalLine()
{
}

void HorizontalLine::setHorizontal(double y0)
{
	y = y0;
}

double HorizontalLine::getHorizontal() const
{
	return y;
}

bool HorizontalLine::above(const Point & h)
{
	return y < h.y1();
}

bool HorizontalLine::y_above(const double & t)
{
	return t > y;
}

bool HorizontalLine::hasPoint(const Point & A)
{
	return y == A.y1();
}
