#include "LexemeManager.h"


#include <iostream>

#include "Node/Token.h"

LexemeManager::LexemeManager()
{
}

void LexemeManager::push()
{
    _stack.push(new Token<int>(nullptr, nullptr, [](int a, int b){
        return 0;
    }));

    std::cerr << "[PUSHED] -> Stack size: " << _stack.size() << std::endl;

//    _stack.push(new Token<int>(nullptr, nullptr, [](void* t, void* s) -> void*
//    {
//        return nullptr;
//    }));
//    std::cerr << "[PUSHED] -> Stack size: " << _stack.size() << std::endl;

//    _stack.push(new Token<int>(nullptr, nullptr, [](void* t, void* s) -> void*
//    {
//        return nullptr;
//    }));
//    std::cerr << "[PUSHED] -> Stack size: " << _stack.size() << std::endl;

//    _stack.push(new Token<int>(nullptr, nullptr, [](void* t, void* s) -> void*
//    {
//        return nullptr;
//    }));
//    std::cerr << "[PUSHED] -> Stack size: " << _stack.size() << std::endl;
}
