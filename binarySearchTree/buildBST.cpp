#include<iostream>
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

Node* insert (Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (root->val > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST (int* arr, int n) {
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main () {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);

    inOrder(root); // 1 2 3 4 5 7

    return 0;
}