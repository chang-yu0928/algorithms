#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int> > &matrix) {
    if(matrix.size() == 0) return;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int> > result(m + n - 1);
    for(int i = 0;i < m;i ++) {
        int dummy = 0;
        while(dummy < min(i + 1, n)) {
            result[i].push_back(matrix[i-dummy][dummy]);
            dummy ++;
        }
    }
    for(int i = 1;i < n;i ++) {
        int dummy = 0;
        while(dummy < min(m, n-i)) {
            result[m + i - 1].push_back(matrix[m-dummy-1][i+dummy]);
            dummy ++;
        }
    }
    for(int i = 0;i < result.size();i ++) {
        for(int j = 0;j < result[i].size();j ++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int> > matrix(5, vector<int>(1));
    matrix[0][0]=1;//matrix[0][1]=2;matrix[0][2]=3;matrix[0][3]=4;
    matrix[1][0]=5;//matrix[1][1]=6;matrix[1][2]=7;matrix[1][3]=8;
    matrix[2][0]=9;//matrix[2][1]=10;matrix[2][2]=11;matrix[2][3]=12;
    matrix[3][0]=13;//matrix[3][1]=14;matrix[3][2]=15;matrix[3][3]=16;
    matrix[4][0]=17;//matrix[4][1]=18;matrix[4][2]=19;matrix[4][3]=20;
    vector<vector<int> > matrix1;
    printMatrix(matrix1);
    return 0;
}

