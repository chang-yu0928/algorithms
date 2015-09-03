#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> temp;
        vector<int> other;
        vector<int> result;
        //corner case
        if(numbers.size() == 0){
            return result;
        }
        unordered_set<int> hashTable;
        for(int i = 0;i < numbers.size();i ++){
            hashTable.insert(numbers[i]);
        }
        for(int i = 0;i < numbers.size();i ++){
            if(hashTable.find(target - numbers[i]) != hashTable.end()){
                temp.push_back(i);
                other.push_back(target - numbers[i]);
            }
        }
        for(int i = 0;i < temp.size();i ++){
            for(int j = 0;j < numbers.size();j ++){
                if(other[i] == numbers[j]){
                    if(j != temp[i] && j > temp[i]){
                        result.push_back(temp[i]+1);
                        result.push_back(j+1);
                    }
                }
            }
        }
        return result;
    }
    
int main(){
    vector<int> temp;
    temp.push_back(3);
    temp.push_back(2);
    temp.push_back(4);
    vector<int> v = twoSum(temp, 6);
    for(int i = 0;i < v.size();i ++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}