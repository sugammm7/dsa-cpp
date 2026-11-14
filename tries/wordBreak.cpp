#include<iostream>
#include<vector>
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

    bool search(string str) {
        Node* temp = root;
        for (char ch: str) {
            if (temp->children.count(ch)) {
                temp = temp->children[ch];
            } else {
                return false;
            }
        }

        return temp->endOfString;
    }
};

bool helper (Tries trie, string key) {
    if (key.size() == 0) {
        return true;
    }

    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if (trie.search(first) && helper(trie, second)) {
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dict, string key) {
    Tries trie;

    for (int i = 0; i < dict.size(); i++) {
        trie.insert(dict[i]);
    }

    return helper(trie, key);
}

int main() {
    vector<string> dict = {"i", "love", "sun", "sunscreen"};

    cout << wordBreak(dict, "ilovesun"); // 1
    cout << wordBreak(dict, "ilovesunscreen"); // 1
    cout << wordBreak(dict, "ilovescreen"); // 0

    return 0;
}