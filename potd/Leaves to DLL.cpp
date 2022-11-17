#include <bits/stdc++.h>
using namespace std;
#define nullptr nullptr

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

Node* buildTree(string str) {
  if (str.length() == 0 || str[0] == 'N') return nullptr;
  vector<string> ip;
  istringstream iss(str);
  for (string str; iss >> str;) ip.push_back(str);
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
    if (i >= ip.size()) break;
    currVal = ip[i];
    if (currVal != "N") {
      currNode->right = new Node(stoi(currVal));
      queue.push(currNode->right);
    }
    i++;
  }
  return root;
}

void inOrder(Node* root) {
  if (!root) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

Node* preorder(Node* root, Node*& prev) {
  if (!root)return nullptr;
  if (!root->right and !root->left) {
    prev->right = root;
    root->left = prev;
    prev = root;
    return nullptr;
  }
  root->left = preorder(root->left, prev);
  root->right = preorder(root->right, prev);
}
Node* convertToDLL(Node* root) {
  // add code here.
  Node* head = new Node(0), * prev = head;
  preorder(root, prev);
  head->right->left = nullptr;
  return head->right;
}
// { Driver Code Starts.

int main() {
  int tc;
  scanf("%d ", &tc);
  while (tc--) {
    string treeString;
    getline(cin, treeString);
    Node* root = buildTree(treeString);
    Node* head = convertToDLL(root);
    inOrder(root);
    cout << "\n";
    Node* curr = head, * last = head;
    while (curr) {
      cout << curr->data << " ";
      last = curr;
      curr = curr->right;
    }
    cout << "\n";
    curr = last;
    while (curr) {
      cout << curr->data << " ";
      curr = curr->left;
    }
    cout << "\n";
  }
  return 0;
}