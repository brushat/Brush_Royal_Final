struct Node{
	int data;
	Node* next;
	Node* prev;
	Node(int x, Node* n, Node* p) : data(x), next(n), prev(p){}
};

class LinkedList {
	private:
		Node *head_;
		int num_items_;
	public:
		LinkedList();
		void addNode(int info);
		int getData(int index);
		void cycle();
		void reverse();
};
