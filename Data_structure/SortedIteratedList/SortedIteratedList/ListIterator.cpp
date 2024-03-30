#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

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
	if (valid())
		this->current->next();
	else
		throw exception();
}

bool ListIterator::valid() const
{
	// TODO - Implementation
	return (this->current != nullptr);
}

TComp ListIterator::getCurrent() const
{
	// TODO - Implementation
	if (!valid())
		throw exception();
	return this->current->info();
}
