#pragma once
#include"stack.h"
#include<iostream>
using namespace std;

class calculate
{
	stack<char,10> actions;
	stack<double,10> digits;    

public:
    calculate(){}

    void set_stack(char*);
   

    void get_actions() {
        cout << actions << endl;
    }
    void get_digits() {
        cout << digits << endl;
    }

    

	

};

