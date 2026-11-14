#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    bool endOfString;
    unordered_map<char, Node*> children;
    int freq;

    Node() {
        endOfString = false;
    }
};

class Tries {
    Node* root;
public:
    Tries() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string str) { // O(L)
        Node* temp = root;

        for (char ch: str) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
                temp->children[ch]->freq = 1;
            } else {
                temp->children[ch]->freq++;
            }

            temp = temp->children[ch];
        }

        temp->endOfString = true;
    }

    bool startsWith (string prefix) {
        Node* temp = root;

        for (char ch: prefix) {
            if (temp->children.count(ch)) {
                temp = temp->children[ch];
            } else {
                return false;
            }
        }

        return temp->freq > 1;
    }
};

void startsWithProblem (vector<string> words, string prefix) {
    Tries trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    cout << trie.startsWith(prefix) << endl;
}

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "moon"};

    startsWithProblem(words, "app");
    startsWithProblem(words, "apple");
    startsWithProblem(words, "man");
    startsWithProblem(words, "mango");
    startsWithProblem(words, "moon");

    return 0;
}