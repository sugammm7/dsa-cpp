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

int nodeCount(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int leftSubTreeNodeCount = nodeCount(root->left);
    int rightSubTreeNodeCount = nodeCount(root->right);

    return leftSubTreeNodeCount + rightSubTreeNodeCount + 1;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << nodeCount(root); // 6

    return 0;
}