#include <iostream>
#include <string>
#include <vector>

using namespace std;


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
    void insertTrie(string word) {
        TrieNode* dummy = root;
        int index;
        for(int i = 0;i < word.size();i ++) {
            index = word[i] - 'a';
            if(dummy->children[index] == NULL) {
                dummy->children[index] = new TrieNode();
            }
            dummy = dummy->children[index];
        }
        dummy->end = true;
    }
    
    void findWords(vector<vector<char> > &board, int m, int n, TrieNode* node, vector<string> &result, string part) {
        if(m < 0 || n < 0 || m >= board.size() || n >= board[0].size() || board[m][n] == '.') return;
        int index = board[m][n] - 'a';
        char temp;
        if(node->children[index]) {
            part += board[m][n];
            temp = board[m][n];
            board[m][n] = '.';
            if(node->children[index]->end) {
                result.push_back(part);
                node->children[index]->end = false;
            }
            findWords(board, m-1, n, node->children[index], result, part);
            findWords(board, m+1, n, node->children[index], result, part);
            findWords(board, m, n-1, node->children[index], result, part);
            findWords(board, m, n+1, node->children[index], result, part);
            board[m][n] = temp;
        }
    }
    
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        root = new TrieNode();
        vector<string> result;
        string part;
        for(int i = 0;i < words.size();i ++) {
            insertTrie(words[i]);
        }
        for(int i = 0;i < board.size();i ++) {
            for(int j = 0;j < board[i].size();j ++) {
                findWords(board, i, j, root, result, part);
            }
        }
        return result;
    }
    
    int main() {
    	vector<vector<char> > board(2, vector<char> (1));
    	board[0][0] = 'a';
    	board[1][0] = 'a';
    	vector<string> words;
    	words.push_back("a");
    	vector<string> result = findWords(board, words);
    	for(int i = 0; i < result.size();i ++) {
    		cout<< result[i] << " ";
    	}
    	cout<<endl;
    	return 0;
    	
    }