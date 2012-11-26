/** 
* @file Brush_Royal_FinalApp
* 
* @author Adam Brush
* @date 2012-09-23
* 
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 licenses (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
* 
* 
* Implementation, specifically the framework, loosely based on CBMiami019's 
* implementation for a singularly linked list
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/* 
* Create a linked list with the head_ set to Null and the number of items
* set at 0.  Head is initially not counted as an item because it has no data to begin
*/
LinkedList::LinkedList(){
	head_ = NULL;
	num_items_ = 0;
}

/*
* Adds a node to the left of the head node and makes the
* necessary adjustments to the prev and next data for all nodes
* invovled in the addition
* 
* Idea for addNode came from:
* http://www.dreamincode.net/forums/topic/251223-circular-double-linked-list-insert-method-problem/
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
* This was based loosely off of CBMiami019's singular link implementation for getData, however 
* mine is obviously meant to be used with a doubly linked circular list.
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
* 
* This part was based on CBMiami's next_in_list() function however,
* mine is meant to be used for the doubly linked list structure I have implemented
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
* Reverses the order of the items in the list.  Head becomes tail and so on
* through the entire list.  Note: this is not the most efficient solution
* because it has to loop through the list each time (wastes memory)
* 
* This code was based off of Dr. Brinkman's
* class lecture on how to implement reverse for singly and doubly linke lists
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
	//Not sure why reverse isn't working, I think it still has something to do with the getData
	//method
}