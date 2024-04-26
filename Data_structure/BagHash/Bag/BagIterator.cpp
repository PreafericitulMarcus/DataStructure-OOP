#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>
using std::cout;

using namespace std;

BagIterator::BagIterator(const Bag &c) : bag(c)
{
	// TODO - Implementation
	currentPosition = 0;

	// Initialize currentNode to the first non-null node in the hash table
	currentNode = bag.hashTable[currentPosition];
	while (currentPosition < bag.hashTableSize && bag.hashTable[currentPosition] == nullptr)
		currentPosition++;
	if (currentPosition < bag.hashTableSize)
	{
		currentNode = bag.hashTable[currentPosition];
		currentFrequency = currentNode->pair.frequency;
	}
	else
	{
		currentNode = nullptr;
		currentFrequency = 0;
	}
}

void BagIterator::first()
{
	currentPosition = 0;

	currentNode = bag.hashTable[currentPosition];
	while (currentPosition < bag.hashTableSize && bag.hashTable[currentPosition] == nullptr)
		currentPosition++;
	if (currentPosition < bag.hashTableSize)
	{
		currentNode = bag.hashTable[currentPosition];
		currentFrequency = currentNode->pair.frequency;
	}
	else
	{
		currentNode = nullptr;
		currentFrequency = 0;
	}
}

void BagIterator::next()
{
	if (!valid())
	{
		throw exception();
	}
	cout << currentNode->pair.element << ' ' << currentNode->pair.frequency << ' ' << currentFrequency << endl;
	if (currentNode != nullptr && currentFrequency < currentNode->pair.frequency)
	{
		currentFrequency++;
	}
	else
	{
		currentNode = currentNode->nextNode;
		if (currentNode == nullptr)
		{
			currentPosition++;
			while (currentPosition < bag.hashTableSize && bag.hashTable[currentPosition] == nullptr)
				currentPosition++;
			if (currentPosition < bag.hashTableSize)
				currentNode = bag.hashTable[currentPosition];
		}
		if (currentNode != nullptr)
		{
			currentElement = currentNode->pair.element;
			currentFrequency = 1;
		}
	}
}

bool BagIterator::valid() const
{
	if (bag.isEmpty())
		return false;
	return (currentNode != nullptr && currentPosition < bag.hashTableSize - 1);
}

TElem BagIterator::getCurrent() const
{
	// TODO - Implementation
	if (!valid())
		throw exception();

	return currentNode->pair.element;
}
