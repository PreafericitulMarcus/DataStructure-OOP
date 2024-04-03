#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r)
{
	// TODO - Implementation
	this->relation = r;
	this->head = nullptr;
	this->tail = nullptr;
	this->size_list = 0;
}

Node::Node()
{
	this->element = 0;
	this->next_node = nullptr;
}

int SortedIteratedList::size() const
{
	// TODO - Implementation
	return size_list;
}

bool SortedIteratedList::isEmpty() const
{
	// TODO - Implementation
	if (head == nullptr)
		return true;
	return false;
}

ListIterator SortedIteratedList::first() const
{
	// TODO - Implementation
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const
{
	// TODO - Implementation
	PNode current = head;
	while (current != nullptr and current->info() != poz.getCurrent())
		current = current->next();
	if (current == nullptr)
		throw exception();
	return current->info();
}

TComp SortedIteratedList::remove(ListIterator &poz)
{
	// TODO - Implementation

	if (poz.current == nullptr) // check for invalid poz
		throw exception();

	TComp removed_element = poz.current->element;
	PNode node_to_remove = poz.current;

	if (poz.current == head)
	{
		head = head->next_node;
	}
	else
	{
		PNode current_node = head;
		while (current_node->next_node != poz.current)
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = poz.current->next_node;

		if (poz.current == tail)
			tail = current_node;
	}

	poz.current = poz.current->next_node;
	delete node_to_remove;
	size_list--;

	return removed_element;
}

ListIterator SortedIteratedList::search(TComp e) const
{
	// TODO - Implementation
	PNode current = head;
	ListIterator it = first();
	while (current != nullptr and current->info() != e)
	{
		current = current->next();
		it.next();
	}
	if (current == nullptr)
		return ListIterator(nullptr);
	return it;
}

void SortedIteratedList::add(TComp e)
{
	// TODO - Implementation
	PNode new_node = new Node();
	new_node->element = e;
	if (head == nullptr)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		PNode current = head;
		PNode previous = nullptr;
		while (current != nullptr and relation(current->info(), e))
		{
			previous = current;
			current = current->next();
		}
		if (previous == nullptr) // means that we didn't move the current pointer, so we need to add the new node at the beginning
		{
			new_node->next_node = head;
			head = new_node;
		}
		else if (current == nullptr) // means that we reached the end of the list, so we add at the end
		{
			tail->next_node = new_node;
			tail = new_node;
		}
		else // means that we are somewhere in between the head and tail
		{
			previous->next_node = new_node;
			new_node->next_node = current;
		}
	}
	size_list++;
}

void SortedIteratedList::print_list()
{
	cout << "List: ";
	PNode current = head;
	while (current != nullptr)
	{
		cout << current->info() << ' ';
		current = current->next();
	}
	cout << '\n';
}

SortedIteratedList::~SortedIteratedList()
{
	// TODO - Implementation
	while (head != nullptr)
	{
		PNode current = head;
		head = head->next_node;
		delete current;
	}
}
