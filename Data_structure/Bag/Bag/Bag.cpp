#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

// Titha(capacity)
Bag::Bag()
{
	// TODO - Implementation
	numberElements = 0;
	numberPairs = 0;
	capacity = 1000;

	headLink = -1;
	for (int i = 1; i < capacity - 1; i++)
		nextLink[i] = i + 1;
	firstEmpty = 0;
	nextLink[capacity - 1] = -1;
}

void Bag::resize()
{
	int newCapacity = 2 * capacity;
	Pairs *newElements = new Pairs[newCapacity];
	int *newNextLink = new int[newCapacity];

	for (int i = 0; i < capacity; i++)
	{
		newElements[i] = elements[i];
		newNextLink[i] = nextLink[i];
	}

	for (int i = capacity; i < newCapacity - 1; i++)
		newNextLink[i] = i + 1;
	newNextLink[newCapacity - 1] = -1;

	delete[] elements;
	delete[] nextLink;

	elements = newElements;
	nextLink = newNextLink;
	firstEmpty = newCapacity + 1;
	capacity = newCapacity;
}

// O(numberPairs)
void Bag::add(TElem elem)
{
	// TODO - Implementation

	// first we check if the element is already in the list. if so we increment the frequency
	int currentLink = headLink;
	bool added = false;
	while (currentLink != -1 && !added)
	{
		if (elements[currentLink].element == elem)
		{
			elements[currentLink].frequency++;
			numberElements++;
			added = true;
		}
		currentLink = nextLink[currentLink];
	}

	if (added == false)
	{
		// check if the list if full
		if (firstEmpty == -1)
			resize();

		// save the element in the first empty spot
		elements[firstEmpty].element = elem;
		elements[firstEmpty].frequency = 1;

		// save the index of the empty spot
		int newEmpty = nextLink[firstEmpty];

		// link the element to the list
		nextLink[firstEmpty] = headLink;

		// update the firstEmpty to the next empty spot
		firstEmpty = newEmpty;

		numberElements++;
		numberPairs++;
	}
}

// O(numberPairs)
bool Bag::remove(TElem elem)
{
	// TODO - Implementation
	int currentLink = headLink;
	int prevoiusLink = -1;
	while (currentLink != -1 && elements[currentLink].element != elem)
	{
		prevoiusLink = currentLink;
		currentLink = nextLink[currentLink];
	}
	if (currentLink != -1)
	{
		if (elements[currentLink].element == elem && elements[currentLink].frequency > 1)
		{
			elements[currentLink].frequency--;
			numberElements--;
		}
		else
		{
			if (currentLink == headLink)
				headLink = nextLink[headLink];
			else
				nextLink[prevoiusLink] = nextLink[currentLink];
			nextLink[currentLink] = firstEmpty;
			firstEmpty = currentLink;
			numberElements--;
			numberPairs--;
		}
		return true;
	}
	else
		return false;
}

// O(numberPairs)
bool Bag::search(TElem elem) const
{
	// TODO - Implementation
	int currentLink = headLink;
	while (currentLink != -1 && elements[currentLink].element != elem)
		currentLink = nextLink[currentLink];
	if (elements[currentLink].element == elem)
		return true;
	return false;
}

// O(numberPairs)
int Bag::nrOccurrences(TElem elem) const
{
	// TODO - Implementation
	int currentLink = headLink;
	int counter = 0;
	while (currentLink != -1) // while not at the end, go through the array and increment if element is found
	{
		if (elements[currentLink].element == elem)
			counter += elements[currentLink].frequency;
		currentLink = nextLink[currentLink];
	}
	return counter;
}

// constant
int Bag::size() const
{
	// TODO - Implementation
	return numberElements;
}

// constant
bool Bag::isEmpty() const
{
	// TODO - Implementation
	return (headLink == -1);
}

BagIterator Bag::iterator() const
{
	return BagIterator(*this);
}

// constant
Bag::~Bag()
{
	// TODO - Implementation
	// delete the list of elements and the list of links
	delete[] elements;
	delete[] nextLink;
}
