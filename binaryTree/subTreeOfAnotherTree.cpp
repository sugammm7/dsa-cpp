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

bool isIdentical (Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL || root2 == NULL) {
        return false;
    }

    if (root1->val != root2->val) {
        return false;
    }

    if (!isIdentical(root1->left, root2->left)) {
        return false;
    }

    return isIdentical(root1->right, root2->right);
}

bool subTree (Node* root, Node* subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    } else if (root == NULL || subRoot == NULL) {
        return false;
    }

    if (root->val == subRoot->val) {
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    bool isLeft = subTree(root->left, subRoot);
    
    if (!isLeft) {
        return subTree(root->right, subRoot);
    }

    return true;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    Node *subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(2);

    cout << subTree(root, subRoot);

    return 0;
}