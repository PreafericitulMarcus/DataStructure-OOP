#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

// Titha(capacity)
Bag::Bag()
{
	// TODO - Implementation
	capacity = 10;
	elements = new Pairs[capacity];
	nextLink = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		nextLink[i] = -1;
	}
	headLink = -1; 
	firstEmpty = 0;
	numberElements = 0;
	numberPairs = 0;
}

void Bag::print_list()
{
	int currentLink = headLink;
	for (int i = 0; i < capacity; i++)
		cout << elements[i].element << " ";
}

// O(numberPairs)
void Bag::add(TElem elem)
{
	int currentLink = headLink;
	bool added = false;

	// Traverse the list to find if the element already exists
	while (currentLink != -1 && !added)
	{
		if (elements[currentLink].element == elem)
		{
			// Element found, increase its frequency
			elements[currentLink].frequency++;
			numberElements++;
			added = true;
		}
		currentLink = nextLink[currentLink];
	}

	// If the element was not found in the list, add it
	if (!added)
	{
		if (firstEmpty == capacity)
		{
			// If the list is full, resize it
			capacity *= 2;
			Pairs *newElements = new Pairs[capacity];
			int *newNextLink = new int[capacity];
			for (int i = 0; i < numberPairs; i++)
			{
				newElements[i] = elements[i];
				newNextLink[i] = nextLink[i];
			}
			delete[] elements;
			delete[] nextLink;
			elements = newElements;
			nextLink = newNextLink;
		}

		// Add the new element at the first empty spot
		elements[firstEmpty].element = elem;
		elements[firstEmpty].frequency = 1;
		nextLink[firstEmpty] = headLink;
		headLink = firstEmpty;
		firstEmpty++;
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
	while (currentLink != -1)
	{
		if (elements[currentLink].element == elem)
			return true;
		currentLink = nextLink[currentLink];
	}
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
	if (headLink == -1)
		return true;
	else
		return false;
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
