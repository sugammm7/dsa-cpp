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

int main() {
    string words[] = {"there", "their", "ant", "any"};
    Tries trie;

    for (int i = 0; i < 4; i++) {
        trie.insert(words[i]);
    }

    cout << trie.search("there") << endl; // 1
    cout << trie.search("and") << endl; // 0
    cout << trie.search("ant") << endl; // 1
    cout << trie.search("any") << endl; // 1
    cout << trie.search("their") << endl; // 1
    cout << trie.search("theirs") << endl; // 0
    cout << trie.search("") << endl; // 0

    return 0;
}