#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <utility>

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

	if (search(e)) // check if element is in the bag
	{
		int middle;
		bool found = false;
		int left = 0;
		int right = this->number_elem - 1;
		while (left < right && !found)
		{
			middle = (left + right) / 2;
			if (this->elements[middle].element == e)
				found = true;
			if (this->elements[middle].element < e)
				left = middle + 1;
			else
				right = middle - 1;
		}
		this->elements[middle].freq++;
	}
	else // element is not in the bag
	{
		if (relation(e, this->elements[0].element)) // check if the element should be added to the left
		{
			if (this->number_elem == this->capacity)
				resize();
			else
			{
				for (int i = this->number_elem; i > 0; i--)
					this->elements[i].element = this->elements[i - 1].element;
				this->elements[0].element = e;
				this->elements[0].freq = 1;
			}
		}
		else if (relation(this->elements[this->number_elem].element, e)) // check if the element should be added to the right
		{
			if (this->number_elem == this->capacity)
				resize();
			else
			{
				this->elements[this->number_elem].element = e;
				this->elements[this->number_elem].freq = 1;
			}
		}
		else // element should be added inside the bag
		{
			int left = 0;
			int right = this->number_elem;
			int middle;
			while (left < right)
			{
				middle = (left + right) / 2;
				if (this->elements[middle].element < e)
					left = middle + 1;
				else
					right = middle - 1;
			}
			if (this->number_elem == this->capacity)
				resize();
			else
			{
				for (int i = this->number_elem; i > middle; i--)
					this->elements[i].element = this->elements[i - 1].element;
				this->elements[middle].element = e;
				this->elements[middle].freq = 1;
			}
		}
	}
}

bool SortedBag::remove(TComp e)
{
	// TODO - Implementation
	bool removed = false;
	if (relation(e, (elements[0].element)) || relation(e, elements[number_elem].element))
	{
		return false;
	}
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
					elements[i] = elements[i + 1];
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
	if (relation(elem, (elements[0].element)) || relation(elem, elements[number_elem].element))
	{
		return false;
	}
	int left = 0;
	int right = this->number_elem - 1;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (this->elements[middle].element == elem)
			return true;
		if (this->elements[middle].element < elem)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return false;
}

int SortedBag::nrOccurrences(TComp elem) const
{
	// TODO - Implementation
	if (relation(elem, (elements[0].element)) || relation(elem, elements[number_elem].element))
	{
		return 0;
	}
	for (int i = 0; i < this->number_elem; i++)
	{
		if (this->elements[i].element == elem)
		{
			return this->elements[i].freq;
		}
	}
	return 0;
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
