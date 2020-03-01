#include <array>
#include <iostream>
#include <algorithm>

#include "Lexeme.h"
#include "Parser.h"
#include "Operation.h"


// Exemple: z = 7y –4x +7
// Final lexeme will look like this: ADD a 12i, where i - integer


int main()
{
    Operation op('+');
    std::cout << op.operation("a", 12.165);

    Lexeme<float, float> a(Operation('+'));
    std::cout << a.finishType();
	
    // Parsing.
    Parser pars("z=7*y-3*(x+7)");
    std::cout << std::endl;

    std::cout << std::endl << "Stack: " << std::endl;

    for (auto const& i : pars.getStack())
        std::cout << "  -> " << i << std::endl;
	
    return 0;
}
