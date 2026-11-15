#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    bool endOfString;
    unordered_map<char, Node*> children;

    Node() {
        endOfString = false;
    }
};

class Tries {
    Node* root;
public:
    Tries() {
        root = new Node();
    }

    void insert(string str) { // O(L)
        Node* temp = root;

        for (char ch: str) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            } 

            temp = temp->children[ch];
        }

        temp->endOfString = true;
    }

    int helper(Node* currRoot) {
        int ans = 0;

        for (pair<char, Node*> child: currRoot->children) {
            ans += helper(child.second);
        }

        return ans + 1;
    }

    int countNodes () {
        return helper(root);
    }
};

int countUniqueSubString(string str) {
    Tries trie;

    for (int i = 0; i < str.size(); i++) {
        trie.insert(str.substr(i));
    }

    return trie.countNodes();
}

int main() {
    string str1 = "abc"; 
    string str2 = "ababa"; 

    cout << countUniqueSubString(str1); // 7
    cout << countUniqueSubString(str2); // 10

    return 0;
}