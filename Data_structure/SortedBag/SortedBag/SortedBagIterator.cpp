#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b)
{
	// TODO - Implementation
	this->current_elem = 0;
	this->current_freq = 0;
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
		return this->bag.elements[this->current_elem].element;
	}
}

bool SortedBagIterator::valid()
{
	// TODO - Implementation
	return (this->current_elem < this->bag.number_elem && this->current_freq < this->bag.elements[this->current_elem].freq);
}

void SortedBagIterator::next()
{
	// TODO - Implementation
	if (!valid())
	{
		throw exception();
	}
	else
	{
		this->current_freq++;
		if (this->current_freq == this->bag.elements[this->current_elem].freq)
		{
			this->current_elem++;
			this->current_freq = 0;
		}
	}
}

void SortedBagIterator::first()
{
	// TODO - Implementation
	this->current_elem = 0;
	this->current_freq = 0;
}