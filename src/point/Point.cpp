/*
 * Point.cpp
 * GILANG SATRIA PRAYOGA 23512153
 */

#include "Point.h"
#include <sstream>

const string DefaultColor="white";

Point::Point() {
	P=new int[2];
	if(P!=NULL){
		P[0]=0;
		P[1]=0;
	}
	color=DefaultColor;
}

Point::Point(int x,int y,string c){
	P=new int[2];
	if(P!=NULL){
		P[0]=x;
		P[1]=y;
		color=c;
	}else{
		color=DefaultColor;
	}
}

Point::Point(const Point &p){
	P=new int[2];
	if(P!=NULL){
		P[0]=p.GetX();
		P[1]=p.GetY();
		color=p.GetColor();
	}else{
		color=DefaultColor;
	}
}

Point & Point::operator =(const Point &p){
	if(P!=NULL){
		delete [] P;
	}
	P=new int[2];
	if(P!=NULL){
		P[0]=p.GetX();
		P[1]=p.GetY();
		color=p.GetColor();
	}else{
		color=DefaultColor;
	}
	return *this;
}

void Point::SetX(int x){
	assert(P!=NULL);
	P[0]=x;
}

void Point::SetY(int y){
	assert(P!=NULL);
	P[1]=y;
}

void Point::SetColor(string c){
	if(P==NULL){
		color=DefaultColor;
	}else{
		color=c;
	}
}

int Point::GetX()const{
	if(P==NULL){
		throw exception();
	}else{
		return P[0];
	}
}

int Point::GetY()const{
	if(P==NULL){
		throw exception();
	}else{
		return P[1];
	}
}

string Point::GetColor()const{
	return color;
}

string Point::PointToString()const{
	assert(P!=NULL);
	stringstream ss;
	ss<<P[0];
	ss<<",";
	ss<<P[1];
	ss<<".";
	ss<<color;
	return ss.str();
}

bool Point::operator ==(const Point &p){
	assert(P!=NULL && p.P!=NULL);
	return (P[0]==p.P[0] && P[1]==p.P[1]);
}

Point operator+(const Point &p1,const Point & p2){
	assert(p1.P!=NULL && p2.P!=NULL);
	return Point(p1.GetX()+p2.GetX(),p1.GetY()+p2.GetY(),DefaultColor);
}

Point::~Point() {
	if(P){
		delete [] P;
	}
}

