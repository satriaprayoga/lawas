/*
 * boolean-util.h
 *
 * Author: Gilang Satria Prayoga
 */

#ifndef BOOLEAN_UTIL_H_
#define BOOLEAN_UTIL_H_

#include "matrix.h"

class BooleanUtil{
private:
	BooleanUtil(){}
public:
	static double fromBoolean(const bool & b);
	static bool fromDouble(const double & d);
	static bool ** fromMatrix(const Matrix & m);
	static Matrix fromBoolean(bool ** b,int r,int c);
	~BooleanUtil(){}
};


#endif /* BOOLEAN_UTIL_H_ */
