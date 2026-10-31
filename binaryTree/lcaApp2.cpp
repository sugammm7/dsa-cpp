// TC: O(n), SC: O(1)

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

Node* lca (Node* root, int node1, int node2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == node1 || root->val == node2) {
        return root;
    }

    Node* left = lca(root->left, node1, node2);
    Node* right = lca(root->right, node1, node2);

    if (left && right) {
        return root;
    }

    return left == NULL ? right : left;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << lca(root, 5, 3)->val;

    return 0;
}