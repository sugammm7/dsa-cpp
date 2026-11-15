#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    bool endOfString;
    unordered_map<char, Node*> children;
    vector<string> words;

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

    void insert(string str) { 
        Node* temp = root;
        string original = str;

        sort(str.begin(), str.end());

        for (char ch: str) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            } 

            temp = temp->children[ch];
        }

        temp->endOfString = true;
        temp->words.push_back(original);
    }

    void helper (vector<vector<string>> &ans, Node* currRoot) {
        for (pair<char, Node*> child: currRoot->children) {
            if (child.second->endOfString == true) {
                ans.push_back(child.second->words);
            }
            helper(ans, child.second);
        }
    }

    vector<vector<string>> groupAnagrams () {
        vector<vector<string>> ans;

        helper(ans, root);

        return ans;
    }
};

vector<vector<string>> groupAnagramsProb(vector<string> words) {
    Tries trie;

    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }

    return trie.groupAnagrams();
}


int main() {
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagramsProb(words);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}