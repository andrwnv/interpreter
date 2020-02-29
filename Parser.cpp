#include "Parser.h"

Parser::Parser(std::string str)
{
    str.erase(std::remove(str.begin(),str.end(),' '),str.end());
}
