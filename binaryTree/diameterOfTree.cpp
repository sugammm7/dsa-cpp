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

pair<int, int> diameterOfTree (Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }

    pair<int, int> leftInfo = diameterOfTree(root->left);
    pair<int, int> rightInfo = diameterOfTree(root->right);

    int currDiameter = leftInfo.second + rightInfo.second + 1;

    int finalDiameter = max(currDiameter, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiameter, finalHeight);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    pair<int, int> res = diameterOfTree(root);

    cout << "Diameter: " << res.first << endl; //5
    cout << "Height: " << res.second << endl; //3

    return 0;
}