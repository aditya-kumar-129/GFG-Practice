// Question:- How will you find the middle element of a singly linked list without iterating the list more than once?

/*
  Logic:- Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.
*/

#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};

class NodeOperation{
public:

	// Function to add a new node
	void pushNode(class Node** head_ref,int data_val){
		class Node *new_node = new Node();
		new_node->data = data_val;
		new_node->next = *head_ref;
		*head_ref = new_node;
	}

	void printNode(class Node *head){
		while(head != NULL){
			cout <<head->data << "->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
	
	void printMiddle(class Node *head){
		struct Node *slow_ptr = head;
		struct Node *fast_ptr = head;
		if (head!=NULL)
		{
			while (fast_ptr != NULL && fast_ptr->next != NULL)
			{
				fast_ptr = fast_ptr->next->next;
				slow_ptr = slow_ptr->next;
			}
			cout << "The middle element is [" << slow_ptr->data << "]" << endl;
		}
	}
};

int main(){
	class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	}
	return 0;
}