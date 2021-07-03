#pragma once
class token
{
public:
	char kind;
	double value;
	token(char ch);		
	token(char ch, double val);		
};

