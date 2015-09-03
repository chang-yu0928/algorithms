#include <iostream>
#include <vector>
using namespace std;

bool solveSudoku(vector<vector<char> > &board, vector<vector<bool> > &rows, vector<vector<bool> > &cols, vector<vector<bool> > &mat, int i, int j) {
	if(j == 9) {
		j = 0;
		i ++;
	}
	if(i == 9) {
		return true;
	}
	if(board[i][j] != '.'){
		if(solveSudoku(board, rows, cols, mat, i, j + 1)) return true;
	} else {
		int index = (i/3) * 3 + (j/3);
		for(int k = 1;k < 10;k ++) {
			if(rows[i][k] && cols[j][k] && mat[index][k]) {
				board[i][j] = k + '0';
				rows[i][k] = false;
    			cols[j][k] = false;
    			mat[index][k] = false;
    			if(solveSudoku(board, rows, cols, mat, i, j + 1)) return true;
    			rows[i][k] = true;
    			cols[j][k] = true;
    			mat[index][k] = true;
    			board[i][j] = '.';
			}
		}
	}
	return false;
}

void solveSudoku(vector<vector<char> >& board) {
        vector<vector<bool> > rows(9, vector<bool>(10, true)), cols(9, vector<bool>(10, true)), mat(9, vector<bool>(10, true));
        for(int i = 0;i < 9;i ++) {
        	for(int j = 0;j < 9;j ++) {
        		if(board[i][j] != '.') {
        			rows[i][board[i][j] - '0'] = false;
        			cols[j][board[i][j] - '0'] = false;
        			mat[(i/3) * 3 + (j/3)][board[i][j] - '0'] = false;
        		}
        	}
        }
        solveSudoku(board, rows, cols, mat, 0, 0);
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