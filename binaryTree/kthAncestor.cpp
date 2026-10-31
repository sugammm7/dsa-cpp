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

int kthAncestor (Node* root, int node, int k) {
    if (root == NULL) {
        return -1;
    }

    if (root->val == node) {
        return 0;
    }

    int left = kthAncestor(root->left, node, k);
    int right = kthAncestor(root->right, node, k);

    if (left == -1 && right == -1) {
        return -1;
    }

    int valid = left == -1 ? right : left;

    if (valid + 1 == k) {
        cout << "Ancestor " << k << ": " << root->val;
    }

    return valid + 1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    kthAncestor(root, 4, 1);

    return 0;
}