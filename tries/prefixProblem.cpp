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

    string getPrefix (string key) {
        Node* temp = root;
        string prefix = "";

        for (char ch: key) {
            prefix += ch;
            if (temp->children[ch]->freq == 1) {
                break;
            }

            temp = temp->children[ch];
        }

        return prefix;
    }
};

void smallestUniquePrefix (vector<string> words) {
    Tries trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    for (int i = 0; i < words.size(); i++) {
        cout << trie.getPrefix(words[i]) << endl;
    }
}

int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};

    smallestUniquePrefix(words);

    return 0;
}