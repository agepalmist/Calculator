#include<iostream>
#include"stack.h"
using namespace std;


int main() {

	//char str[10];
	//gets_s(str);

	stack <double, 10> num;
	stack <char, 10> token;
	
	
	while (cin) {
		char ch;
		cin >> ch;
		if (ch == '=')break;

		switch (ch) {
		case '+': case '-': case '*': case '/':
			token.push(ch);
		case '.': case '0':
		case '1': case '2': case '3':
		case '4': case '5': case '6':
		case '7': case '8': case '9':
		{	
			cin.putback(ch);
			double value;
			cin >> value;
			num.push(value);
		}

		}
	}
	

	cout << num << endl;
	cout << token << endl;
}