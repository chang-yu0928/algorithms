#include <iostream>
using namespace std;

	int rangeBitwiseAnd(int m, int n) {
        int bits[32], base = 1, range = m - n + 1, result = 0, i = 0, k;
        memset(bits, 0, sizeof(bits));
        while(n > 0) {
            for(k = m;k <= n;k ++) {
                if(k % 2 == 0) {
                    bits[i] = 0;
                    break;
                }
            }
            if(k == n + 1) bits[i] = 1;
            i ++;
            m = m >> 1;
            n = n >> 1;
        }
        for(int i = 0;i < 32;i ++) {
            result = result + base * bits[i];
            base *= 2;
        }
        return result;
    }
    
   	int main() {
   		cout<<rangeBitwiseAnd(2147483647, 2147483647)<<endl;
   		return 0;
   	}