#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
	bool end;
    TrieNode *children[26];
    // Initialize your data structure here.
    TrieNode() {
        end = false;
        for(int i = 0;i < 26;i ++) {
        	children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *curr = root;
        for(int i = 0;i < word.size();i ++) {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *curr = root;
        for(int i = 0;i < word.size();i ++) {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return curr->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(int i = 0;i < prefix.size();i ++) {
            int index = prefix[i] - 'a';
            if(curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
	Trie trie;
	trie.insert("somestring");
	cout<<trie.search("key")<<endl;
	return 0;
}