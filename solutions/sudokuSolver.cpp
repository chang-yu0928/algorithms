#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool solveSudoku(vector<vector<char> >& board, vector<vector<bool> > &cols, vector<vector<bool> > &rows, vector<vector<bool> > &mats, int i, int j) {
        if(j == 9) {
            j = 0;
            i ++;
        }
        if(i == 9) return true;
        if(board[i][j] != '.') return solveSudoku(board, cols, rows, mats, i, j + 1);
        else {
            int m = (i/3) * 3 + (j/3);
            for(int n = 1;n <= 9;n ++) {
                if(!rows[i][n] && !cols[j][n] && !mats[m][n]) {
                    cols[j][n] = true;
                    rows[i][n] = true;
                    mats[m][n] = true;
                    board[i][j] = (n + '0');
                    if(solveSudoku(board, cols, rows, mats, i, j + 1)) return true;
                    board[i][j] = '.';
                    cols[j][n] = false;
                    rows[i][n] = false;
                    mats[m][n] = false;
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        vector<vector<bool> > cols(9, vector<bool>(10)), rows(9, vector<bool>(10)), mats(9, vector<bool>(10));
        int x;
        for(int i = 0;i < board.size();i ++) {
            for(int j = 0;j < board[i].size();j ++) {
                if(board[i][j] != '.') {
                    x = board[i][j] - '0';
                    cols[j][x] = true;
                    rows[i][x] = true;
                    mats[(i/3) * 3 + (j/3)][x] = true;
                }
            }
        }
        solveSudoku(board, cols, rows, mats, 0, 0);
    }
    
    int main() {
    	vector<vector<char> > board(9, vector<char>(9, '.'));
    	board[0][0]='5';board[0][1]='3';board[0][4]='7';
    	board[1][0]='6';board[1][3]='1';board[1][4]='9';board[1][5]='5';
    	board[2][1]='9';board[2][2]='8';board[2][7]='6';
    	board[3][0]='8';board[3][4]='6';board[3][8]='3';
    	board[4][0]='4';board[4][3]='8';board[4][5]='3';board[4][8]='1';
    	board[5][0]='7';board[5][4]='2';board[5][8]='6';
    	board[6][1]='6';board[6][6]='2';board[6][7]='8';
    	board[7][3]='4';board[7][4]='1';board[7][5]='9';board[7][8]='5';
    	board[8][4]='8';board[8][7]='7';board[8][8]='9';
    	
    	solveSudoku(board);
    	
    	for(int i = 0;i < 9;i ++) {
    		for(int j = 0;j < 9;j ++) {
    			cout<<board[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    }