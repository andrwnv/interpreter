#pragma once

#include "INode.h"

template <class T>
class Token : public INode<T>
{
public:
    Token() = default;

    std::shared_ptr<T> getRightChild() const override;
    std::shared_ptr<T> getLeftChild()  const override;
    std::shared_ptr<T> getOperand()    const override;

private:
    std::weak_ptr<T> _operand;
    std::weak_ptr<T> _leftChild;
    std::weak_ptr<T> _rightChild;
};


template<class T>
std::shared_ptr<T> Token<T>::getRightChild() const
{
    return _rightChild.lock();
}

template<class T>
std::shared_ptr<T> Token<T>::getLeftChild() const
{
    return _leftChild.lock();
}

template<class T>
std::shared_ptr<T> Token<T>::getOperand() const
{
    return _operand.lock();
}
