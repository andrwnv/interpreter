#pragma once

#include <list>
#include <iostream>
#include <functional>

#include "Node/Token.h"

class LexemeManager
{
public:
    LexemeManager();
    void push();

private:
    std::list<INode*> _lexemesTree;
};
