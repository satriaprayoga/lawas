//============================================================================
// Name        : itad.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "table/entry.h"
using namespace std;

int main() {
	Entry<int> entry("asdqwe123",3);
	cout<<entry.getKey()<<","<<entry.getObject()<<endl;
	return 0;
}
