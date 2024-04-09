#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

//constant complexity
SortedIteratedList::SortedIteratedList(Relation r)
{
	// TODO - Implementation
	this->relation = r;
	this->head = nullptr;
	this->tail = nullptr;
	this->size_list = 0;
}

//constant complexity
Node::Node()
{
	this->element = 0;
	this->next_node = nullptr;
}

//constant complexity
int SortedIteratedList::size() const
{
	// TODO - Implementation
	return size_list;
}

//constant complexity
bool SortedIteratedList::isEmpty() const
{
	// TODO - Implementation
	if (head == nullptr)
		return true;
	return false;
}

//constant complexity
ListIterator SortedIteratedList::first() const
{
	// TODO - Implementation
	return ListIterator(*this);
}

// BC: Titha(1)
// Wc: Titha(size_list)
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

// BC: Titha(1)
// WC: Titha(size_list)
TComp SortedIteratedList::remove(ListIterator &poz)
{
	// TODO - Implementation

	if (poz.current == nullptr) // check for invalid poz
		throw exception();

	TComp removed_element = poz.current->element;	// ititialize the removed_element with the value at the pozition
	PNode node_to_remove = poz.current;	// itialize node_to_remove to the node at the pozition

	if (poz.current == head)	// if the pozition is the head of the list we need to update the head
	{
		head = head->next_node;
	}
	else	
	{
		PNode current_node = head; // if the pozition is not the head we need to find the node before the pozition
		while (current_node->next_node != poz.current)	// we iterate through the list until we find the node before the pozition
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = poz.current->next_node;	// we update the next_node of the node before the pozition

		if (poz.current == tail)
			tail = current_node;	// if the pozition is the tail we need to update the tail
	}

	poz.current = poz.current->next_node; // we update the current node of the iterator

	delete node_to_remove;	// we delete the node at the pozition
	size_list--; // we decrement the size of the list

	return removed_element;
}

// BC: Titha(1)
// WC: Titha(size_list)
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

// BC: Titha(1)
// WC: Titha(size_list)
void SortedIteratedList::add(TComp e)
{
	// TODO - Implementation
	PNode new_node = new Node();	// create a new node
	new_node->element = e;	// set the value of the new node to e
	if (head == nullptr)	// if the list is empty we add the new node at the beginning
	{
		head = new_node;
		tail = new_node;
	}
	else	// if the list is not empty we need to find the correct position to add the new node
	{
		PNode current = head;
		PNode previous = nullptr;
		while (current != nullptr and relation(current->info(), e))	// we iterate through the list until we find the correct element
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
	size_list++;	// increment the size of the list
}

// Titha(size_list) 
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

// Titha(size_list) 
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
