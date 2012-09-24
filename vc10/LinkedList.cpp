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