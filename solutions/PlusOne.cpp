#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1;i >= 0;i --) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
            if(!carry) break;
        }
        if(carry) digits.insert(digits.begin(), carry);
        return digits;
    }
    
int main(){
    vector<int> digits(1);
    digits[0] = 9;
    vector<int> result = plusOne(digits);
    for(int i = 0;i < result.size();i ++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}