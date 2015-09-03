#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solveNQueens(int n, int i, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2, vector<vector<string> > &result, vector<string> &part) {
        if(i == n) {
            result.push_back(part);
            return;
        }
        for(int j = 0;j < n;j ++) {
            if(!column[j] && !diag1[n+i-j-1] && !diag2[i+j]) {
                column[j] = true;
                diag1[n+i-j-1] = true;
                diag2[i+j] = true;
                part[i][j] = 'Q';
                solveNQueens(n, i+1, column, diag1, diag2, result, part);
                part[i][j] = '.';
                column[j] = false;
                diag1[n+i-j-1] = false;
                diag2[i+j] = false;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        string line(n, '.');
        vector<string> part(n, line);
        vector<bool> column(n), diag1(2 * n - 1), diag2(2 * n - 1);
        solveNQueens(n, 0, column, diag1, diag2, result, part);
        return result;
    }

int main() {
	vector<vector<string> > result = solveNQueens(8);
	for(int i = 0;i < result.size();i ++) {
		for(int j = 0;j < result[i].size();j ++) {
			cout<<result[i][j]<<endl;
		}
		cout<<endl;
	}
	cout<<result.size()<<endl;
}