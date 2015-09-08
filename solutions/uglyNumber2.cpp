#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        int f2 = 0, f3 = 0, f5 = 0, curr;
        uglyNumbers[0] = 1;
        for(int i = 1;i < n;i ++) {
            curr = min(uglyNumbers[f2] * 2, min(uglyNumbers[f3] * 3, uglyNumbers[f5] * 5));
            uglyNumbers[i] = curr;
            if(curr == uglyNumbers[f2] * 2) f2 ++;
            if(curr == uglyNumbers[f3] * 3) f3 ++;
            if(curr == uglyNumbers[f5] * 5) f5 ++;
        }
        return uglyNumbers[n-1];
    }
    
    int main() {
    	cout<<nthUglyNumber(10)<<endl;
    }