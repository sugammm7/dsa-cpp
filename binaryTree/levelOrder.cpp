#include<iostream>
#include<vector>
#include<queue>
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

void levelOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;

            if (q.empty()) {
                break;
            } else {
                q.push(NULL);
            }
        } else {
            cout << curr->val << " ";

            if (curr->left != NULL) {
                q.push(curr->left);
            }

            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(nodes);

    levelOrder(root);
    /*
        1 
        2 3 
        4 5 6 
    */

    return 0;
}