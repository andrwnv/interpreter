#include "Parser.h"

Parser::Parser(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	this->str = str;
}

void Parser::parse()
{
	int pos[2] = { 0,0 };

	for (auto element : str)
	{

		for (int i = 0; i < operandsSize; i++)
		{
			if (element == operands[i])
			{
				std::string tempstr;
				pos[1] = str.find(element,pos[0]);
				std::cout << std::endl << "pos 0 = " << pos[0] << " pos 1 = " << pos[1] << std::endl;
				int var = pos[0];
				if (pos[0] != pos[1]) {
					do
					{
						tempstr += str[var];
						std::cout << std::endl << "                  ZASHEL        " << std::endl;
						var++;
					} while (var < pos[1]);
				}
				if (!tempstr.empty())
					varsAndOps.push(tempstr);
				
				tempstr = element;
				if (!tempstr.empty())
					varsAndOps.push(tempstr);
				pos[0] = pos[1] + 1;
			}
		}

	}
	std::cout << std::endl << "Stack " << std::endl;
	while (!varsAndOps.empty())
	{
		std::cout << varsAndOps.top();
		varsAndOps.pop();
		std::cout << std::endl;
	}
	//"a=3+(2+2);"
}

