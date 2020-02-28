#include <iostream>

/*
    Exemple: z = 7y –4x +7
*/

class Operation
{
public:
    Operation() = default;

public:
    [[nodiscard]]
    std::string operation(std::string const& var) const
    {
        switch (_operand)
        {
            case Operand::equal:
                return "MOV " + var;
            case Operand::mult:
                return "MLT " + var;
            case Operand::sum:
                return "SUM " + var;
            case Operand::div:
                return "DIV " + var;
            case Operand::sub:
                return "SUB " + var;
            default:
                return "";
        }
    }

    [[nodiscard]]
    bool convert(char operand)
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
};

int main()
{

    return 0;
}
