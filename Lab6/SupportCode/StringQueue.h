
#ifndef Queue_h
#define Queue_h
#include <string>

using namespace std;

struct Node {
	string data;
	Node* next;
	
	Node() {
		data = "";
		next = NULL;
	}
};

struct Queue {
	Node* first;
	Node* last;

	Queue() {
		first = NULL;
		last = NULL;
	}

	void push(string name) {
		if (isEmpty()) {
			Node* nodeOne = new Node();
			first = nodeOne;
			last = nodeOne;
			last->data = name;
		}
		else {
			Node* nodeTwo = new Node();
			last->next = nodeTwo;
			last = last->next;
			last->data = name;
		}
	}

	string pop() {
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
			return temp;
		}
		return "";
	}

	bool isEmpty() {
		if (first == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	~Queue() {
		Node* temp = first;

		while (temp != NULL) {
			temp = temp->next;
			delete first;
			first = temp;
		}
	}
};

#endif


