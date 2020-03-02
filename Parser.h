#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <array>
#include <list>

class Parser
{
public:

    Parser(std::string const& str);

    void setNewString(std::string const& str);
    [[nodiscard]] std::list<std::string> getStack();

private:
    void _parse();

private:
    std::string            _str;
    std::array<char, 8>    _operands {'+','-','=','(',')','*','/',';'};

    std::list<std::string> _varsAndOps;
};
