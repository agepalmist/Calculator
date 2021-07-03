#include "token_stream.h"
#include<iostream>
using namespace std;

token token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';': case 'q': case '(': case ')':
	case '+': case '-': case '*': case '/':
		return token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		cin.putback(ch);
		double val;
		cin >> val;
		return token{ '!',val };
	}
	default:
		cerr << "Input error";
	}
}

void token_stream::putback(token t) {
	buffer = t;
	full = true;
}

token_stream::token_stream() :full(false), buffer(0)
{ }
