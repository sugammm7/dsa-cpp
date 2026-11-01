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

Node* inOrderSuccessor (Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* deleteNode (Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val > val) {
        root->left = deleteNode(root->left, val);
    } else if (root->val < val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }

        Node* IS = inOrderSuccessor(root->right);
        root->val = IS->val;
        root->right = deleteNode(root->right, IS->val);
    }

    return root;
}

int main () {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);

    inOrder(root); // 1 2 3 4 5 7
    cout << endl;

    deleteNode(root, 3);
    inOrder(root); // 1 2 4 5 7

    return 0;
}