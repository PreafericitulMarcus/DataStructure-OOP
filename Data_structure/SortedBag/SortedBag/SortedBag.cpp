#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <utility>
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r)
{
	// TODO - Implementation
	this->capacity = 1;					 // initial capacity
	this->elements = new Pair[capacity]; // allocate memory for the elements
	this->number_elem = 0;				 // number of elements in the bag without considering the frequency
	this->relation = r;					 // relation between the elements
	this->number_elem_ocurrences = 0;	 // number of elements in the bag considering the frequency
}

void SortedBag::resize() // resize the bag when it is full
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
	/*
	When trying to add an element in the bag, we first check if the element is already in the bag.
	If it is, we increase the frequency of the element.
	Otherwise, we add the element in the bag.
	We also resize the bag if it is full.
	We add the element in the correct position in the bag. Meaning the bag is always sorted.
	*/
	// TODO - Implementation
	if (search(e)) // increase frequency if the element is already in the bag
	{
		bool found = false;
		for (int i = 0; i < number_elem and !found; i++)
		{
			if (elements[i].element == e)
			{
				elements[i].freq++;
				number_elem_ocurrences++;
				found = true;
			}
			// ? Binary search not working. Don't know why
			// int left = 0;
			// int right = number_elem - 1;
			// bool found = false;
			// while (left < right and !found)
			// {
			// 	int middle = (left + right) / 2;
			// 	if (this->elements[middle].element == e)
			// 	{
			// 		elements[middle].freq++;
			// 		number_elem_ocurrences++;
			// 		found = true;
			// 	}
			// 	if (this->elements[middle].element < e)
			// 		left = middle + 1;
			// 	else
			// 		right = middle - 1;
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
	/*
	First we check if the element is in the bag.
	If it is, we decrease the frequency of the element.
	If the frequency is 1, we remove the element from the bag, and shift the elements to the left.

	We decrease the number of elements in the bag and/or the number of occurences of the element in the bag.

	return true if the element was removed, false otherwise.
	*/
	// TODO - Implementation
	if (search(e)) // check if the element is in the bag
	{
		for (int i = 0; i < number_elem; i++) // find the element in the bag
		{
			if (elements[i].element == e and elements[i].freq > 1) // decrease frequency if the element is in the bag and the frequency is greater than one
			{
				elements[i].freq--;
				number_elem_ocurrences--;
				return true;
			}
			else if (elements[i].element == e and elements[i].freq == 1) // remove the element from the bag if the frequency is one
			{
				for (int j = i; j < number_elem - 1; j++) // shift the elements to the left
					elements[j] = elements[j + 1];
				number_elem--;
				number_elem_ocurrences--;
				return true;
			}
		}
	}
	return false;
}

bool SortedBag::search(TComp elem) const
{
	/*
	Simple search function that iterates through the bag and checks if the element is in the bag.
	return true if the element is in the bag, false otherwise.
	*/
	// TODO - Implementation
	for (int i = 0; i < number_elem; i++)
		if (elements[i].element == elem)
			return true;
	return false;

	// ? Binary search not working. Don't know why
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
	/*
	We go through the bag and count the number of occurences of the element.
	We return the number of occurences of the element.

	? Binary search implemenation could be used here.

	*/
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
	// return the overall number of elements in the bag. Frequcnies are taken into account.
	// TODO - Implementation
	return number_elem_ocurrences;
}

bool SortedBag::isEmpty() const
{
	// return true if the bag is empty, false otherwise
	// TODO - Implementation
	return (this->number_elem == 0);
}

SortedBagIterator SortedBag::iterator() const
{
	return SortedBagIterator(*this);
}

SortedBag::~SortedBag()
{
	// free the memory allocated for the elements
	// TODO - Implementation
	delete[] this->elements;
}
