#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(){
        data = 0;
        next = NULL;
    }
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


struct LinkedList {
    Node* head;
    
    LinkedList(){
        head = NULL;
    }
    
    void append(int value){
        
        if (head == NULL){
            head = new Node(value);
        }
        else{
            // Allocate a new node with value
            // Go to the last element of the list
            // Make the next of the last element point to the new node
            
            Node* newNode = new Node(value);
            
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            // At this point, temp is pointing to the last existing element of list
            
            temp->next = newNode;
        }
    }
    
    void insertAt(int index, int value) {
		/*Node* newNode = new Node(value);     //ATTEMPT 1

		Node* temp = head;
		for (int i = index; i < 7; i++) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
		}
		for (int i = 1; i < index-5; i++) {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			if (temp->next == NULL) {
				Node* zero = new Node(0);
				temp->next = zero;
			}
		}

		temp->next = newNode;*/

		Node* newNode = new Node(value);     //ATTEMPT 2

		Node* temp = head;
		for (int i = 1; i < index; i++) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
			while (temp->next == NULL) {
				Node* zero = new Node(0);
				temp->next = zero;
			}
		}
		//for (int i = 1; i < index-5; i++) {
		//	while (temp->next != NULL) {
		//		temp = temp->next;
		//	}
		//	if (temp->next == NULL) {
		//		Node* zero = new Node(0);
		//		temp->next = zero;
		//	}
		//}

		newNode->next = temp->next;
		temp->next = newNode;

		/*Node* newNode = new Node(value);     //ATTEMPT 3

		Node* temp = head;
		for (int i = 1; i < index; i++) {
			if (temp->next != NULL) {
				temp = temp->next;
			}
			else {
				Node* zero = new Node(0);
				temp->next = zero;
			}
		}

		newNode->next = temp->next;
		temp->next = newNode;*/
    }
    
    int getValue(int index){
		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
    }
    
    void setValue(int index, int value){
		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->data = value;
    }
    
    void print (){
        Node* temp = head;
        
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    
    ~LinkedList(){
        Node* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    LinkedList myList;
    
    
    for (int i = 0; i < 6; i++) {
        myList.append(i);
    }
    
    myList.insertAt(2, 77);
    
    myList.insertAt(10, 89);
    
    myList.append(101);
    
    myList.setValue(0, 11);
    
    cout << myList.getValue(2) << endl << endl;
    
    myList.print();
    
    //    Expected output:
    //    77
    //
    //    11
    //    1
    //    77
    //    2
    //    3
    //    4
    //    5
    //    0
    //    0
    //    0
    //    89
    //    101
    
    return 0;
}














