#include <iostream>
#include <string>
using namespace std;

class Tree
{
public:
	enum OperationType
	{
		Summ,
		Subst,
		Multiply,
		Division,
		Equal
	};
	struct Node
	{
		string dataLeft, dataRight;
		Node* left = nullptr, * right = nullptr;
		OperationType operation;
		int prior;
	};
private:

	Node* head = nullptr;

public:
	Tree()
	{
		head = new Node;
		head->dataLeft = "z";
		head->operation = OperationType::Equal;
		head->right = new Node;
		Node* curNode = head->right;
		
		curNode->dataRight = "7";
		curNode->operation = OperationType::Summ;
		curNode->left = new Node;
		
		curNode = curNode->left;
		curNode->left = new Node;
		curNode->operation = OperationType::Subst;
		curNode->right = new Node;
		Node* centerNode = curNode;

		curNode = curNode->left;
		curNode->dataLeft = "7";
		curNode->operation = OperationType::Multiply;
		curNode->right = new Node;
		
		curNode = curNode->right;
		curNode->dataLeft = "y";
		curNode->operation = OperationType::Multiply;
		curNode->dataRight = "y";
		curNode = centerNode->right;
		curNode->dataLeft = "4";
		curNode->operation = OperationType::Multiply;
		curNode->right = new Node;

		curNode = curNode->right;
		curNode->dataLeft = "x";
		curNode->operation = OperationType::Multiply;
		curNode->dataRight = "x";
	}
	void startTranslate()
	{
		n = 0;
		translate(head);
	}
private:
	int n = 0;
	bool isConstant(string c)
	{
		return ('0' <= c[0] && c[0] <= '9');
	}

	string generateLoadOutput(string c)
	{
		if (isConstant(c)) return ("= " + c);
		else return c;
	}
	
	string translate(Node* currentNode)
	{
		string p1, p2, returnValue;
		bool p1IsTemporary = false, p2IsTemporary = false;
		if (currentNode->right == nullptr)
		{
			cout << "LOAD " << generateLoadOutput(currentNode->dataRight) << endl;
			if (currentNode->operation != OperationType::Equal)
			{
				n++;
				p1 = '$' + to_string(n);
				cout << "STORE " << p1 << endl;
			}
		}
		else
		{
			p2 = translate(currentNode->right);
			p2IsTemporary = true;
			
		}

		if (currentNode->left == nullptr)
		{
			if (currentNode->operation != OperationType::Equal)
			{
				cout << "LOAD " << generateLoadOutput(currentNode->dataLeft) << endl;
			}

		}
		else
		{
			p1 = translate(currentNode->left);
			p1IsTemporary = true;
			
		}

		switch (currentNode->operation)
		{
		case OperationType::Summ:
			if (p2.empty())p2 = "$2";
			if (p2IsTemporary || p1IsTemporary) cout << "LOAD " << p2 << endl;
			cout << "ADD $" << n - 1 << endl;
			cout << "STORE $" << n - 1 << endl;
			returnValue = "$" + to_string(n - 1);
			break;
		case OperationType::Multiply:
			if ( p1IsTemporary) cout << "LOAD " << p1 << endl;
			cout << "MPY $" << n << endl;
			cout << "STORE $" << n << endl;
			returnValue = "$" + to_string(n);
			break;
		case OperationType::Subst:
			if (p2IsTemporary || p1IsTemporary) cout << "LOAD " << p1 << endl;
			cout << "DIFF $" << n - 1 << endl;
			cout << "STORE $" << n - 1 << endl;
			returnValue = "$" + to_string(n);
			break;
		case OperationType::Equal:
			if (p2IsTemporary) cout << "LOAD " << p2 << endl;
			cout << "STORE " << currentNode->dataLeft << endl;
			break;
		}
		if (p1IsTemporary) n--;
		return returnValue;
	}
};



int main()
{
	Tree* tree = new Tree;
	setlocale(0, "");
	tree->startTranslate();
	//userControl(tree);
	return 0;
}