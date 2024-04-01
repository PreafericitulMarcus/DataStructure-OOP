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
	if (!poz.valid())
		throw exception();
	PNode current = head;
	PNode previous = nullptr;
	while (current != nullptr and current->info() != poz.getCurrent())
	{
		previous = current;
		current = current->next();
	}
	if (current != nullptr and previous == nullptr) // means there is only 1 node, the head
		head = head->next();
	else if (current != nullptr)
		previous->next_node = current->next();
	TComp removed_element = current->info();
	delete current;
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
		return ListIterator(*this);
	return it;
}

void SortedIteratedList::add(TComp e)
{
	// TODO - Implementation
	PNode new_node = new Node();
	new_node->element = e;
	size_list++;
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
	size_list++;
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
