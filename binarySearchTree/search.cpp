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

bool search (Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->val == val) {
        return true;
    }

    if (root->val > val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}


int main () {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);

    cout << search(root, 7) << endl; // 1
    cout << search(root, 12); // 0

    return 0;
}