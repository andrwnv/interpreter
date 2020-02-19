#pragma once

#include <memory>
#include <functional>

template<class T>
class INode
{
public:
    virtual std::shared_ptr<T>     getRightChild() const = 0;
    virtual std::shared_ptr<T>     getLeftChild()  const = 0;

    virtual std::function<T(T, T)> getOperand()    const = 0;
};
