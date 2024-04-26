#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

Bag::Bag()
{
	// TODO - Implementation
	hashTableSize = 10;
	hashTable = new Node *[hashTableSize];
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = nullptr;
	}
	numberPairs = 0;
	numberElements = 0;
}

int Bag::hashFunction(TElem e) const
{
	return abs(e) % hashTableSize;
}

void Bag::resizeHashTable()
{
	int oldSize = hashTableSize;
	Node **oldTable = hashTable;

	// Double the size of the hash table
	hashTableSize *= 2;
	hashTable = new Node *[hashTableSize];

	// Initialize the new hash table
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = nullptr;
	}

	// Rehash all elements
	for (int i = 0; i < oldSize; i++)
	{
		Node *node = oldTable[i];
		while (node != nullptr)
		{
			// Calculate the new hash value and insert the element into the new table
			int hashPosition = hashFunction(node->pair.element);
			Node *nextNode = node->nextNode;
			node->nextNode = hashTable[hashPosition];
			hashTable[hashPosition] = node;
			node = nextNode;
		}
	}

	// Delete the old hash table
	delete[] oldTable;
}

void Bag::add(TElem elem)
{
	// TODO - Implementation
	int hashPosition = hashFunction(elem);

	// Check if the element is already in the hash table to increase frequency
	Node *currentNode = hashTable[hashPosition];
	Node *previousNode = nullptr;
	while (currentNode != nullptr && currentNode->pair.element != elem)
	{
		previousNode = currentNode;
		currentNode = currentNode->nextNode;
	}

	if (currentNode != nullptr && currentNode->pair.element == elem)
	{
		// If the element is found, increase its frequency
		currentNode->pair.frequency++;
		numberElements++;
	}
	else
	{
		// If the element is not found, create a new node for it
		Node *newNode = new Node;
		newNode->pair.element = elem;
		newNode->pair.frequency = 1;
		newNode->nextNode = nullptr;

		// If the bucket is empty, add the new node to the bucket
		// Otherwise, add the new node to the end of the bucket's linked list
		if (previousNode == nullptr)
			hashTable[hashPosition] = newNode;
		else
			previousNode->nextNode = newNode;

		numberElements++;
		numberPairs++;
	}
	// resize
	float loadFactor = (float)numberElements / hashTableSize;
	if (loadFactor > 0.7)
	{
		// If the load factor exceeds 0.7, resize the hash table
		resizeHashTable();
	}
}

bool Bag::remove(TElem elem)
{
	// TODO - Implementation
	for (int i = 0; i < hashTableSize; i++)
	{
		Node *currentNode = hashTable[i];
		Node *previousNode = nullptr;
		while (currentNode != nullptr && currentNode->pair.element != elem)
		{
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
		if (currentNode != nullptr && currentNode->pair.element == elem)
			if (currentNode->pair.frequency > 1)
			{
				// decrease frequency
				currentNode->pair.frequency--;
				numberElements--;
				return true;
			}
			else
			{
				// prevoius is the first node
				if (previousNode == nullptr)
					hashTable[i] = currentNode->nextNode;
				else // jump over the current node
					previousNode->nextNode = currentNode->nextNode;

				delete currentNode;

				numberElements--;
				numberPairs--;

				return true;
			}
	}
	return false;
}

bool Bag::search(TElem elem) const
{
	// TODO - Implementation
	for (int i = 0; i < hashTableSize; i++)
	{
		Node *currentNode = hashTable[i];
		while (currentNode != nullptr && currentNode->pair.element != elem)
			currentNode = currentNode->nextNode;
		if (currentNode != nullptr && currentNode->pair.element == elem)
		{
			return true;
		}
	}
	return false;
}

int Bag::nrOccurrences(TElem elem) const
{
	// TODO - Implementation
	for (int i = 0; i < hashTableSize; i++)
	{
		Node *currentNode = hashTable[i];
		while (currentNode != nullptr && currentNode->pair.element != elem)
			currentNode = currentNode->nextNode;
		if (currentNode != nullptr && currentNode->pair.element == elem)
			return currentNode->pair.frequency;
	}
	return 0;
}

int Bag::size() const
{
	// TODO - Implementation
	return numberElements;
}

bool Bag::isEmpty() const
{
	// TODO - Implementation
	return (numberElements == 0);
}

BagIterator Bag::iterator() const
{
	return BagIterator(*this);
}

void Bag::printList()
{
	for (int i = 0; i < hashTableSize; i++)
	{
		Node *currentNode = hashTable[i];
		while (currentNode != nullptr)
		{
			cout << "Bucket " << i << ": Element " << currentNode->pair.element << ", Frequency " << currentNode->pair.frequency << endl;
			currentNode = currentNode->nextNode;
		}
	}
}

Bag::~Bag()
{
	// TODO - Implementation
	for (int i = 0; i < hashTableSize; i++)
	{
		Node *currentNode = hashTable[i];
		while (currentNode != nullptr)
		{
			Node *nextNode = currentNode->nextNode;
			delete currentNode;
			currentNode = nextNode;
		}
	}

	delete[] hashTable;
}
