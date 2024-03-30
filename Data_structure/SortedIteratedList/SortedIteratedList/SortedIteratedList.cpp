#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r)
{
	// TODO - Implementation
	this->relation = r;
	this->head = nullptr;
	this->size_list = 0;
}

Node::Node()
{
	this->element = 0;
	this->next_node = nullptr;
}

int SortedIteratedList::size() const
{
	// TODO - Implementation
	return size_list;
}

bool SortedIteratedList::isEmpty() const
{
	// TODO - Implementation
	if (head == nullptr)
		return true;
	return false;
}

ListIterator SortedIteratedList::first() const
{
	// TODO - Implementation
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const
{
	// TODO - Implementation
	PNode current = head;
	while (current != nullptr)
	{
		if (current->info() == poz.getCurrent())
			return current->info();
		current = current->next();
	}
	throw exception();
}

TComp SortedIteratedList::remove(ListIterator &poz)
{
	// TODO - Implementation
	return NULL_TCOMP;
}

ListIterator SortedIteratedList::search(TComp e) const
{
	// TODO - Implementation
	return ListIterator(*this);
}

void SortedIteratedList::add(TComp e)
{
	// TODO - Implementation
}

SortedIteratedList::~SortedIteratedList()
{
	// TODO - Implementation
	while (head != nullptr)
	{
		PNode p = head;
		head = head->next_node;
		delete p;
	}
}
