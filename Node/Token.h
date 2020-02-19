#pragma once

#include "INode.h"

template <typename T>
class Token : public INode<T>
{
public:
    Token() = default;
    Token(std::shared_ptr<INode<T>> rightChild, std::shared_ptr<INode<T>> leftChild, std::function<int(int, int)> && operand);
    Token(Token<T> const& token);

    [[nodiscard]] std::shared_ptr<INode<T>>    getRightChild()  const override;
    [[nodiscard]] std::shared_ptr<INode<T>>    getLeftChild()   const override;

    [[nodiscard]] std::function<int(int, int)> getOperand()     const override;

private:
    std::function<int (int, int)>    _operand;

    std::weak_ptr<INode<T>>           _leftChild;
    std::weak_ptr<INode<T>>           _rightChild;
};

template <typename T>
Token<T>::Token(Token<T> const& token)
{
    _operand    = token.getOperand();
    _leftChild  = token.getLeftChild();
    _rightChild = token.getRightChild();
}

template <typename T>
Token<T>::Token(std::shared_ptr<INode<T>> rightChild, std::shared_ptr<INode<T>> leftChild, std::function<int(int, int)> && operand)
        : _operand   (std::move(operand))
        , _leftChild(leftChild)
        , _rightChild(rightChild) { }

template <typename T>
std::shared_ptr<INode<T>> Token<T>::getRightChild() const
{
    return _rightChild.lock();
}

template <typename T>
std::shared_ptr<INode<T>> Token<T>::getLeftChild() const
{
    return _leftChild.lock();
}

template <typename T>
std::function<int(int, int)> Token<T>::getOperand() const
{
    return _operand;
}