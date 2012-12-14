/*
 * stack.h
 *
 * Author: Gilang Satria Prayoga
 */

#ifndef STACK_H_
#define STACK_H_

#include "list.h"


template <class T>
class Stack:public List<T>{
public:
	Stack():List<T>(){}
	void push(T data){
		List<T>::pushFront(data);
	}
	void pop(T *data){
		List<T>::popFront(data);
	}
	typename Stack<T>::Iterator begin(){
		return List<T>::begin();
	}

	typename Stack<T>::Iterator end(){
			return List<T>::end();
		}

	~Stack(){}
};



#endif /* STACK_H_ */
