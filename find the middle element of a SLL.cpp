#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};

class NodeOperation {
public:

	// Function to add a new node
	void pushNode(class Node** head_ref, int data_val) {
		class Node* new_node = new Node();
		new_node->data = data_val;
		new_node->next = *head_ref;
		*head_ref = new_node;
	}

	void printNode(class Node* head) {
		while (head != nullptr) {
			cout << head->data << "->";
			head = head->next;
		}
		cout << "nullptr" << endl;
	}

	void printMiddle(class Node* head) {
		struct Node* slow_ptr = head;
		struct Node* fast_ptr = head;
		if (head != nullptr)
		{
			while (fast_ptr != nullptr && fast_ptr->next != nullptr)
			{
				fast_ptr = fast_ptr->next->next;
				slow_ptr = slow_ptr->next;
			}
			cout << "The middle element is [" << slow_ptr->data << "]" << endl;
		}
	}
};