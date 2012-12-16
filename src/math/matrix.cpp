/*
 * Matrix.cpp
 *
 * Author: Gilang Satria Prayoga
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#include "matrix.h"

using namespace std;

void Matrix::_initialize(const int & r,const int & c){
	assert(r>=1 && c>=1);
	row=r;
	column=c;
	data=new double*[row];
	assert(data);
	for(int i=0;i<row;i++){
		data[i]=new double[column];
		assert(data[i]);
	}
}

void Matrix::_destroy(){
	if(data){
		for(int i=0;i<row;i++){
			delete [] data[i];
		}
		delete [] data;
		row=0;
		column=0;
	}
}

Matrix::Matrix() {
	_initialize(1,1);
}

Matrix::Matrix(const int & r,const int & c){
	_initialize(r,c);
}

Matrix::Matrix(const Matrix & m){
	_initialize(m.row,m.column);
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			setAt(i,j,m.getAt(i,j));
		}
	}
}

Matrix Matrix::createRowMatrix(const int & c){
	return Matrix(1,c);
}

Matrix Matrix::createColumnMatrix(const int & r){
	return Matrix(r,1);
}

Matrix Matrix::createIdentityMatrix(const int & r,const int & c,const double & v){
	Matrix m(r,c);
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			if(i==j)
				m.setAt(i,j,v);
			else
				m.setAt(i,j,0);
		}
	}
	return m;
}

Matrix & Matrix::operator =(const Matrix & m){
	_destroy();
	_initialize(m.row,m.column);
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			setAt(i,j,m.getAt(i,j));
		}
	}
	return *this;
}

double * Matrix::operator [](const int & idx)const{
	assert(_isValidRow(idx));
	return data[idx];
}

double & Matrix::getAt(const int & i,const int & j)const{
	assert(isValidIndex(i,j));
	return data[i][j];
}

void Matrix::setAt(const int & i,const int & j,const double & v){
	assert(isValidIndex(i,j));
	data[i][j]=v;
}

Matrix Matrix::transpose()const{
	Matrix t(column,row);
	for(int i=0;i<t.row;i++){
		for(int j=0;j<t.column;j++){
			t.setAt(i,j,getAt(j,i));
		}
	}
	return t;
}

Matrix Matrix::rowMatrix(const int & idx)const{
	assert(_isValidRow(idx));
	Matrix c=createRowMatrix(row);
	for(int i=0;i<c.column;i++){
		c.setAt(0,i,getAt(idx,i));
	}

	return c;
}

Matrix Matrix::columnMatrix(const int & idx)const{
	assert(_isValidColumn(idx));
	Matrix c=createColumnMatrix(column);
	for(int i=0;i<c.row;i++){
		c.setAt(i,0,getAt(i,idx));
	}

	return c;
}

double Matrix::vectorlength()const{
	assert(isVector());
	double sum=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			sum+=pow(data[i][j],2);
		}
	}
	return sqrt(sum);
}

void Matrix::nwDiag(const double & v){
	for(int i=0;i<row;i++){
		for(int j=0;j<row;j++){
			if(i==j)
				setAt(i,j,v);
		}
	}
}

double Matrix::dot(const Matrix & m){
	//double d=0;
	assert(isVector() && m.isVector() && isInverseIndex(m));
	return ((*this)*(m)).getAt(0,0);
}

bool Matrix::isVector()const{
	return (row==1 || column==1);
}

bool Matrix::isValidIndex(const int & r,const int & c)const{
	return ((r>=0 && r<row) && (c>=0 && c<column));
}

bool Matrix::isEqualIndex(const Matrix & m)const{
	return (row==m.row && column==m.column);
}

bool Matrix::isInverseIndex(const Matrix & m)const{
	return (row==m.column);
}

Matrix operator+(const Matrix & m1,const Matrix & m2){
	assert(m1.isEqualIndex(m2));
	Matrix m(m1.row,m1.column);
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			m.setAt(i,j,(m1.getAt(i,j)+m2.getAt(i,j)));
		}
	}
	return m;
}

Matrix operator-(const Matrix & m1,const Matrix & m2){
	assert(m1.isEqualIndex(m2));
	Matrix m(m1.row,m1.column);
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			m.setAt(i,j,(m1.getAt(i,j)-m2.getAt(i,j)));
		}
	}
	return m;
}

Matrix operator*(const Matrix & m1,const Matrix & m2){
	assert(m1.isInverseIndex(m2));
	Matrix m(m1.row,m2.column);
	double sum;
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			sum=0;
			for(int k=0;k<m2.row;k++){
				sum+=m1.getAt(i,k)*m2.getAt(k,j);
			}
			m.setAt(i,j,sum);
		}
	}
	return m;
}

Matrix operator*(const Matrix & m1,const double & d){
	Matrix m(m1.row,m1.column);
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			m.setAt(i,j,(d*m1.getAt(i,j)));
		}
	}
	return m;
}

ostream & operator<<(ostream & out,const Matrix & m){
	out<<m.row<<","<<m.column<<"\n";
	for(int i=0;i<m.row;i++){
		for(int j=0;j<m.column;j++){
			out<<setprecision(3)<<m.getAt(i,j)<<setw(6);
		}
		out<<"\n";
	}
	return out;
}

istream & operator>>(istream & in,Matrix & m){
	int r,c;
	in>>r;
	in.ignore(2,',');
	in>>c;
	double data[r][c];
	m=Matrix(r,c);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			in>>data[i][j];
			m.setAt(i,j,data[i][j]);
		}
	}
	return in;
}

Matrix::~Matrix() {
	_destroy();
}

