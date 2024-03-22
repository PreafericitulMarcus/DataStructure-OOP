#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation

	int current_elem;
	int current_freq;

public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

