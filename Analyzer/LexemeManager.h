#pragma once

#include <stack>
#include <iostream>

template<typename T>
class INode;

class LexemeManager
{
public:
    LexemeManager();

private:
    std::stack < INode<void*> * > _stack;
};
