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

int distFromLca (Node* root, int node) {
    if (root == NULL) {
        return -1;
    }

    if (root->val == node) {
        return 0;
    }

    int left = distFromLca(root->left, node);
    if (left != -1) {
        return left + 1;
    }

    int right = distFromLca(root->right, node);
    if (right != -1) {
        return right + 1;
    }

    return -1;
}

int minDistance (Node* root, int node1, int node2) {
    Node* lcaNode = lca(root, node1, node2);

    int dist1 = distFromLca(lcaNode, node1);
    int dist2 = distFromLca(lcaNode, node2);

    return dist1 + dist2;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << minDistance(root, 4, 3);

    return 0;
}