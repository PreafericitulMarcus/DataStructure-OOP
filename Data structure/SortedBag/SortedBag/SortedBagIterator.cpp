#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b)
{
	// TODO - Implementation
	this->current_elem = 0;
}

TComp SortedBagIterator::getCurrent()
{
	// TODO - Implementation
	if (!valid())
	{
		throw exception();
	}
	else
	{
		return this->bag.elements[this->current_elem];
	}
}

bool SortedBagIterator::valid()
{
	// TODO - Implementation
	return (this->current_elem < this->bag.number_elem);
}

void SortedBagIterator::next()
{
	// TODO - Implementation
	if (!valid)
	{
		throw exception();
	}
	else
	{
		this->current_elem++;
	}
}

void SortedBagIterator::first()
{
	// TODO - Implementation
	this->current_elem = 0;
}