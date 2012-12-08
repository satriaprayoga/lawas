/*
 * entry.h
 * GILANG SATRIA PRAYOGA 23512153
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

template <class T>
class Entry{
private:
	char key[16];
	T object;
	Entry<T> *next;
public:
	Entry(const char *k,const T & o){
		strcpy(key,k);
		object=o;
		next=NULL;
	}
	Entry(const Entry & e){
		strcpy(key,e.key);
		object=e.object;
		next=e.next;
	}
	const char * getKey()const{
		return key;
	}
	T getObject()const{
		return object;
	}
	void setKey(const char *k){
		strcpy(key,k);
	}
	void setObject(const T & o)const{
		object=o;
	}
	void setNext(Entry<T> *next){
		this->next=next;
	}
	Entry<T> * getNext(){
		return next;
	}
	~Entry(){}
};

#endif /* ENTRY_H_ */
