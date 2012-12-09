/*
 * StackPoint.cpp
 * GILANG SATRIA PRAYOGA 23512153
 */

#include "StackPoint.h"

const int DefaultSize=10;

StackPoint::StackPoint() {
	size=DefaultSize;
	top=0;
	P=new Point[size];
	if(P!=NULL){
		for(int i=0;i<size;i++){
			P[i].SetX(0);
			P[i].SetY(0);
			P[i].SetColor("Green");
		}
	}
}

StackPoint::StackPoint(int s) {
	size=s;
	top=0;
	P=new Point[size];
	if(P!=NULL){
		for(int i=0;i<size;i++){
			P[i].SetX(0);
			P[i].SetY(0);
			P[i].SetColor("Green");
		}
	}
}

StackPoint::StackPoint(const StackPoint& S) {
	size=S.size;
	top=S.top;
	P=new Point[size];
	if(P!=NULL){
		for(int i=0;i<size;i++){
			P[i].SetX(S.P[i].GetX());
			P[i].SetY(S.P[i].GetY());
			P[i].SetColor(S.P[i].GetColor());
		}
	}
}

StackPoint& StackPoint::operator =(const StackPoint& S) {
	if(P){
		delete [] P;
	}
	size=S.size;
	top=S.top;
	P=new Point[size];
	if(P!=NULL){
		for(int i=0;i<size;i++){
			P[i].SetX(S.P[i].GetX());
			P[i].SetY(S.P[i].GetY());
			P[i].SetColor(S.P[i].GetColor());
		}
	}
	return *this;
}

void StackPoint::Push(Point p) {
	assert(P!=NULL);
	if(IsFull()){
		cout<<"STACK FULL\n";
	}else{
		P[top]=p;
		top++;
	}
}

Point StackPoint::Pop() {
	assert(P!=NULL);
	Point popped;
	if(IsEmpty()){
		cout<<"Stack Empty\n";
	}else{
		top--;
		popped=P[top];
	}
	return popped;

}

bool StackPoint::IsEmpty() const {
	return top==0;
}

bool StackPoint::IsFull() const {
	return top==size;
}

StackPoint::~StackPoint() {
	delete [] P;
	size=0;
	top=0;
}

