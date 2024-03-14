#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <utility>
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r)
{
	// TODO - Implementation
	this->capacity = 1;
	this->elements = new Pair[capacity];
	this->number_elem = 0;
	this->relation = r;
}

void SortedBag::resize()
{
	Pair *new_elements = new Pair[2 * capacity];
	for (int i = 0; i <= number_elem; i++)
		new_elements[i] = elements[i];

	capacity = 2 * capacity;

	delete[] elements;

	this->elements = new_elements;
}

void SortedBag::add(TComp e)
{
	// TODO - Implementation
	if (search(e)) // increase frequency if the element is already in the bag
	{
		for (int i = 0; i < number_elem; i++)
			if (elements[i].element == e)
				elements[i].freq++;
	}
	else // add the element in the bag
	{
		if (number_elem == capacity) // resize if the bag is full
			resize();
		if (number_elem == 0) // add the first element in the bag
		{
			elements[0].element = e;
			elements[0].freq = 1;
			number_elem++;
		}
		else // add the element in the bag
		{
			int i = number_elem - 1;
			while (i >= 0 && relation(e, elements[i].element)) // go backwords in the bag and add the element in the correct position
			{
				elements[i + 1] = elements[i]; // shift the elements to the right to make way for the new element
				i--;
			}
			elements[i + 1].element = e;
			elements[i + 1].freq = 1;
			number_elem++;
		}
		for (int i = 0; i < number_elem; i++)
			cout << elements[i].element << ' ' << elements[i].freq << '\n';
		cout << '\n';
	}
}

bool SortedBag::remove(TComp e)
{
	// TODO - Implementation
	bool removed = false;
	if (search(e))
	{
		int left = 0;
		int right = this->number_elem - 1;
		while (left < right && !removed)
		{
			int middle = (left + right) / 2;
			if (this->elements[middle].element == e)
			{
				removed = true;
				for (int i = middle; i < number_elem - 1; i++)
				{
					elements[i] = elements[i + 1];
					// cout << elements[i].element << ' ' << elements[i].freq << '\n';
				}
				number_elem -= 1;
			}
			else if (this->elements[middle].element < e)
				left = middle + 1;
			else
				right = middle - 1;
		}
	}
	return removed;
}

bool SortedBag::search(TComp elem) const
{
	// TODO - Implementation
	for (int i = 0; i < number_elem; i++)
		if (elements[i].element == elem)
			return true;
	return false;
	// int left = 0;
	// int right = this->number_elem - 1;
	// while (left < right)
	// {
	// 	int middle = (left + right) / 2;
	// 	if (this->elements[middle].element == elem)
	// 		return true;
	// 	if (this->elements[middle].element < elem)
	// 		left = middle + 1;
	// 	else
	// 		right = middle - 1;
	// }
	// return false;
}

int SortedBag::nrOccurrences(TComp elem) const
{
	// TODO - Implementation
	int count = 0;
	for (int i = 0; i < number_elem; i++)
	{
		if (elements[i].element == elem)
		{
			// cout << elements[i].element << ' ' << elements[i].freq << ' ' << count << ' ';
			count += elements[i].freq;
		}
	}
	return count;
}

int SortedBag::size() const
{
	// TODO - Implementation
	return this->number_elem;
}

bool SortedBag::isEmpty() const
{
	// TODO - Implementation
	return (this->number_elem == 0);
}

SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

SortedBag::~SortedBag()
{
	// TODO - Implementation
	delete[] this->elements;
}
