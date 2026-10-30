#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<pair<Node*, int>> q; 
    map<int, int> m;

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHd = curr.second;

        if (m.count(currHd) == 0) {
            m[currHd] = currNode->val;
        }

        if (currNode->left != NULL) {
            q.push(make_pair(currNode->left, currHd - 1));
        }

        if (currNode->right != NULL) {
            q.push(make_pair(currNode->right, currHd + 1));
        }
    }

    for (auto it: m) {
        cout << it.second << " ";
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    topView(root); // 4 2 1 3 6

    return 0;
}