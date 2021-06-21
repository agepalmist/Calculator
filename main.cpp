#include<iostream>
#include"stack.h"
using namespace std;


int main() {

	stack<int,10> arr;	
	for (size_t i = 0; i <15; i++)
	{
		arr.push(i);
	}


	return 0;
}