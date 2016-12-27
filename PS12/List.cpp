
#include "List.h"
#include "ListNode.h"
#include "Settings.h"

namespace cs52 {

	//head points to NULL. The list has 0 elements; size 0.
	List::List() {
		head = NULL;
		listSize = 0;
	}
	//DESTRUCTOR
	List::~List() {
#ifdef SHOW_DESTRUCTOR_CALLS
		std::cout << "about to--> makeEmpty();" << std::endl;
#endif
		makeEmpty();
#ifdef SHOW_DESTRUCTOR_CALLS
		std::cout << "about to--> delete( head );" << std::endl;
#endif
		delete(head);
	}
	//returns TRUE if list IS EMPTY
	bool List::isEmpty() const {
		return(head == NULL);
	}

	//deletes all nodes.
	void List::makeEmpty() {
		while (head != NULL) {
			remove(head->getElement());
		}
	}

	int List::size() const {
		return(listSize);
	}

	void List::insert(const int& data) {
		// place data into a ListNode at the front of the list
		// it will move the head node to behind the node 
		//    we create dynamically
		ListNode* temp = head;
		ListNode* newnode = new ListNode(data);
		head = newnode;
		newnode->setNext(temp);
		listSize++;
	}


	//add node with user specified data to the end of the list.
	void List::append(const int& data) {

		if (head == NULL) {

			insert(data);
		}

		else {
			//make a temporary pointer that  points to the new node (new node should be pointing to NULL)
			ListNode* tempPtr = new ListNode(data);

			//make another pointer that iterates through the list (starting at HEAD) until it finds the last node.
			ListNode* lastNode = head;
			while ((lastNode->getNext()) != NULL) {
				lastNode = lastNode->getNext();
			}
			//lastNode should now point to the last node of the original list.

			//it should now point to the new node, making it the penultimate.
			lastNode->setNext(tempPtr);
		}
		listSize++;
	} 

	//append the second list onto the first list. This should only modify the first list and NOT THE SECOND.
	void List::concatenate(const List& B) {

		//if ListB is empty, there's nothing to concatenate. Do nothing.

		if (B.head != NULL) {
		//iterate through list B using a pointer until it's NULL.
		//append to this(list1) using append f(x)
			ListNode* iter = B.head;
			for (iter = B.head; iter != NULL; iter = iter->getNext()) {

				append((iter->getElement()));

			} //end FORLOOP
		} //end IF

	}


	//The user will give a position in which to insert a node with specific data.
	//insert that node onto the pre-existing list.
	void List::insertith(const int& data, const size_t& i) {

		//spawning the new node with desired data.
		ListNode* temp = new ListNode(data);
		int iter(0); //iterator

		//if it's bigger, or zero!
		if ( (i > listSize) || (isEmpty()) ) 
			append(data);
		else if (i == 1) {
			insert(data);
		}
		else { //this clause executes if i > 1
			ListNode* afterMe = head;
			for (iter = 1; iter < (i-1); iter++) {
				afterMe = afterMe->getNext();
			}
			//afterMe now points to node BEFORE desired position
			temp->setNext(afterMe->getNext());
			afterMe->setNext(temp);
			listSize++;
		}

}

//REMOVE DUPS:
//remove duplicates from the linked list. The first instance of an int should be kept. All of the following instances 
	//are to be removed.

	void  List::removeDups() {
		//if list is empty or has single elements, it can't have duplicates. 
		//if list isn't empty or has a single element...
		if ((head != NULL) || ((head->getNext()) != NULL)) {
			//deleteMe ptr to avoid mem leaks.
			ListNode* deleteMe = NULL;
			ListNode* mainPtr = head;
			//while there is more than a single node left to traverse...
			while ((mainPtr != NULL) && (mainPtr->getNext() != NULL)) {
				//spawn another pointer that will allow you to KEEP nodes.
				ListNode* curr = mainPtr;
				while (curr->getNext() != NULL) {
					//if it's a duplicate...
					if ((mainPtr->getElement() == (curr->getNext()->getElement()))) {
						deleteMe = curr->getNext();
						curr->setNext(curr->getNext()->getNext());
						//delete it
						delete deleteMe;
						listSize--;
					}//end duplicate if
					else {
						curr = curr->getNext();
					}//end duplicate else
				}//end internal while
				mainPtr = mainPtr->getNext();
			}//end external while
		}//end main if
	}



	void List::remove(const int& data) {
		ListNode* current = head;
		ListNode* previous = NULL;
		ListNode* nodeToRemove = NULL;
		while (current != NULL) {
			// have we found it at the current node???
			if (current->getElement() == data) {
				// found it at head node
				if (previous == NULL) {
					nodeToRemove = head;
					head = head->getNext();
				}
				// found it inside the list somewhere
				else {
					nodeToRemove = current;
					// skip the current node
					previous->setNext(current->getNext());
				}
				delete(nodeToRemove);
				listSize--;
				break;
			}
			// keep looking
			else {
				previous = current;
				current = current->getNext();
			}
		}
	}

	std::ostream& operator << (std::ostream& outs, const List& l) {
		return(l.printList(outs));
	}

	std::ostream& operator << (std::ostream& outs, const List* l) {
		return(l->printList(outs));
	}

	std::ostream& List::printList(std::ostream& outs) const {
		if (isEmpty())
			outs << "Empty List" << std::endl;
		else {
			outs << "List has " << size() << " elements: " << std::endl;
			ListNode* current = head;
			while (current != NULL) {
				outs << current->getElement() << " -> ";
				current = current->getNext();
			}
			outs << " NULL";
			outs << std::endl;
		}
		return(outs);
	}



}
