#pragma once
#include <iostream>
using namespace std;
class Point
{
public:
	Point();
	Point(double x0, double y0);
	void setValue(const double& x0, const double& y0);
	Point(const Point& B);
	inline const double& x1() const { return x; }
	inline const double& y1() const { return y; }
	~Point();

	//	Operators
	Point& operator=(const Point& B);
	//Point& operator=( Point&& B);


	bool operator==(const Point& B) const;
	bool operator>(const Point& B) const;
	bool operator<(const Point& B) const;
	bool operator>=(const Point& B) const;
	bool operator<=(const Point& B) const;
	
	friend ostream& operator<<(ostream& r, Point & z);
	friend istream& operator>> (istream& r, Point & z);

	Point operator+(const Point& B);
	Point operator+=(const Point& B);
	Point operator-(const Point& B);
	Point operator-=(const Point& B);
	Point operator*(const Point& B);
	Point operator*=(const Point& B);

	double distance(const Point& B) const;
	void clean();
private:
	double x, y;
};

