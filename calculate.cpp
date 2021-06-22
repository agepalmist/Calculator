#include "calculate.h"

void calculate::set_stack(char* str){
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == '*') {
			double tmp = digits.pop() * atoi(str + i + 1);
			digits.push(tmp);
			i++;
		}
		else if (isdigit(str[i])) {
			digits.push(atoi(str + i));
		}
		else {
			actions.push(str[i]);
		}
	}
}
