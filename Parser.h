#pragma once
#include <string>
#include <algorithm>
#include <iostream>
class Parser
{
public:

    Parser(std::string str);
private:
    std::string str;
    char operands[8] = {'+','-','=','(',')','*','/',';'};
};
