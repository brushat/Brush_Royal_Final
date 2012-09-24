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

void LinkedList::addNode(int info){
	if( head_==NULL ) {
        head_ = new Node(info, NULL, NULL);
        head_->next = head_->prev = head_; 
    } else {
        Node *node = new Node(info, head_->prev, head_);
        node->prev->next = node;
        node->next->prev = node;
        }
}

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
* 
*
*/
void LinkedList::cycle(){
	
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