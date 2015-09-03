#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> >& matrix) {
        int n = matrix.size(), m = matrix[0].size(), leftLen = 0, rightLen = m, result = 0, temp;
        vector<int> left(m, 0), right(m, m), height(m, 0);
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m;j ++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], leftLen);
                    height[j] ++;
                } else {
                    leftLen = j + 1;
                    left[j] = 0;
                    height[j] = 0;
                }
            }
            for(int j = m - 1;j >= 0;j --) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], rightLen);
                } else {
                    rightLen = j;
                    right[j] = m;
                }
            }
            for(int j = 0;j < m;j ++) {
                temp = (right[j] - left[j]) * height[j];
                result = max(temp, result);
                cout<<i<<","<<j<<", left: "<<left[j]<<", right: "<<right[j]<<", height: "<<height[j]<<endl;
            }
            leftLen = 0;
            rightLen = m;
        }
        return result;
    }
    
int main() {
	vector<vector<char> > matrix(3, vector<char> (3));
	matrix[0][0] = '1';matrix[0][1] = '0';matrix[0][2] = '0';
	matrix[1][0] = '1';matrix[1][1] = '0';matrix[1][2] = '1';
	matrix[2][0] = '1';matrix[2][1] = '1';matrix[2][2] = '1';
	
	cout<<maximalRectangle(matrix)<<endl;
	return 0;
}