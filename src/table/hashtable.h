/*
 * hashtable.h
 * GILANG SATRIA PRAYOGA 23512153
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "entry.h"

using namespace std;

template <class T>
class Hashtable{
private:
	static int DEFAULT_TBL_SIZE;
	int size;
	int tableSize;
	Entry<T> ** table;
	int currentIndex;

	void initTable(int s);
	Entry<T> * find(const char *k);

public:
	Hashtable();
	Hashtable(int t);
	Hashtable(const Hashtable &);
	Hashtable & operator=(const Hashtable&);

	bool put(const char *k,const T & obj);
	bool get(const char *k,T * obj);
	bool remove(const char *k);
	void removeAll();

	bool contains(const char *k) const;

	int getSize()const;

	virtual ~Hashtable();
};
#endif /* HASHTABLE_H_ */

template <class T>
int Hashtable<T>::DEFAULT_TBL_SIZE=101;

template <class T>
void Hashtable<T>::initTable(int s){
	size=0;
	tableSize=s;
	table=new Entry<T>*[tableSize];
	for(int i=0;i<tableSize;i++){
		table[i]=NULL;
	}
	currentIndex=0;
}

template <class T>
Hashtable<T>::Hashtable(){
	initTable(DEFAULT_TBL_SIZE);
}

template <class T>
Hashtable<T>::Hashtable(int t){
	initTable(t);
}
