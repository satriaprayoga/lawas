/*
 * StackPoint.h
 * GILANG SATRIA PRAYOGA 23512153
 */

#ifndef STACKPOINT_H_
#define STACKPOINT_H_

#include <iostream>
#include "Point.h"

using namespace std;

/**
 * Stack of Point object
 */
class StackPoint {
protected:
	Point *P;
	int top;
	int size;
public:
	/**
	 * GOF
	 */
	StackPoint();
	StackPoint(int s);
	StackPoint(const StackPoint &S);
	StackPoint & operator=(const StackPoint &S);

	/**
	 * push operation. push Point p to the top
	 */
	void Push(Point p);
	/**
	 * return Point from the top of the stack
	 */
	Point Pop();

	/**
	 * return true if top==0, false otherwise
	 */
	bool IsEmpty() const;
	/**
	 * return true if top==size, false otherwise
	 */
	bool IsFull() const;
	~StackPoint();
};

#endif /* STACKPOINT_H_ */
