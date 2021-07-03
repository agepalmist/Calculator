#pragma once
#include"stack.h"
#include"token.h"
#include"token_stream.h"

class calculator
{
	stack<double,10> numbers;
	stack<char,10> operators;  
    token_stream ts;

public:
    calculator(){}
    void scaling();
    void in_stream_stack(token);
    void out_stream_stack();
    void action(char);
   

    void get_numbers() {
        cout << numbers << endl;
    }
    void get_operators() {
        cout << operators << endl;
    }

    

	

};

