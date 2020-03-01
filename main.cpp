#include <iostream>
#include <array>
#include <algorithm>

#include "Parser.h"
/*
    Exemple: z = 7y –4x +7
*/

// Final lexeme will look like this: ADD a 12i, where i - integer

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

private:
    Operand _operand;
};

template <class T, class U>
class Lexeme
{
public:
    explicit Lexeme(Operation operation) : _operation(operation)
    { }

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

int main()
{
    Operation op('+');

    std::cout << op.operation("a", 12);

    Lexeme<float, float> a(op);
    std::cout << a.finishType();
	
    // Parsing.
    Parser pars("z=7*y-3*(x+7)");
    std::cout << std::endl;

    std::cout << std::endl << "Stack: " << std::endl;

    for (auto const& i : pars.getStack())
        std::cout << "  -> " << i << std::endl;
	
    return 0;
}
