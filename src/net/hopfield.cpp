/*
 * hopfield.cpp
 *
 * Author: Gilang Satria Prayoga
 */

#include <iostream>
#include <cassert>
#include "hopfield.h"

using namespace std;

const int DefaultSize=4;

HopfieldNetwork::HopfieldNetwork():size(DefaultSize) {
}

HopfieldNetwork::HopfieldNetwork(const int & size):size(size){}

bool * HopfieldNetwork::output(bool * input)const{
	if(weightMatrix.getRow()==1 && weightMatrix.getColumn()==1){
		return NULL;
	}else{
		bool * output=new bool[size];
		Matrix minput=Matrix::createRowMatrix(size);
		for(int i=0;i<minput.getColumn();i++){
				minput.setAt(0,i,BooleanUtil::fromBoolean(input[i]));
		}

		for(int i=0;i<size;i++){
			Matrix colMatrix=weightMatrix.rowMatrix(i);
			colMatrix=colMatrix.transpose();
			double dotp=minput.dot(colMatrix);
			if(dotp>0){
				output[i]=true;
			}else{
				output[i]=false;
			}
		}
		return output;
	}
}

void HopfieldNetwork::train(bool * pattern){
	assert(pattern);
	Matrix minput=Matrix::createRowMatrix(size);
	for(int i=0;i<minput.getColumn();i++){
		minput.setAt(0,i,BooleanUtil::fromBoolean(pattern[i]));
	}
	Matrix tminput=minput.transpose();
	weightMatrix=tminput*minput;
	weightMatrix.nwDiag();
}

HopfieldNetwork::~HopfieldNetwork() {

}

