#include<iostream>
#include"calculate.h"
using namespace std;


int main() {

	calculate t;

	char str[] = "2+3-6*4";

	
	
		t.set_stack(str);
	
	
	t.get_actions();
	t.get_digits();
}