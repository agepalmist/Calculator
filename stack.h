#pragma once
#include<iostream>
using namespace std;

template<typename T, size_t size>
class stack
{
	T* stck;
	int peak = -1;

public:

	stack()
		:stack{new T*[size]}{}

	stack(const stack<T, size_t>&) = delete;

	void operator=(const stack<T, size_t>&) = delete;

	~stack() { delete[]this->stck; }

	void push(T value) {
		if (this->peak == size - 1) {
			cout << "Stack is complete" << endl;
		}
		else {
			this->stck[++this->peak] = value;
		}
	}

	T pop() {
		if (this->peak < 0) {
			cout << "Stack is empty" << endl;			
		}
		else {
			return this->stck[this->peak--];
		}
	}



	
	
};

