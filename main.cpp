#include<iostream>
#include"calculator.h"
using namespace std;
/*
Для завершения потока ввода, в конце выражения вводится ';'
например, 3+2; затем нажать enter.
Для выхода из программы ввести q. 
Калькулятор не обрабатывает двойные скобки:
2+(3+(6-4)) - ERROR
*/

int main() {
	calculator t;
	t.scaling();	
}