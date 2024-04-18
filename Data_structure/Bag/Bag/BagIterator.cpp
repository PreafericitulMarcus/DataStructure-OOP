#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//constant
BagIterator::BagIterator(const Bag &c) : bag(c)
{
	// TODO - Implementation
	current = bag.headLink;
}

//constant
void BagIterator::first()
{
	// TODO - Implementation
	current = bag.headLink;
}

//constant
void BagIterator::next()
{
	// TODO - Implementation
	if (valid())
		current = bag.nextLink[current];
	else
		throw exception();
}

//constant
bool BagIterator::valid() const
{
	// TODO - Implementation
	if (current != -1)
		return true;
	else
		return false;
}

//constant
TElem BagIterator::getCurrent() const
{
	// TODO - Implementation
	if (!valid())
		throw exception();
	else
		return bag.elements[current].element;
}
