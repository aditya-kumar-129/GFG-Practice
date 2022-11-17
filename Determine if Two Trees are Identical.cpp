#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    //Function to check if two trees are identical.
    bool isIdentical(Node* r1, Node* r2)
    {
        if (r1 == nullptr && r2 == nullptr) {
            return true;
        }

        if (r1 == nullptr && r2 != nullptr) {
            return false;
        }

        if (r2 == nullptr && r1 != nullptr) {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);

        bool ans = r1->data == r2->data;

        if (left && right && ans) {
            return true;
        }
        return false;
    }
};