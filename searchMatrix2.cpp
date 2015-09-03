#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target, int m, int n) {
        if(m >= matrix.size() || n < 0) return false;
        if(target == matrix[m][n]) return true;
        if(target < matrix[m][n]) {
            return searchMatrix(matrix, target, m , n - 1);
        } else {
            return searchMatrix(matrix, target, m + 1, n);
        }
    }

    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix[0].size() - 1);
    }
    
    int main() {
    	vector<vector<int> > matrix(1, vector<int> (1));
    	matrix[0][0] = -5;// matrix[1][0] = 6;
    	cout<<searchMatrix(matrix, -2)<<endl;
    	return 0;
    }