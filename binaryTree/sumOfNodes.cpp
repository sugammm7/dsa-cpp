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

int sumOfNode(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int leftSubTreeNodeSum = sumOfNode(root->left);
    int rightSubTreeNodeSum = sumOfNode(root->right);

    return leftSubTreeNodeSum + rightSubTreeNodeSum + root->val;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << sumOfNode(root); // 20

    return 0;
}