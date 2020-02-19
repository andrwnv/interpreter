#include "LexemeManager.h"

#include <iostream>

#include "Node/Token.h"

LexemeManager::LexemeManager()
{
}

void LexemeManager::push()
{
    _lexemesTree.push_back(new Token<int>(std::make_shared<Token<int>>(),
                                          std::make_shared<Token<int>>(),
                                          [](int a, int b) { return a + b; }));

    std::cerr << "[PUSHED] -> Stack size: " << _lexemesTree.size() << std::endl;

    _lexemesTree.push_back(new Token<int>(std::make_shared<Token<int>>(),
                                          std::make_shared<Token<int>>(),
                                          [](int a, int b) { return a + b; }));

    std::cerr << "[PUSHED] -> Stack size: " << _lexemesTree.size() << std::endl;

    _lexemesTree.push_back(new Token<int>(std::make_shared<Token<int>>(),
                                          std::make_shared<Token<int>>(),
                                          [](int a, int b) { return a + b; }));

    std::cerr << "[PUSHED] -> Stack size: " << _lexemesTree.size() << std::endl;
}
