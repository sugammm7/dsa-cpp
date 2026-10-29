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

void preOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->val << " "; 
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->val << " "; 
    inOrder(root->right);
}

void postOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " "; 
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    preOrder(root); // 1 2 4 5 3 6
    cout << endl;

    inOrder(root); //4 2 5 1 3 6
    cout << endl;

    postOrder(root); // 4 5 2 6 3 1
    cout << endl;

    return 0;
}