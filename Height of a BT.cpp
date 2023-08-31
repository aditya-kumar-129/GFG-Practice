#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left, * right;
};

class Solution {
public:
	// Using level order traversal
	int height(struct Node* node) {
		queue<Node*>q;
		int count = 0;
		q.push(node);
		while (q.empty() == false) {
			int size = q.size();
			count++;
			for (int i = 0;i < size;i++) {
				Node* curr = q.front();
				q.pop();
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		}
		return count;
	}
};

// Method 2:- Uisng recursive solution:-

int height(struct Node* node) {
	if (!node) return 0;
	int x = height(node->left);
	int y = height(node->right);
	return max(x, y) + 1;
}