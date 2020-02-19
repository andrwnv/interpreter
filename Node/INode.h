#pragma once

#include <memory>

template<typename T>
class INode
{
public:
    virtual std::shared_ptr<T> getRightChild() const = 0;
    virtual std::shared_ptr<T> getLeftChild()  const = 0;
    virtual std::shared_ptr<T> getOperand()    const = 0;
};
