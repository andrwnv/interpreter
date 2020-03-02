#pragma once

#include <string>
#include <stdexcept>
#include <unordered_map>

class Operation
{
public:
    Operation(char operand) { _convert(operand); }

private:
    enum class Operator {
        equal,
        mult,
        sum,
        div,
        sub,
        undefinded = 0
    };

    Operator _operand;

    const std::unordered_map<char, Operator> _operators
    {
        {'=', Operator::equal},
        {'*', Operator::mult },
        {'+', Operator::sum  },
        {'-', Operator::sub  },
        {'/', Operator::div  },
    };

public:
    [[nodiscard]]
    std::string operation(std::string const& var, std::string const& value) const {
        switch (_operand)
        {
            case Operator::equal:
                return "MOV " + var + " " + value;
            case Operator::mult:
                return "MLT " + var + " " + value;
            case Operator::sum:
                return "SUM " + var + " " + value;
            case Operator::div:
                return "DIV " + var + " " + value;
            case Operator::sub:
                return "SUB " + var + " " + value;
            default:
                return "";
        }
    }

private:
    bool _convert(char operand) {
        auto res =  _operators.find(operand);
        _operand = res->second;

        return res != _operators.end();
    }
};
