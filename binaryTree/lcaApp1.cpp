// TC: O(n), SC: O(n)

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

bool rootToNodePath (Node* root, int node, vector<int> &path) {
    if (root == NULL) {
        return false;
    }

    path.push_back(root->val);

    if (root->val == node) {
        return true;
    }

    bool left = rootToNodePath(root->left, node, path);
    if (left) {
        return true;
    }

    bool right = rootToNodePath(root->right, node, path);

    if (!left && !right) {
        path.pop_back();
        return false;
    }

    return true;
}

int lca (Node* root, int node1, int node2) {
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, node1, path1);
    rootToNodePath(root, node2, path2);

    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
        if (path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    cout << lca(root, 4, 5);

    return 0;
}