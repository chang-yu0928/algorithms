#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
        vector<int> result(digits.size());
        int add = 1;
        for(int i = digits.size() - 1;i >= 0;i ++){
            if(digits[i] == 1 && add == 1){
                add = 1;
                result[i] = 0;
            }else if(digits[i] == 0 && add == 1){
                add = 0;
                result[i] = 1;
            }else{
                result[i] = digits[i];
            }
        }
        return result;
    }
    
int main(){
    
}