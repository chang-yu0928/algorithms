#include <iostream>
#include <vector>
using namespace std;

void totalNQueens(int i, int n, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2, int &result) {
        if(i == n) {
            result ++;
            return;
        }
        for(int j = 0;j < n;j ++) {
            if(column[j] && diag1[n+i-j-1] && diag2[i+j]) {
                column[j] = false;
                diag1[n+i-j-1] = false;
                diag2[i+j] = false;
                totalNQueens(i+1, n, column, diag1, diag2, result);
                column[j] = true;
                diag1[n+i-j-1] = true;
                diag2[i+j] = true;
            }
        }
    }

    int totalNQueens(int n) {
        vector<bool> column(n, true), diag1(2 * n - 1, true), diag2(2 * n - 1, true);
        int result = 0;
        totalNQueens(0, n, column, diag1, diag2, result);
        return result;
    }
    
    int main(int args, char **argv) {
    	int n = atoi(argv[1]);
    	cout<<totalNQueens(n)<<endl;
    	return 0;
    }