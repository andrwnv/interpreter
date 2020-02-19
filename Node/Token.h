#pragma once

#include "INode.h"

template <class T>
class Token : public INode<T>
{
public:
    explicit Token(INode<T>* rightChild, INode<T>* leftChild, std::function<T(T, T)> && operand);

    std::shared_ptr<INode<T>> getRightChild()  const override;
    std::shared_ptr<INode<T>> getLeftChild()   const override;

    std::function<T(T, T)>    getOperand()     const override;

private:
    std::function<T(T, T)>    _operand;

    std::weak_ptr<INode<T>>   _leftChild;
    std::weak_ptr<INode<T>>   _rightChild;
};


template<class T>
Token<T>::Token(INode<T>* rightChild, INode<T>* leftChild, std::function<T(T, T)> && operand)
    : _rightChild(std::make_shared<INode<T>>(rightChild))
    , _leftChild (std::make_shared<INode<T>>(leftChild))
    , _operand   (std::move(operand)) { }

template<class T>
std::shared_ptr<INode<T>> Token<T>::getRightChild() const
{
    return _rightChild.lock();
}

template<class T>
std::shared_ptr<INode<T>> Token<T>::getLeftChild() const
{
    return _leftChild.lock();
}

template<class T>
std::function<T(T, T)> Token<T>::getOperand() const
{
    return _operand;
}
