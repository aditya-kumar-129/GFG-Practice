#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = right = nullptr;
	}
};

Node* buildTree(string str)
{
	if (str.length() == 0 || str[0] == 'N')
		return nullptr;
	vector<string> ip;
	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);
	Node* root = new Node(stoi(ip[0]));
	queue<Node*> queue;
	queue.push(root);
	int i = 1;
	while (!queue.empty() && i < ip.size()) {
		Node* currNode = queue.front();
		queue.pop();
		string currVal = ip[i];
		if (currVal != "N") {
			currNode->left = new Node(stoi(currVal));
			queue.push(currNode->left);
		}
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];
		if (currVal != "N") {
			currNode->right = new Node(stoi(currVal));
			queue.push(currNode->right);
		}
		i++;
	}
	return root;
}

class Solution {
public:
	// Using level order traversal
	int height(struct Node* node)
	{
		queue<Node*>q;
		int count = 0;
		q.push(node);
		while (q.empty() == false)
		{
			int size = q.size();
			count++;
			for (int i = 0;i < size;i++)
			{
				Node* curr = q.front();
				q.pop();
				if (curr->left != nullptr)
					q.push(curr->left);
				if (curr->right != nullptr)
					q.push(curr->right);
			}
		}
		return count;
	}
};

int main()
{
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string treeString;
		getline(cin, treeString);
		Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.height(root) << endl;
	}
	return 0;
}

// Method 2:- Uisng recursive solution:-

int height(struct Node* node)
{
	if (node == nullptr)
		return 0;
	int x = height(node->left);
	int y = height(node->right);
	return max(x, y) + 1;
}