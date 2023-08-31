#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class NodeOperation {
public:
	void printMiddle(class Node* head) {
		Node* slow_ptr = head, * fast_ptr = head;
		if (head != nullptr) {
			while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
				fast_ptr = fast_ptr->next->next;
				slow_ptr = slow_ptr->next;
			}
			cout << "The middle element is [" << slow_ptr->data << "]" << endl;
		}
	}
};