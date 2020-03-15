#include <iostream>
#include <string>
#include  <list>
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
	//void startTranslate()
	//{
	//	n = 0;
	//	translate(head);
	//}
	void startTranslateUpr()
	{
		n = 0;
		translateUpr(head);
	}
	list<string> coms;
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


	string translateUpr(Node* currentNode)
	{
		string p1, p2, returnValue;
		bool p1IsTemporary = false, p2IsTemporary = false;
		if (currentNode->right == nullptr)
		{

			coms.push_back("LOAD " + generateLoadOutput(currentNode->dataRight));

			if (currentNode->operation != OperationType::Equal)
			{
				n++;
				p1 = '$' + to_string(n);
				coms.push_back("STORE " + p1);
			}
		}
		else
		{
			p2 = translateUpr(currentNode->right);
			p2IsTemporary = true;

		}

		if (currentNode->left == nullptr)
		{
			if (currentNode->operation != OperationType::Equal)
			{
				coms.push_back("LOAD " + generateLoadOutput(currentNode->dataLeft));
			}

		}
		else
		{
			p1 = translateUpr(currentNode->left);
			p1IsTemporary = true;

		}

		switch (currentNode->operation)
		{
		case OperationType::Summ:

			if (p2IsTemporary || p1IsTemporary)
			{
				coms.push_back("LOAD " + p1);
			}

			coms.push_back("ADD $" + to_string(n - 1));
			coms.push_back("STORE $" + to_string(n - 1));

			returnValue = "$" + to_string(n - 1);
			break;

		case OperationType::Multiply:

			if (p1IsTemporary) {
				coms.push_back("LOAD " + p1);
			}

			coms.push_back("MPY $" + to_string(n));
			coms.push_back("STORE $" + to_string(n));

			returnValue = "$" + to_string(n);
			break;
		case OperationType::Subst:

			if (p2IsTemporary || p1IsTemporary) {
				coms.push_back("LOAD " + p1);
			}

			coms.push_back("DIFF $" + to_string(n - 1));
			coms.push_back("STORE $" + to_string(n - 1));
			returnValue = "$" + to_string(n);
			break;
		case OperationType::Equal:
			if (p2IsTemporary) {
				coms.push_back("LOAD " + p2);
			}
			coms.push_back("STORE " + currentNode->dataLeft);
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
	tree->startTranslateUpr();
	int count = 0;
	for (auto const& element : tree->coms)
	{
		cout << element << endl;
	}
	cout << endl;
	auto prevItem = tree->coms.begin();
	for (auto i = tree->coms.begin(); i != tree->coms.end(); ++i)
	{
		if (prevItem->find("STORE") == std::string::npos)
		{
			prevItem = i;
			continue;
		}

		if (i->back() == prevItem->back() && i->find("LOAD") != std::string::npos)
		{
			auto tmp = ++i;
			tree->coms.erase(prevItem, tmp);
		}

		prevItem = i;
	}

	for (auto const& element : tree->coms)
	{
		cout << element << endl;
	}

	return 0;
}