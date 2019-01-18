#include <stdexcept>
#include <iostream>
#include "ExpressionTree.h"

	template <typename DataType>
	ExprTree<DataType>::ExprTree()
	{
		root = NULL; //Start of the tree  == null.
	}
	template <typename DataType>
	ExprTree<DataType>::ExprTree(const ExprTree& source)
	{
		*this = source;
		root = NULL;
	}

	template <typename DataType>
	ExprTree& ExprTree<DataType>::operator=(const ExprTree& source)
	{
		if (source != *this)
		{
			makeEmpty();
		}
		clone(root, source.root);
		return *this;
	}
	//Using similar method to PP slide
	template<typename DataType>
	void ExprTree<DataType>::clone(ExprTreeNode *source)
	{

		if (this != &source)
		{
			makeEmpty();
		}

		if (source == NULL)
		{
			return new ExprTreeNode(source->dataItem, clone(source->left),clone(source->right));
		}
	}

	// Destructor
	template <typename DataType>
	ExprTree<DataType>::~ExprTree()
	{
		makeEmpty();
	}
	
	//Using makeEmpty example from powerpoint.
	template <typename DataType>
	void makeEmpty(const ExprTree * & source)
	{
		if (source != NULL)
		{
			makeEmpty(source->left);
			makeEmpty(source->right);
			delete source;
		}
		source = NULL;
	}

	// Expression tree manipulation operations
	template <typename DataType>
	void ExprTree<DataType>::build()
	{
		//Moved to BuildHelper
		/*String input = "";
		cout << "Enter in infix notation";
		cin << input;
		*/
		build_helper(root);

	}

	template <typename DataType>
	void ExprTree<DataType>::expression() const
	{
		if (root == NULL)
		{
			cout << "No expression" << endl;
		}
		else
		{
			expression_helper(root, LEFT);
		}
	}

	template <typename DataType>
	DataType ExprTree<DataType>::evaluate() const throw (logic_error)
	{
		DataType result;

		if (root == NULL)
		{
			throw logic_error("No expression");
		}
		else
		{
			result = evaluate_helper(root);
		}
		return result;
	}
	// Clear tree -- SEE PP, use either post-order or pre-order notation to loop through it all.
	template <typename DataType>
	void ExprTree<DataType>::clear()
	{
		//Isnt this the same as deconstructor? OR is this looking to keep the acual tree intact and remove data inside.
		makeEmpty();
	}

	template <typename DataType>
	void ExprTree<DataType>::commute()
	{
		if (root != NULL)
		{
			commute_helper(root);
		}
	}

	template <typename DataType>
	bool ExprTree<DataType>::isEquivalent(const ExprTree& source) const
	{
		bool result = false;
		if (this == &source)
		{
			result = true;
		}

		else if ((root == NULL) && (source.isEmpty()))
		{
			result = true;
		}
		{
			result = isEquivalent_helper(root, source.root);
		}
		return result;
	}

	template <typename DataType>
	void ExprTree<DataType>::showStructure() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
		{
			cout << endl;
			showHelper(root, 1);
			cout << endl;
		}
	}


	//May need to move/remove this. Check later.
	template<typename DataType>
	ExprTree<DataType>::ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode * leftPtr, ExprTreeNode * rightPtr)
	{
		dataItem = elem;
		left = leftPtr;
		right = rightPtr;
	}

	//HELPERS, IDEAS FROM POWERPOINTS TO CLEAN UP CODE.
	template <typename DataType>
	bool ExprTree<DataType>::isEmpty() const
	{
		return (root == NULL);
	}

	template <typename DataType>
	void ExprTree<DataType>::build_helper(ExprTreeNode*& currentNode)
	{
		char newData;

		cin >> newData;

		currentNode = new ExprTreeNode(newData, NULL, NULL);

		if ((newdataItement == '+') || (newdataItement == '-') ||
			(newdataItement == '*') || (newdataItement == '/'))
		{
			build_helper(currentNode->left);
			build_helper(currentNode->right);
		}
	}

	template <typename DataType>
	void ExprTree<DataType>::expression_helper(ExprTreeNode* currentNode,bool side) const
	{
		if (((currentNode->dataItem >= '0') && (currentNode->dataItem <= '9'))
			&& (side == LEFT))
		{
			cout << '(' << currentNode->dataItem;
		}
		else if ((currentNode->dataItem == '+') || (currentNode->dataItem == '-') ||
			(currentNode->dataItem == '*') || (currentNode->dataItem == '/'))
		{
			expression_sub(currentNode->left, LEFT);

			cout << ' ' << currentNode->dataItem << ' ';

			expression_sub(currentNode->right, RIGHT);
		}
		else
		{
			cout << currentNode->dataItem << ')';
		}
	}

	template <typename DataType>
	DataType ExprTree<DataType>::evaluate_helper(ExprTreeNode* currentNode)	const throw (logic_error)
	{
		DataType leftRes;
		DataType rightRes;
		DataType result;

		if (currentNode->dataItem >= '0' && currentNode->dataItem <= '9')
		{
			result = DataType(currentNode->dataItem - '0');
		}
		else
		{
			leftRes = evaluate_sub(currentNode->left);
			rightRes = evaluate_sub(currentNode->right);

			switch (currentNode->dataItem)
			{
			case '+':
				result = leftRes + rightRes;
				break;

			case '-':
				result = leftRes - rightRes;
				break;

			case '*':
				result = leftRes * rightRes;
				break;

			case '/':
				result = leftRes / rightRes;
				break;

			default:
				throw logic_error("Not Operand");
				break;
			}
		}
		return result;
	}

	template <typename DataType>
	void ExprTree<DataType>::commute_helper(ExprTreeNode*& currentNode)
	{
		ExprTreeNode* temp;

		if ((currentNode->left != NULL) || (currentNode->right != NULL))
		{
			if (currentNode->left != NULL)
			{
				commute_helper(currentNode->left);
			}

			if (currentNode->right != NULL)
			{
				commute_helper(currentNode->right);
			}

			if ((currentNode->dataItem == '+') || (currentNode->dataItem == '-') ||
				(currentNode->dataItem == '*') || (currentNode->dataItem == '/'))
			{
				temp = currentNode->left;
				currentNode->left = currentNode->right;
				currentNode->right = temp;
			}
		}
	}

	template <typename DataType>
	bool ExprTree<DataType>::isEquivalent_helper(ExprTreeNode* currentNode, ExprTreeNode* otherCurrent) const
	{
		bool result = false;

		if ((currentNode == NULL) || (otherCurrent == NULL))
		{
			if ((currentNode == NULL) && (otherCurrent == NULL))
			{
				result = true;
			}
		}
		else if (currentNode->dataItem == otherCurrent->dataItem)
		{
			result = (isEquivalent_helper(currentNode->left, otherCurrent->left)
				&& isEquivalent_helper(currentNode->right, otherCurrent->right));

			if (!result)
			{
				if ((currentNode->dataItem == '+') || (currentNode->dataItem == '*'))
				{
					result = (isEquivalent_helper(currentNode->right, otherCurrent->left)
						&& isEquivalent_helper(currentNode->left, otherCurrent->right));
				}
			}
		}
		return result;
	}

	template <typename DataType>
	void ExprTree<DataType>::showHelper(ExprTreeNode *node, int depth) const
	{
		int j; 

		if (node != NULL)
		{
			showHelper(node->right, depth + 1);
			for (j = NULL; j < depth; j++)
				cout << "\t";
			cout << " " << p->dataItem;
			if ((node->left != NULL) &&
				(node->right != NULL))
				cout << "<";
			else if (node->right != NULL)
				cout << "/";
			else if (node->left != NULL)
				cout << "\\";
			cout << endl;
			showHelper(node->left, depth + 1);
		}
	}