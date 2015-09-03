#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        for(int i = 0;i < num.size();i ++){
            int front = i+1;
            int back = num.size()-1;
            while(front < back){
                int temp = num[i]+num[front]+num[back];
                if(temp == 0){
                    vector<int> resultPart;
                    resultPart.push_back(num[i]);
                    resultPart.push_back(num[front]);
                    resultPart.push_back(num[back]);
                    result.push_back(resultPart);
                    front ++;
                    while(num[front-1] == num[front] && front < num.size()){
                        front ++;
                    }
                    back --;
                    while(num[back] == num[back+1] && back >= 0){
                        back --;
                    }
                }else if(temp < 0){
                    front ++;
                    while(num[front-1] == num[front] && front < num.size()){
                        front ++;
                    }
                }else{
                    back --;
                    while(num[back] == num[back+1] && back >= 0){
                        back --;
                    }
                }
            }
            while(num[i] == num[i+1] && i < num.size()){
                i ++;
            }
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
    temp.push_back(-4);
    vector<vector<int> > result = threeSum(temp);
    for(int i = 0;i < result.size();i ++){
        for(int j = 0; j < result[i].size();j ++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}