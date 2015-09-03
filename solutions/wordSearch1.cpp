#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool exist(vector<vector<char> > &board, string word, int i, int m, int n) {
        if(i == word.size() - 1) return true;
        int x = board.size(), y = board[0].size();
        board[m][n] = '#';
        i ++;
        if(m + 1 < x && board[m+1][n] == word[i] && exist(board, word, i, m + 1, n)) return true;
        if(m - 1 >= 0 && board[m-1][n] == word[i] && exist(board, word, i, m - 1, n)) return true;
        if(n - 1 >= 0 && board[m][n-1] == word[i] && exist(board, word, i, m, n - 1)) return true;
        if(n + 1 < y && board[m][n+1] == word[i] && exist(board, word, i, m, n + 1)) return true;
        board[m][n] = word[i-1];
        return false;
    }
    
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(board[i][j] == word[0] && exist(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int main() {
    	vector<vector<char> > board(3, vector<char>(4));
    	board[0][0]='A';board[0][1]='B';board[0][2]='C';board[0][3]='E';
    	board[1][0]='S';board[1][1]='F';board[1][2]='C';board[1][3]='S';
    	board[2][0]='A';board[2][1]='D';board[2][2]='E';board[2][3]='E';
    	//cout<<exist(board, "ABCCED")<<endl;
    	//cout<<exist(board, "SEE")<<endl;
    	cout<<exist(board, "ABCB")<<endl;
    	return 0;
    }