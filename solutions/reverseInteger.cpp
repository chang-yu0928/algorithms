#include <iostream>
using namespace std;

int reverse(int x) {
        int result = 0;
        if(x > 0) {
            while(x > 0) {
                int digit = x % 10;
                x /= 10;
                if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)) {
                    return 0;
                } else {
                    result = result * 10 + digit;
                }
            }
        } else {
            if(x == INT_MIN) return 0;
            x *= -1;
            while(x > 0) {
                int digit = x % 10;
                x /= 10;
                if(result < (INT_MIN / 10) || (result == (INT_MIN / 10) && digit > 8)) {
                    return 0;
                } else {
                    result = result * 10 - digit;
                }
            }
        }
        return result;
    }
    
    int main() {
    	cout<<reverse(-1563847412)<<endl;
    	return 0;
    }