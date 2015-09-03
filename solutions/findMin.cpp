#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &num);
int main(){
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(0);
    temp.push_back(1);
    cout<<findMin(temp)<<endl;
    int x = 1;
    int xxx = 1;
    return 0;
}

int findMin(vector<int> &num){
    int length = num.size();
    if(length == 0){
        return 0;
    }
    if(length == 1){
        return num[0];
    }
    int i = 1;
    for(;i < length;i ++){
        if(num[i] < num[i - 1]){
            return num[i];
        }
    }
    if(i == length){
        return num[0];
    }
    return 0;
}
