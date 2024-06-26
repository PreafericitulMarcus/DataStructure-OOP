#pragma once

// DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix
{

private:
	// TODO - Representation
	struct Position
	{
		int i, j;
		TElem value;
	};

	struct TreeNode
	{
		Position info;
		TreeNode *right;
		TreeNode *left;
	};

	int size;
	int numberLines;
	int numberColumns;

	TreeNode *root;
	TreeNode **binaryTree;

public:
	// constructor
	Matrix(int nrLines, int nrCols);

	~Matrix();
	void deleteTree(TreeNode *node);

	// returns the number of lines
	int nrLines() const;

	// returns the number of columns
	int nrColumns() const;

	// returns the element from line i and column j (indexing starts from 0)
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	// modifies the value from line i and column j
	// returns the previous value from the position
	// throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);
};
