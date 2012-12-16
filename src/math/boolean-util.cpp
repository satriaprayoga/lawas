/*
 * boolean-util.cpp
 *
 * Author: Gilang Satria Prayoga
 */


#include "boolean-util.h"

double BooleanUtil::fromBoolean(const bool & b){
	if(b){
		return 1.0;
	}else{
		return -1.0;
	}
}

bool BooleanUtil::fromDouble(const double & d){
	if(d<0){
		return false;
	}else{
		return true;
	}
}

bool ** BooleanUtil::fromMatrix(const Matrix & m){
	bool **output=new bool*[m.getRow()];
	for(int i=0;i<m.getRow();i++){
		output[i]=new bool[m.getColumn()];
	}
	for(int i=0;i<m.getRow();i++){
		for(int j=0;j<m.getColumn();j++){
			output[i][j]=fromDouble(m.getAt(i,j));
		}
	}

	return output;
}

Matrix BooleanUtil::fromBoolean(bool ** b,int r,int c){
	Matrix output(r,c);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<b[i][j]<<endl;
			output.setAt(i,j,fromBoolean(b[i][j]));
		}
	}
	return output;
}
