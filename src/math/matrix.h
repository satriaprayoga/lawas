/*
 * Matrix.h
 *
 * Author: Gilang Satria Prayoga
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

class Matrix {
private:
	double **data;
	int row;
	int column;

	void _initialize(const int &r,const int &c);
	void _destroy();

	bool _isValidRow(const int & r)const{
		return (r>=0 && r<row);
	}

	bool _isValidColumn(const int & c)const{
		return (c>=0 && c<column);
	}
public:
	Matrix();
	Matrix(const int & r,const int & c);
	Matrix(const Matrix &m);
	Matrix & operator=(const Matrix &m);
	/**
	 * static member functions
	 */
	static Matrix createRowMatrix(const int & c);
	static Matrix createColumnMatrix(const int &r);
	static Matrix createIdentityMatrix(const int & r,const int & c,const double & v=1.0);

	/**
	 * getter and setter
	 */
	double * operator[](const int & idx)const;
	double & getAt(const int & i,const int & j)const;
	void setAt(const int & i,const int & j,const double & v);
	int getRow()const{return row;}
	int getColumn() const{return column;}

	bool isVector()const;
	bool isValidIndex(const int & r,const int & c)const;
	bool isEqualIndex(const Matrix & m)const;
	bool isInverseIndex(const Matrix & m)const;

	Matrix transpose()const;
	double vectorlength()const;
	void nwDiag(const double & v=0);
	double dot(const Matrix & m);
	Matrix rowMatrix(const int & idx)const;
	Matrix columnMatrix(const int & idx)const;

	friend Matrix operator+(const Matrix & m1,const Matrix & m2);
	friend Matrix operator-(const Matrix & m1,const Matrix & m2);
	friend Matrix operator*(const Matrix & m1,const Matrix & m2);
	friend Matrix operator*(const Matrix & m1,const double & d);

	friend ostream & operator<<(ostream & out,const Matrix & m);

	friend istream & operator>>(istream & in,Matrix & m);

	~Matrix();
};

#endif /* MATRIX_H_ */
