#pragma once

#include <stack>
#include <iostream>
#include <functional>

template<class T>
class INode;

class LexemeManager
{
public:
    LexemeManager();
    void push();

private:
    std::stack < INode<void*> * > _stack;
};
