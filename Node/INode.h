#pragma once

#include <memory>
#include <functional>

template <typename T>
class INode
{
public:
    virtual std::shared_ptr<INode<T>> getRightChild()    const = 0;
    virtual std::shared_ptr<INode<T>> getLeftChild()     const = 0;

    virtual std::function<int(int, int)> getOperand() const = 0;
};
