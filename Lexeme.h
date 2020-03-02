#pragma once

#include <string>

#include "Operation.h"

class Lexeme
{
public:
    explicit Lexeme(Operation const& operation, std::string const& first, std::string const& second)
        : _firstOperand(first)
        , _secondOperand(second)
        , _operation(operation) { }

    explicit Lexeme(Operation && operation) : _operation( std::move(operation) ) { }

private:
    std::string _firstOperand;
    std::string _secondOperand;

    Operation _operation;

public:

    [[nodiscard]] std::string command() const
    {
        return _operation.operation(_firstOperand, _secondOperand);
    }
};

