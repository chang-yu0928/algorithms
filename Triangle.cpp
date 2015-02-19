#include <iostream>
#include <vector>
using namespace std;
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> > minLevel;
        for(int n = 0;n < triangle.size();n ++){
            vector<int> temp;
            if(n == 0){
                temp.push_back(triangle[n][n]);
            }else{
                for(int i = 0;i < triangle[n].size();i ++){
                    int left = 0, right = 0;
                    bool flagLeft = false, flagRight = false;
                    if(i <= n - 1){
                        right = triangle[n][i] + minLevel[n-1][i];
                        flagRight = true;
                    }
                    if(i - 1 >= 0){
                        left = triangle[n][i] + minLevel[n-1][i-1];
                        flagLeft = true;
                    }
                    if(!flagLeft){
                        temp.push_back(right);
                    }else if(!flagRight){
                        temp.push_back(left);
                    }else if(left > right){
                        temp.push_back(right);
                    }else{
                        temp.push_back(left);
                    }
                }
            }
            minLevel.push_back(temp);
        }
        int min = minLevel[minLevel.size() - 1][0];
        for(int i = 0;i < minLevel[minLevel.size() - 1].size();i ++){
            if(minLevel[minLevel.size() - 1][i] < min){
                min = minLevel[minLevel.size() - 1][i];
            }
        }
        cout<<minLevel[0][0]<<"\n"<<minLevel[1][0]<<" "<<minLevel[1][1]<<"\n"<<minLevel[2][0]<<" "<<minLevel[2][1]<<" "<<minLevel[2][2]<<endl;
        return min;
    }

int main(){
    vector<vector<int> > v;
    vector<int> temp1;
    vector<int> temp2;
    vector<int> temp3;
    temp1.push_back(-1);
    temp2.push_back(2);
    temp2.push_back(3);
    temp3.push_back(1);
    temp3.push_back(-1);
    temp3.push_back(-3);
    v.push_back(temp1);
    v.push_back(temp2);
    v.push_back(temp3);
    cout<<v[0][0]<<"\n"<<v[1][0]<<" "<<v[1][1]<<"\n"<<v[2][0]<<" "<<v[2][1]<<" "<<v[2][2]<<endl;
    cout<<minimumTotal(v)<<endl;
    return 0;
}