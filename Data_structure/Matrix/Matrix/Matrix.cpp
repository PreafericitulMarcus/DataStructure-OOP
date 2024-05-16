#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;

// O(n) - n is the number of elements in the matrix
Matrix::Matrix(int nrLines, int nrCols)
{
	// TODO - Implementation
	numberLines = nrLines;
	numberColumns = nrCols;

	size = 0;
	root = nullptr;

	// we create an array of pointers to each element in the matrix and initialize them with nullptr
	binaryTree = new TreeNode *[nrLines * nrCols];
	for (int i = 0; i < nrLines * nrCols; i++)
		binaryTree[i] = nullptr;
}

// constant
int Matrix::nrLines() const
{
	// TODO - Implementation
	return numberLines;
}

// constant
int Matrix::nrColumns() const
{
	// TODO - Implementation
	return numberColumns;
}

TElem Matrix::element(int i, int j) const
{
	// TODO - Implementation
	// validation
	if (i < 0 || i >= numberLines || j < 0 || j >= numberColumns)
		throw exception();

	// start the search from the root
	TreeNode *currentNode = root;
	while (true)
	{
		// if the root is nullptr, the matrix is empty
		if (currentNode == nullptr)
			return NULL_TELEM;
		// if we found the element, we return its value
		if (currentNode->info.i == i && currentNode->info.j == j)
			return currentNode->info.value;
		// if the element is not the current node, we search for it in the left or right subtree
		// we go throught the binary tree the same way we modified it in the modify function
		if (currentNode->info.i == i)
		{
			if (currentNode->info.j < j)
				currentNode = currentNode->right;
			else
				currentNode = currentNode->left;
		}
		else
		{
			if (currentNode->info.i < i)
				currentNode = currentNode->right;
			else
				currentNode = currentNode->left;
		}
	}
}

TElem Matrix::modify(int i, int j, TElem e)
{
	// TODO - Implementation
	// validation
	if (i < 0 || i >= numberLines || j < 0 || j >= numberColumns)
		throw exception();

	if (size == 0) // empty matrix, so we add the first element as the root
	{
		// create the new node and add the information about it
		TreeNode *newNode = new TreeNode;
		newNode->info.i = i;
		newNode->info.j = j;
		newNode->info.value = e;
		newNode->left = nullptr;
		newNode->right = nullptr;

		// make this node the root, being the first element in the matrix
		root = newNode;
		binaryTree[i] = newNode;
		size++;
		return NULL_TELEM;
	}
	else // we add the element in the list
	{
		// create a new node and add the information about it
		TreeNode *newNode = new TreeNode;
		newNode->info.i = i;
		newNode->info.j = j;
		newNode->info.value = e;
		newNode->left = nullptr;
		newNode->right = nullptr;

		// we search for the position where we should add the new element
		TreeNode *currentNode = root;
		while (true)
		{
			// if the element is already in the matrix, we update its value
			if (currentNode->info.i == i && currentNode->info.j == j)
			{
				TElem oldValue = currentNode->info.value;
				currentNode->info.value = e;
				return oldValue;
			}
			// if the element is not in the matrix, we add it
			if (currentNode->info.i == i) // if the line is the same as the current node's line
			{
				if (currentNode->info.j < j) // if the column is greater than the current node's column we add the element to the right
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;
						size++;
						return NULL_TELEM;
					}
					else
						currentNode = currentNode->right;
				}
				else // if the column is smaller than the current node's column we add the element to the left
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = newNode;
						size++;
						return NULL_TELEM;
					}
					else
						currentNode = currentNode->left;
				}
			}
			else // if the line is not the same as the current node's line
			{
				if (currentNode->info.i < i) // if the line is greater than the current node's line we add the element to the right
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = newNode;
						size++;
						return NULL_TELEM;
					}
					else
						currentNode = currentNode->right;
				}
				else // if the line is smaller than the current node's line we add the element to the left
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = newNode;
						size++;
						return NULL_TELEM;
					}
					else
						currentNode = currentNode->left;
				}
			}
		}
	}
}

void Matrix::deleteTree(TreeNode *node)
{
	if (node == nullptr)
		return;

	// first delete both subtrees
	deleteTree(node->left);
	deleteTree(node->right);

	// then delete the node
	delete node;
}

Matrix::~Matrix()
{
	deleteTree(root);
	delete[] binaryTree;
}