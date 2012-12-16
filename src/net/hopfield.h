/*
 * hopfield.h
 *
 * Author: Gilang Satria Prayoga
 */

#ifndef HOPFIELD_H_
#define HOPFIELD_H_

#include "../math/math.h"

class HopfieldNetwork {
private:
	int size;
	Matrix weightMatrix;
public:
	HopfieldNetwork();
	HopfieldNetwork(const int & size);

	void setSize(const int & size);
	void setWeightMatrix(const Matrix & wm);

	int getSize()const{return size;}
	Matrix getWeightMatrix()const{return weightMatrix;}
	bool * output(bool * input)const;
	void train(bool * pattern);
	~HopfieldNetwork();
};

#endif /* HOPFIELD_H_ */
