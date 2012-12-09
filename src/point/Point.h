/*
 * Point.h
 * GILANG SATRIA PRAYOGA 23512153
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;

class Point {
protected:
	int *P;
	string color;
public:
	/**
	 * GOF
	 */
	Point();
	Point(int,int,string);
	Point(const Point &p);
	Point & operator=(const Point &p);

	/**
	 * setter and getter
	 */
	void SetX(int x);
	void SetY(int y);
	void SetColor(string color);
	int GetX()const;
	int GetY()const;
	string GetColor()const;

	/**
	 * return string representation of Point object
	 */
	string PointToString()const;

	/**
	 * operator overloads
	 */
	bool operator==(const Point &);
	friend Point operator+(const Point &,const Point &);

	~Point();
};

#endif /* POINT_H_ */
