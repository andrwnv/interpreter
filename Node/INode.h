#pragma once

#include <memory>
#include <functional>

class INode
{
public:
    virtual std::shared_ptr<INode> getRightChild()    const = 0;
    virtual std::shared_ptr<INode> getLeftChild()     const = 0;

    virtual std::function<int(int, int)> getOperand() const = 0;
};
