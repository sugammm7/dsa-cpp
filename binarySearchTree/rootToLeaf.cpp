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

void rootToLeaf (Node* root, vector<int> &path) {
    if (root == NULL) {
        return;
    }

    path.push_back(root->val);

    rootToLeaf(root->left, path);
    rootToLeaf(root->right, path);

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    path.pop_back();
}

int main () {
    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6);
    vector<int> path;

    rootToLeaf(root, path);

    return 0;
}