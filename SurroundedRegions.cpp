#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int sizeX;
int sizeY;
void _solve(vector<vector<char> > &board, int x, int y){
        if(x >= sizeX || x < 0 || y < 0 || y >= sizeY){
            return;
        }
        if(board[x][y] == '*' || board[x][y] == 'X'){
            return;
        }
        if(board[x][y] == 'O'){
            stack<int> containerX;
            stack<int> containerY;
            containerX.push(x);
            containerY.push(y);
            while(!containerX.empty()){
                int tempX = containerX.top();
                int tempY = containerY.top();
                board[tempX][tempY] = '*';
                containerX.pop();
                containerY.pop();
                if(tempX-1 >= 0 && board[tempX-1][tempY] == 'O'){
                	containerX.push(tempX-1);
                	containerY.push(tempY);
                }
                if(tempX+1 < sizeX && board[tempX+1][tempY] == 'O'){
                	containerX.push(tempX+1);
                	containerY.push(tempY);
                }
                if(tempY-1 >= 0 && board[tempX][tempY-1] == 'O'){
                	containerX.push(tempX);
                	containerY.push(tempY-1);
                }
                if(tempY+1 < sizeY && board[tempX][tempY+1] == 'O'){
                	containerX.push(tempX);
                	containerY.push(tempY+1);
                }
            }
        }
    }
    void solve(vector<vector<char> > &board) {
        sizeX = board.size();
        sizeY = board[0].size();
        for(int i = 0;i < sizeY;i ++){
            if(board[0][i] == 'O'){
                board[0][i] = '*';
                _solve(board, 1, i);
            }
            if(board[sizeX-1][i] == 'O'){
                board[sizeX-1][i] = '*';
                _solve(board, sizeX-2, i);
            }
        }
        for(int i = 0;i < sizeX;i ++){
            if(board[i][0] == 'O'){
                board[i][0] = '*';
                _solve(board, i, 1);
            }
            if(board[i][sizeY-1] == 'O'){
                board[i][sizeY-1] = '*';
                _solve(board, i, sizeY-2);
            }
        }
        for(int i = 0;i < sizeX;i ++){
            for(int j = 0;j < sizeY;j ++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    
int main(){
	vector<vector<char> > board(4, vector<char>(6));
	for(int i = 0;i < board.size();i ++){
		for(int j = 0;j < board[0].size();j ++){
			board[i][j] = 'X';
		}
	}
	board[0][0] = 'X';board[0][1] = 'O';board[0][2] = 'X';board[0][3] = 'O';board[0][4] = 'X';board[0][5] = 'O';
	board[1][0] = 'O';board[1][1] = 'X';board[1][2] = 'O';board[1][3] = 'X';board[1][4] = 'O';board[1][5] = 'X';
	board[2][0] = 'X';board[2][1] = 'O';board[2][2] = 'X';board[2][3] = 'O';board[2][4] = 'X';board[2][5] = 'O';
	board[3][0] = 'O';board[3][1] = 'X';board[3][2] = 'O';board[3][3] = 'X';board[3][4] = 'O';board[3][5] = 'X';
	for(int i = 0;i < board.size();i ++){
		for(int j = 0;j < board[0].size();j ++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	solve(board);
	for(int i = 0;i < board.size();i ++){
		for(int j = 0;j < board[0].size();j ++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}