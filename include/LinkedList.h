struct Node{
	int data;
	Node* next;
	Node(int x, Node* y) : data(x), next(y){}
};

class LinkedList {
	private:
		Node *sentinel_;
		int num_items_;
	public:
		LinkedList() : sentinel_() {}
		void addNode(int info);
		Node* getIndex(int index);
		void reorder();
		void reverse();
};
