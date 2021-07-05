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
			operators.clear();
			numbers.clear();
		}
		else {
			in_stream_stack(t);
		}
	}
}

void calculator::in_stream_stack(token t) {
	char ch = t.kind;
	switch (ch) {
	case '*': case '/': {
		token next = ts.get();
		if (next.kind != '(') {
			numbers.push(next.value);
			action(ch);
			break;
		}
		operators.push(ch);
		ts.putback(next);
		break;
	}
	case '(': {
		flag = false;
		operators.push(t.kind);
		break;
	}
	case ')': {
		out_stream_stack();
		flag = true;
		break;
	}
	case '-': case '+': {
		if (operators.get_size() >= 0 && flag) {
			out_stream_stack();
			operators.push(ch);
		}
		else {
			operators.push(ch);
		}
		break;
	}
	case '!': {
		numbers.push(t.value);
		break;
	}
	default: {
		operators.push(t.kind);
	}
	}
}

void calculator::out_stream_stack() {
	while (operators.get_size() >= 0) {
		char ch = operators.pop();
		if (ch == '(') {
			break;
		}
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
		try {
			if (!right) {
				throw runtime_error("Divide by zero!");
			}
			numbers.push(left / right);
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;
			exit(1);
		}
	}
}
