#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
class Parser
{
public:

    Parser(std::string str);
	void parse();
private:
	std::string str;
	const static int operandsSize = 8;
    
    char operands[operandsSize] = {'+','-','=','(',')','*','/',';'};

	std::stack<std::string> varsAndOps;
};
