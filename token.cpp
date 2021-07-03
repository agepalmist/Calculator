#include "token.h"

token::token(char ch) :kind(ch), value(0)
{ }

token::token(char ch, double val) : kind(ch), value(val) 
{ }
