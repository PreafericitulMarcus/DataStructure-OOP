#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

bool rel(TElem e1, TElem e2){
	if (e1 <= e2){
		return true;
	} else {
		return false;
	}
}

void Bag::resize() {

	//We allocate a new array with double capacity somewhere in the computer's memory
	TElem *eNou = new int[2 * cp];

	//We copy all the elements from the old array into the new array
	for (int i = 0; i < n; i++)
		eNou[i] = e[i];

	//We double the capacity
	cp = 2 * cp;

	//We release the memory space occupied by the old array
	delete[] e;

	//We make the field e to refer the new array (with double capacity)
	e = eNou;
}


Bag::Bag() {
	//We initialize the capacity
	this->cp = 1;

	//We allocate memory space for an array with at most cp TElems
	e = new TElem[cp];

	//We initialize the number of elements
	this->n = 0;
}


void Bag::add(TElem elem) {
	//If the maximum capacity has been reached, then we resize the array of elements
	if (n == cp)
		resize();

	//We add the element to the end of the array
	this->e[n++] = elem;
}


bool Bag::remove(TElem elem) {
    //We start searching for the element to be deleted (one occurrence only!) from index 0
	bool found = false;
	int i = 0;
	//While we still have elements to compare the element to be deleted to and we haven't found
	//(and deleted) the element
	while (i<this->n && !found){
		//We compare the current element with the one to be deleted
		//If they are equal
		if (this->e[i]==elem){
			//We just found the element
			found = true;
			//So we delete it, by shifting all the elements starting from index i+1 one position to the left
			for (int j = i; j < n-1; j++){
				this->e[j] = this->e[j+1];
			}
			//And we decrement the size
			this->n--;
		//If the current element is not equal to the one we are searching for
		} else {
			//, then we just increase the index in order to advance in traversing the array of elements
			i++;
		}
	}
	return found;
}


bool Bag::search(TElem elem) const {
	//We traverse the array of elements
	for (int i=0; i<n; i++){
		//and compare each element in the array with the element we are searching for
		//If the two are equal then we just return true (and exist the loop)
		if (this->e[i]==elem){
			return true;
		}
	}
	//If we existed the loop with i=n (so we haven't found the element), we return false to indicate
	//that the element does not appear in the bag
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	//We initialize the number of occurrences with 0 since we assume that the element does not appear in the bag
	int nrO = 0;
	//We traverse the array of elements
	for (int i=0; i<n; i++){
		    //and compare the current element in the traversal with the element we want the number of occurrences for
		    //If the two are equal, then we just found a new occurrence of the element, so we increase the current
		    //number of occurrences
			if (this->e[i]==elem){
				nrO++;
			}
		}
	//Finally, we return the resulted number of occurrences
	return nrO;
}


int Bag::size() const {
	//We just return the value of the field n which is indeed the exactly the current number of elements the bag contains
	return this->n;
}


bool Bag::isEmpty() const {
	//The bag is empty if and only if the current number of elements is 0
	return (n==0);
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//We free the memory space allocated for the array of elements
	delete[] e;
}