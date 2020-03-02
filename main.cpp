#include <array>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Lexeme.h"
#include "Parser.h"
#include "Operation.h"


// Exemple: z = 7y –4x +7
// Final lexeme will look like this: ADD a 12i, where i - integer


void task(std::list<std::string> list)
{
    if (list.empty())
        return;

    static int count = 0;

    auto openBracket = list.begin();
    auto closeBracket = list.begin();

    auto search = std::find(list.begin(), list.end(), std::string("("));
    if (search != list.end())
    {
        openBracket = search;
    }

    search = std::find(list.begin(), list.end(), std::string(")"));
    if (search != list.end())
    {
        closeBracket = ++search;
    }

    // Get part between brackets and start recursion.
    if (openBracket != list.end() and closeBracket != list.end())
    {
        auto nestedList = std::list<std::string>(closeBracket, openBracket);
        list.erase(closeBracket, openBracket);
        task(nestedList);
    }


    // Print list.
//    for (auto const& i : list)
//        std::cout << "[task item]:  " << i << std::endl;

    std::vector<std::list<std::string>::iterator> multItems;
    std::vector<std::list<std::string>::iterator> devItems;
    std::vector<std::list<std::string>::iterator> subItems;
    std::vector<std::list<std::string>::iterator> sumItems;

    for (auto i = list.begin(), t = list.end(); i != t; ++i)
    {
        if (*i == "*")
            multItems.push_back(i);
        else if (*i == "/")
            devItems.push_back(i);
        else if (*i == "+")
            sumItems.push_back(i);
        else if (*i == "-")
            subItems.push_back(i);
    }

    for (auto i : multItems)
    {
        auto tmp = i;
        std::string tmpStr;

        if (count != 0)
            tmpStr = "$"+std::to_string(count - 1);
        else
            tmpStr = *(++i);

        std::cout << Lexeme(Operation('*'), tmpStr, *(++tmp)).command() << std::endl;
        std::cout << Lexeme(Operation('='), "$"+std::to_string(count), tmpStr).command() << std::endl;

        ++count;
    }

    for (auto i : devItems)
    {
//        std::cout << Lexeme(Operation('='), "$"+std::to_string(count), *(--i)).command() << std::endl;
//        ++i;
//        std::cout << Lexeme(Operation('/'), "$"+std::to_string(count), *(++i)).command() << std::endl;

//        ++count;
    }

    for (auto i : subItems)
    {
        auto tmp = i;
        std::string tmpStr;

        if (count != 0)
            tmpStr = "$"+std::to_string(count - 1);
        else
            tmpStr = *(++i);

        std::cout << Lexeme(Operation('-'), tmpStr, *(++tmp)).command() << std::endl;
        std::cout << Lexeme(Operation('='), "$"+std::to_string(count), tmpStr).command() << std::endl;

        ++count;
    }

    for (auto i : sumItems)
    {
        auto tmp = i;
        std::string tmpStr;

        if (count != 0)
            tmpStr = "$"+std::to_string(count - 1);
        else
            tmpStr = *(++i);

        std::cout << Lexeme(Operation('+'), tmpStr, *(--tmp)).command() << std::endl;
        std::cout << Lexeme(Operation('='), "$"+std::to_string(count), *(i)).command() << std::endl;

        ++count;
    }

    if (openBracket == list.end() and closeBracket == list.end())
        return;

    --count;
    std::cout << Lexeme(Operation('='), list.back(), "$"+std::to_string(count)).command() << std::endl;
}


int main()
{
    // Parsing.
    auto parsResult = Parser("z=7*y-3*(x+7)").getStack();

    // Do commands.
    task(parsResult);

    return 0;
}
