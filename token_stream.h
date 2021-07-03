#pragma once
#include"token.h"
class token_stream
{
	bool full;
	token buffer;
public:
	token get();
	void putback(token);
	token_stream();
};

