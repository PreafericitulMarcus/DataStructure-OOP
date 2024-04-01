#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>
#include <iostream>
using std::cout;

using namespace std;

ListIterator::ListIterator(const SortedIteratedList &list) : list(list)
{
	// TODO - Implementation
	this->current = list.head;
}

void ListIterator::first()
{
	// TODO - Implementation
	this->current = list.head;
}

void ListIterator::next()
{
	// TODO - Implementation
	if (!valid())
	{
		throw exception();
	}
	else
	{
		this->current = current->next();
	}
}

bool ListIterator::valid() const
{
	// TODO - Implementation
	if (this->current == nullptr)
		return false;
	return true;
}

TComp ListIterator::getCurrent() const
{
	// TODO - Implementation
	if (!valid())
		throw exception();
	return this->current->info();
}
