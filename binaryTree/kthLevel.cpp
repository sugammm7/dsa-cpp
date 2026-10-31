#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree (vector<int> nodes) {
    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);

    curr->left = buildTree(nodes); 
    curr->right = buildTree(nodes); 

    return curr;
}

void helper (Node* root, int k, int level) {
    if (root == NULL) {
        return;
    }

    if (k == level) {
        cout << root->val << " ";
        return;
    }

    helper(root->left, k, level+1);
    helper(root->right, k, level+1);
}

void kthLevel (Node* root, int k) {
    helper(root, k, 1);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    kthLevel(root, 2);

    return 0; 
}