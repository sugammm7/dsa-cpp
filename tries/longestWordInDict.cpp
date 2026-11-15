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

    void helper(Node* currRoot, string &ans, string temp) {
        for (pair<char, Node*> child: currRoot->children) {
            if (child.second->endOfString == true) {
                temp += child.first;

                if ((temp.size() > ans.size()) || (temp.size() == ans.size() && ans > temp)) {
                    ans = temp;
                }

                helper(child.second, ans, temp);

                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    string longestWord() {
        string ans = "";

        helper(root, ans, "");
            
        return ans;
    }
};

string longestWord(vector<string> words) {
    Tries trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    return trie.longestWord();
}

int main() {
    vector<string> words = {"a","banana","app","appl","ap","apply","apple"};

    cout << longestWord(words); // apple

    return 0;
}