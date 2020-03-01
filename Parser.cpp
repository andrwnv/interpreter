#include "Parser.h"

Parser::Parser(std::string const& str) { setNewString(str); }

void Parser::setNewString(const std::string &str)
{
    _str = str;
    _str.erase(std::remove(_str.begin(), _str.end(), ' '), _str.end());

    _parse();
}

void Parser::_parse()
{
	int pos[2] = { 0,0 };

    for (auto element : _str)
	{
        for (size_t i = 0; i < _operands.size(); ++i)
		{
            if (element == _operands.at(i))
			{
				std::string tempstr;
                pos[1] = _str.find(element, pos[0]);

				int var = pos[0];
				if (pos[0] != pos[1]) {
					do {
                        tempstr += _str[var];
						var++;
					} while (var < pos[1]);
				}
				if (!tempstr.empty())
                    _varsAndOps.push_front(tempstr);

				tempstr = element;
				if (!tempstr.empty())
                    _varsAndOps.push_front(tempstr);
				pos[0] = pos[1] + 1;
			}
		}

	}
}

std::list<std::string> Parser::getStack() { return _varsAndOps; }


