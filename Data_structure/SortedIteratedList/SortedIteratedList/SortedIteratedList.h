#pragma once
// DO NOt INCLUDE LISTITERATOR

// DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111

class Node;

typedef Node *PNode;

class Node
{
private:
	TComp element;
	PNode next_node;

public:
	friend class SortedIteratedList;
	Node();
	TComp info() const { return element; }
	PNode next() const { return this->next_node; };
};

class SortedIteratedList
{
private:
	friend class ListIterator;

private:
	// TODO - Representation

	PNode head;
	PNode tail;

	int size_list;

	Relation relation;

public:
	// constructor
	SortedIteratedList(Relation r);

	// returns the number of elements from the list
	int size() const;

	// verifies if the list is empty
	bool isEmpty() const;

	// returns the first position from the list
	ListIterator first() const;

	// returns the element from the given position
	// throws an exception if the position is not valid
	TComp getElement(ListIterator pos) const;

	// adds a new element to the list
	void add(TComp e);

	// removes the element from position pos
	// returns the removed element
	// after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed
	// throws an exception if the position is not valid
	TComp remove(ListIterator &poz);

	// searches for the first occurrence of an element
	// returns an iterator that points to the element, if it appear in the list, or an invalid iterator if the element is not in the list
	ListIterator search(TComp e) const;

	// TODO elimina
	void print_list();

	// destructor
	~SortedIteratedList();
};
