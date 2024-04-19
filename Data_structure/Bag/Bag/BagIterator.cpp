#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

// constant
BagIterator::BagIterator(const Bag &c) : bag(c)
{
	// TODO - Implementation
	current_element= bag.headLink;
	current_frequency = 0;
}

// constant
void BagIterator::first()
{
	// TODO - Implementation
	current_element = bag.headLink;
}

// constant
void BagIterator::next()
{
	// TODO - Implementation
	if (valid())
	{
		if (current_frequency < bag.elements[current_element].frequency - 1)
			current_frequency++;
		else
		{
			current_element = bag.nextLink[current_element];
			current_frequency = 0;
		}
	
	}
	else
		throw exception();
}

// constant
bool BagIterator::valid() const
{
	// TODO - Implementation
	if (current_element != -1)
		return true;
	else
		return false;
}

// constant
TElem BagIterator::getCurrent() const
{
	// TODO - Implementation
	if (!valid())
		throw exception();
	else
		return bag.elements[current_element].element;
}
