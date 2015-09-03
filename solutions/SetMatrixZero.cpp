#include <iostream>
#include <vector>
using namespace std;
    void setZeroes(vector<vector<int> > &matrix) {
        bool flag = true;
        int firstZeroRow = -1, firstZeroCol = -1, rowCount = 0, colCount = 0;
        int row = matrix[0].size(), col = matrix.size();
        if(row == 0 || col == 0){
            return;
        }
        cout<<row<<" "<<col<<endl;
        for(int i = 0;i < col;i ++){
            for(int j = 0;j < row;j ++){
                if(matrix[i][j] == 0 && flag){
                    firstZeroRow = i;
                    firstZeroCol = j;
                    flag = false;
                }else if(matrix[i][j] == 0){
                    if(rowCount == firstZeroCol && colCount == firstZeroRow){
                        rowCount ++;
                        colCount ++;
                    }
                    if(rowCount < row){
                        matrix[firstZeroRow][rowCount] = i;
                        rowCount ++;
                    }
                    if(colCount < col){
                        cout<<"1:"<<j<<","<<colCount<<endl;
                        matrix[colCount][firstZeroCol] = j;
                        colCount ++;
                    }
                }
            }
        }
        cout<<firstZeroRow<<" "<<firstZeroCol<<endl;
        cout<<rowCount<<" "<<colCount<<endl;
        for(int i = 0;i < rowCount;i ++){
            if(i == firstZeroCol){
                continue;
            }
            if(i < row && matrix[firstZeroRow][i] != firstZeroRow){
                cout<<matrix[firstZeroRow][i]<<endl;
                for(int j = 0;j < row;j ++){
                    if(j != firstZeroCol){
                        matrix[matrix[firstZeroRow][i]][j] = 0;
                    }
                }
            }
        }
        for(int i = 0;i < colCount;i ++){
            cout<<matrix[i][firstZeroCol]<<endl;
            if(i == firstZeroRow){
                continue;
            }
            if(i < col && matrix[i][firstZeroCol] != firstZeroCol){
                cout<<matrix[i][firstZeroCol]<<endl;
                for(int j = 0;j < col;j ++){
                    matrix[j][matrix[i][firstZeroCol]] = 0;
                }
            }
        }
        cout<<firstZeroRow<<endl;
        if(firstZeroRow != -1){
            for(int i = 0;i < row;i ++){
                matrix[firstZeroRow][i] = 0;
            }
            for(int j = 0;j < col;j ++){
                matrix[j][firstZeroCol] = 0;
            }
        }
    }
    
int main(){
    vector<vector<int> > input;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(5);
    input.push_back(temp);
    temp.clear();
    temp.push_back(4);
    temp.push_back(3);
    temp.push_back(1);
    temp.push_back(4);
    input.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(4);
    input.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(3);
    input.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    input.push_back(temp);
    setZeroes(input);
    for(int i = 0;i < input.size();i ++){
        for(int j = 0;j < input[0].size();j ++){
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}