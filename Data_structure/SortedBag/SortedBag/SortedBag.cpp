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
	this->number_elem_ocurrences = 0;
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
		int left = 0;
		int right = number_elem - 1;
		bool found = false;
		while (left < right and !found)
		{
			int middle = (left + right) / 2;
			if (this->elements[middle].element == e)
			{
				elements[middle].freq++;
				number_elem_ocurrences++;
				found = true;
			}
			if (this->elements[middle].element < e)
				left = middle + 1;
			else
				right = middle - 1;
		}
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
			number_elem_ocurrences++;
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
			number_elem_ocurrences++;
		}
	}
}

bool SortedBag::remove(TComp e)
{
	// TODO - Implementation
	bool removed = false;
	if (search(e))
	{
		for (int i = 0; i < number_elem and !removed; i++)
		{
			if (elements[i].element == e and elements[i].freq > 1)
			{
				elements[i].freq--;
				number_elem_ocurrences--;
				return true;
			}
			else if (elements[i].element == e and elements[i].freq == 1)
			{
				for (int j = i; j < number_elem - 1; j++)
					elements[j] = elements[j + 1];
				number_elem--;
				number_elem_ocurrences--;
				return true;
			}
		}
	}
	// cout << number_elem;

	// for (int i = 0; i < number_elem; i++)
	// 	cout << elements[i].element << ' ' << elements[i].freq << '\n';
	// cout << '\n';
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
	// int right = number_elem - 1;
	// bool found = false;
	// while (left < right and !found)
	// {
	// 	int middle = (left + right) / 2;
	// 	if (this->elements[middle].element == elem)
	// 		found = true;
	// 	if (this->elements[middle].element < elem)
	// 		left = middle + 1;
	// 	else
	// 		right = middle - 1;
	// }
	// return found;
}

int SortedBag::nrOccurrences(TComp elem) const
{
	// TODO - Implementation
	int count = 0;
	for (int i = 0; i < number_elem; i++)
	{
		if (elements[i].element == elem)
		{
			count += elements[i].freq;
		}
	}
	return count;
}

int SortedBag::size() const
{
	// TODO - Implementation
	cout<<number_elem<<'\n\n'
		<<"    ";
	return number_elem_ocurrences;
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
