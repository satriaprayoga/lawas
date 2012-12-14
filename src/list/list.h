/*
 * list.h
 *
 * Author: Gilang Satria Prayoga
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class List{
	class Node{
		friend class List;
		Node *left;
		Node *right;
		T data;
	public:
		Node():left(NULL),right(NULL){}
		Node(T d):left(NULL),right(NULL),data(d){}
		T value()const{return data;}
		bool hasNext()const{return right!=NULL;}
		bool hasPrev()const{return left!=NULL;}
		Node * next(){return right;}
		Node * prev(){return left;}
	};
protected:
	Node *head;
	Node *tail;
	int size;
	void appendBefore(Node *n,T data);
	void appendAfter(Node *n,T data);
	void removeAfter(Node *n);
	void removeBefore(Node *n);
public:
	typedef Node * Iterator;
	List();
	void pushFront(T data);
	void pushBack(T data);
	void popFront(T *data);
	void popBack(T *data);
	bool isEmpty()const;
	Iterator end() const;
	Iterator begin() const;
	virtual ~List();

};

template<class T>
List<T>::List(){
	size=0;
	head=new Node;
	tail=new Node;
	head->right=tail;
	tail->left=head;
}

template<class T>
void List<T>::appendBefore(Node *n, T data){
	Node *p=new Node;
	p->data=data;
	p->right=n;
	p->left=n->left;
	n->left->right=p;
	n->left=p;
	size++;
}

template<class T>
void List<T>::appendAfter(Node *n, T data){
	Node *p=new Node;
	p->data=data;
	p->left=n;
	p->right=n->right;
	n->right->left=p;
	n->right=p;
	size++;
}

template<class T>
void List<T>::removeAfter(Node *n){
	Node *p=n->right;
	n->right=p->right;
	p->right->left=n;
	p->left=NULL;
	p->right=NULL;
	delete p;
	size--;
}

template<class T>
void List<T>::removeBefore(Node *n){
	Node *p=n->left;
	n->left=p->left;
	p->left->right=n;
	p->left=NULL;
	p->right=NULL;
	delete p;
	size--;
}

template<class T>
void List<T>::pushFront(T data){
	appendAfter(head,data);
}

template<class T>
void List<T>::pushBack(T data){
	appendBefore(tail,data);
}

template<class T>
void List<T>::popFront(T *data){
	*data=head->right->data;
	removeAfter(head);
}

template<class T>
void List<T>::popBack(T *data){
	*data=tail->left->data;
	removeBefore(tail);
}

template<class T>
bool List<T>::isEmpty()const{
	return head->right==tail;
}

template<class T>
typename List<T>::Iterator List<T>::begin()const{
	return head->next();
}

template<class T>
typename List<T>::Iterator List<T>::end()const{
	return tail->prev();
}

template<class T>
List<T>::~List(){
	T temp;
	while(!isEmpty()){
		popFront(&temp);
		cout<<"removing: "<<temp<<endl;
		//removeAfter(head);
	}
	delete head;
	delete tail;
}
#endif
