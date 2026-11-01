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

void printInRange (Node* root, int start, int end) {
    if (root == NULL) {
        return;
    }

    if (root->val >= start && root->val <= end) {
        printInRange(root->left, start, end);
        cout << root->val << " ";
        printInRange(root->right, start, end);
    } else if (root->val > end) {
        printInRange(root->left, start, end);
    } else {
        printInRange(root->right, start, end);
    }
}

int main () {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);

    printInRange(root, 3, 7);

    return 0;
}