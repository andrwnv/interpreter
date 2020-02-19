#pragma once

#include "INode.h"

class Token : public INode
{
public:
    Token() = default;
    Token(std::shared_ptr<INode> rightChild, std::shared_ptr<INode> leftChild, std::function<int(int, int)> && operand);
    Token(Token const& token);

    [[nodiscard]] std::shared_ptr<INode>       getRightChild()  const override;
    [[nodiscard]] std::shared_ptr<INode>       getLeftChild()   const override;

    [[nodiscard]] std::function<int(int, int)> getOperand()     const override;

private:
    std::function<int (int, int)>    _operand;

    std::weak_ptr<INode>           _leftChild;
    std::weak_ptr<INode>           _rightChild;
};