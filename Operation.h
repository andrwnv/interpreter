#pragma once

#include <string>
#include <stdexcept>

class Operation
{
public:
    Operation(char operand) { _convert(operand); }

private:
    enum class Operand
    {
        equal,
        mult,
        sum,
        div,
        sub,
        undefinded
    };

    Operand _operand;

public:
    template <class T> [[nodiscard]]
    std::string operation(std::string const& var, T const& value) const
    {
        switch (_operand)
        {
            case Operand::equal:
                return "MOV " + var + " " + std::to_string(value);
            case Operand::mult:
                return "MLT " + var + " " + std::to_string(value);
            case Operand::sum:
                return "SUM " + var + " " + std::to_string(value);
            case Operand::div:
                return "DIV " + var + " " + std::to_string(value);
            case Operand::sub:
                return "SUB " + var + " " + std::to_string(value);
            default:
                return "";
        }
    }

private:
    bool _convert(char operand)
    {
        switch (operand)
        {
            case '=':
                _operand = Operand::equal;
                return true;
            case '*':
                _operand = Operand::mult;
                return true;
            case '+':
                _operand = Operand::sum;
                return true;
            case '/':
                _operand = Operand::div;
                return true;
            case '-':
                _operand = Operand::sub;
                return true;
            default:
                throw std::logic_error("invalid operator");
        }
    }
};
