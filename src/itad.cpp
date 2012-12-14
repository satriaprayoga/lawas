

#include<iostream>
#include <string>
#include "list/list.h"


using namespace std;

int main(){
	List<string> l;
	l.pushBack("test");
	l.pushFront("dulu");
	string s;
	l.popFront(&s);
	cout<<"popped: "<<s<<endl;
	List<string>::Iterator iter=l.begin();
	while(iter->hasNext()){
		cout<<iter->value()<<endl;
		iter=iter->next();
	}
    return 0;
}
