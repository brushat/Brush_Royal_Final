#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;


void LinkedList::addNode(int info){
	Node* node = new Node(info, NULL, NULL);
	node->prev = head_->prev;
	node->next = head_;
	head_->prev->next = node;
	head_->prev = node;
	num_items_++;
}

int LinkedList::getData(int index){
	int i = 0;
	Node* pointer = head_;
	while(pointer->next != head_){
		Node* temp = pointer;
		pointer = pointer->next;
		i++;
	}
	return pointer->data;
}

void LinkedList::reorder(){

}

void LinkedList::reverse(){

}