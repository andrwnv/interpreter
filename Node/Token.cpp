#include "Token.h"


Token::Token(Token const& token)
{
    _operand    = token.getOperand();
    _leftChild  = token.getLeftChild();
    _rightChild = token.getRightChild();
}

Token::Token(std::shared_ptr<INode> rightChild, std::shared_ptr<INode> leftChild, std::function<int(int, int)> && operand)
        : _operand   (std::move(operand))
        , _leftChild(leftChild)
        , _rightChild(rightChild) { }

std::shared_ptr<INode> Token::getRightChild() const
{
    return _rightChild.lock();
}

std::shared_ptr<INode> Token::getLeftChild() const
{
    return _leftChild.lock();
}

std::function<int(int, int)> Token::getOperand() const
{
    return _operand;
}