#include <iostream>
using namespace std;

	int countDigitOne(int n) {
        int count = 0;
        for(int i = 0;i <= n;i ++) {
            int n = i;
            while(n > 0) {
                if(n % 10 == 1) {
                    count ++;
                }
                n /= 10;
            }
        }
        return count;
    }
    
    int main() {
    	cout<<countDigitOne(13)<<endl;
    	return 0;
    }