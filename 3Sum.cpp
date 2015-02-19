#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3){
            return result;
        }
        sort(num.begin(), num.end());
        for(int i = 0;i < num.size();){
            int n = num[i];
            for(int j = i + 1;j < num.size();){
                int m = num[j];
                for(int k = j + 1;k < num.size();k ++){
                    if(n + m + num[k] == 0){
                        vector<int> temp;
                        temp.push_back(m);
                        temp.push_back(n);
                        temp.push_back(num[k]);
                        result.push_back(temp);
                    }
                }
                do{
                    j += 1;
                }while(j < num.size() && num[j] == m);
            }
            do{
                i += 1;
            }while(i < num.size() && num[i] == n);
        }
        return result;    
    }
    
    
int main(){
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(0);
    temp.push_back(-1);
    temp.push_back(2);
    temp.push_back(-1);
    temp.push_back(4);
    vector<vector<int> > result = threeSum(temp);
    for(int i = 0;i < result.size();i ++){
        for(int j = 0; j < result[i].size();j ++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}