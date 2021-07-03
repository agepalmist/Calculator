#include "calculator.h"
#include<iostream>
using namespace std;

void calculator::scaling() {
	while (cin) {		
		token t = ts.get();
		if (t.kind == 'q') {
			break;
		}
		if (t.kind == ';') {
			out_stream_stack();
			get_numbers();
		}
		else {
			//ts.putback(t);
			in_stream_stack(t);
		}		
	}
}

void calculator::in_stream_stack(token t) {
	char ch = t.kind;	
	switch (ch) {
	case '*': case '/': {
		numbers.push(ts.get().value);
		action(ch);
		break;
	}
	case '-': case '+': {
		if (operators.get_size() >= 0) {
			out_stream_stack();
			operators.push(ch);
		}
		else {
			operators.push(ch);
		}
		break;
	}
	default: {
		numbers.push(t.value);
	}
	}
}

void calculator::out_stream_stack() {
	while (operators.get_size() >= 0) {
		char ch = operators.pop();
		action(ch);
	}
}

void calculator::action(char opr) {
	double right = numbers.pop();
	double left = numbers.pop();
	if (opr == '+') {
		numbers.push(left + right);
	}
	else if (opr == '-') {
		numbers.push(left - right);
	}
	else if (opr == '*') {
		numbers.push(left * right);
	}
	else if (opr == '/') {
		numbers.push(left / right);
	}
}
