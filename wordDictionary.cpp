#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
    struct TrieNode {
        bool end;
        TrieNode *children[26];
        TrieNode() {
            end = false;
            for(int i = 0;i < 26;i ++) {
                children[i] = NULL;
            }
        }
    };
    TrieNode *root;
public:
    // Adds a word into the data structure.
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp = root;
        for(int i = 0;i < word.size();i ++) {
            int index = word[i] - 'a';
            TrieNode *dummy = temp->children[index];
            if(dummy == NULL) {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->end = true;
    }

    bool _search(TrieNode* root, string word, int index) {
        if(root == NULL) {
            return false;
        }
        if((index == word.size()) && root->end) {
            return true;
        }
        if(word[index] == '.') {
            for(int i = 0;i < 26;i ++) {
                if(root->children[i] != NULL) {
                    if(_search(root->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int n = word[index] - 'a';
            if(root->children[n] != NULL) {
                return _search(root->children[n], word, index + 1);
            }
            return false;
        }
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return _search(root, word, 0);
    }
};

int main() {
	WordDictionary wordDictionary;
	wordDictionary.addWord("ran");
	wordDictionary.addWord("rune");
	wordDictionary.addWord("runner");
	wordDictionary.addWord("runs");
	wordDictionary.addWord("add");
	wordDictionary.addWord("adds");
	wordDictionary.addWord("adder");
	wordDictionary.addWord("addee");
	cout<<wordDictionary.search("r.n")<<" ";
	cout<<wordDictionary.search("ru.n.e")<<" ";
	cout<<wordDictionary.search("add")<<" ";
	cout<<wordDictionary.search("add.")<<" ";
	cout<<wordDictionary.search("adde.")<<" ";
	cout<<wordDictionary.search(".an.")<<" ";
	cout<<wordDictionary.search("...s")<<" ";
	cout<<wordDictionary.search("....e.")<<" ";
	cout<<wordDictionary.search(".......")<<" ";
	cout<<wordDictionary.search("..n.r")<<endl;
	return 0;
}