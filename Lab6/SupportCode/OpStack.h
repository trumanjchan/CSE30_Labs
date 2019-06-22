#ifndef OpStack_h
#define OpStack_h

using namespace std;

// Define the Node struct below...

struct Node {
	string data;
	string op;
	Node* next;

	Node() {
		data = "";
		op = "";
		next = NULL;
	}
};

// Now define the Stack struct. It should be a stack of Nodes...

struct Stack {
	Node* first;
	Node* last;

	Stack() {
		first = NULL;
		last = NULL;
	}
	void push(int number, char math) {
		if (isEmpty()) {
			Node* nodeOne = new Node();
			if (math == +) {
				first = nodeOne;
				last = nodeOne;
				last->data = number;
			}
		}
		else {
			Node* nodeOne = new Node();
			Node* nodeTwo = new Node();
			if (math == +) {
				last->next = nodeTwo;
				last = last->next;
				last->data = number;
			}
			if (math == -) {
				last->next = nodeTwo;
				nodeTwo = nodeOne;

			}
		}
	}

	void pop() {
		if (!isEmpty()) {
			string temp = first->data;
			Node* point = first;
			if (first == last)
			{
				first = last = NULL;
			}
			else
			{
				first = first->next;
			}
			delete point;
		}
	}

	bool isEmpty() {
		if (first == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	~Stack() {
		Node* temp = first;

		while (temp != NULL) {
			temp = temp->next;
			delete first;
			first = temp;
		}
	}
};

#endif

