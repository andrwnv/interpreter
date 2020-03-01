#pragma once

#include <string>

#include "Operation.h"


template <class T, class U>
class Lexeme
{
public:
    explicit Lexeme(Operation const& operation) : _operation(operation) { }
    explicit Lexeme(Operation && operation) : _operation( std::move(operation) ) { }

private:
    T         _fisrt;
    U         _secound;

    Operation _operation;

private:
    [[nodiscard]] auto _firstType() const -> std::string
    {
        return typeid(_fisrt).name();
    }

    [[nodiscard]] auto _secondType() const -> std::string
    {
        return typeid(_secound).name();
    }

public:
    [[nodiscard]] auto finishType() const -> std::string
    {
        return typeid(decltype(_fisrt + _secound)).name();
    }
};

