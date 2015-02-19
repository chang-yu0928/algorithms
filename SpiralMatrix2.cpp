#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        int flag = 0;
        int boundaryL = -1;
        int boundaryH = n;
        int x = 0;
        int y = 0;
        for(int i = 1;i < n*n + 1;i ++){
            switch(flag){
                case 0: {
                    if(y < boundaryH){
                        result[x][y] = i;
                        y ++;
                    }else{
                        flag = 1;
                        y = boundaryH - 1;
                        x ++;
                        i --;
                    }
                    break;
                };
                case 1: {
                    if(x < boundaryH){
                        result[x][y] = i;
                        x ++;
                    }else{
                        flag = 2;
                        x = boundaryH - 1;
                        y --;
                        i --;
                        boundaryH --;
                    }
                    break;
                };
                case 2: {
                    if(y > boundaryL){
                        result[x][y] = i;
                        y --;
                    }else{
                        flag = 3;
                        y = boundaryL + 1;
                        x --;
                        i --;
                        boundaryL ++;
                    }
                    break;
                };
                case 3: {
                    if(x > boundaryL){
                        result[x][y] = i;
                        x --;
                    }else{
                        flag = 0;
                        x = boundaryL + 1;
                        y ++;
                        i --;
                    }
                    break;
                };
            }
        }
        return result;
    }
    
int main(){
    vector<vector<int> > result = generateMatrix(1);
    for(int i = 0;i < result.size();i ++){
        for(int j = 0;j < result[0].size();j ++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}