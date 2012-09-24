#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;


LinkedList::LinkedList(){
	head_ = NULL;
	num_items_ = 0;
}

/*
* Adds a node to the left of the head node and makes the
* necessary adjustments to the prev and next data for all nodes
* invovled in the addition
*/
void LinkedList::addNode(int info){
	if( head_==NULL ) {
        head_ = new Node(info, NULL, NULL);
        head_->next = head_->prev = head_; 
    } 
	else {
        Node *node = new Node(info, head_->prev, head_);
        node->prev->next = node;
        node->next->prev = node;
	}
}

/*
* Finds the data point (type int) of the node at that index
* in the list.  Not quite working right yet.  Only returns 1, 2, or 4.
* 
*/
int LinkedList::getData(int index){
	int i = 0;
	Node* pointer = head_;
	while(i < index && pointer->next != head_){
		Node* temp = pointer;
		pointer = pointer->next;
		i++;
	}
	return pointer->next->data;
}

/*
* Cycles through the list moving each node one place to the right
* and making the tail become the head
*/
void LinkedList::cycle(){
	if(head_ != NULL){
		Node* temp = head_;
		Node* end;
		Node* tempPrev;
		while (true){
			tempPrev = temp;
			temp = temp->next;
			temp->prev = tempPrev;
			// Not sure if this is all that I need to do to update
			// the prev and next pointers.  I think I might've missed something here.
			if (temp->next == head_){
				end = temp;
				break;
			}
		}
		Node* tempHead = head_;
		head_ = end;
		end = tempHead;
	}
	else{
		// don't do anything, there is nothing to cycle through
	}
}
/*
* Reverses the order of the list.  This code was based off of Dr. Brinkman's
* class lecture on how to implement reverse for singly and doubly linke lists
*
*/
void LinkedList::reverse(){
	Node* current = head_;
	do{
		Node* temp = current->next;
		current->next=current->prev;
		current->prev=temp;
		current = current->prev;
	}
	while(current != head_);
}