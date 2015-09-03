#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string multiply(string num1, string num2) {
		string result;
        stringstream ss;
        int len1 = num1.size(), len2 = num2.size(), index = 0, carry, p1, p2, n1, n2, i;
        int con[len1 + len2];
        memset(con, 0, sizeof(con));
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(p1 = 0;p1 < len1;p1 ++) {
        	carry = 0;
            n1 = num1[p1] - '0';
            for(p2 = 0;p2 < len2;p2 ++) {
                n2 = num2[p2] - '0';
                int dummy = n1 * n2 + carry;
                con[p2 + index] += (dummy % 10);
                carry = dummy / 10;
                if(con[p2 + index] >= 10) {
                    con[p2 + index] = con[p2 + index] % 10;
                    carry ++;
                }
            }
            con[p2 + index] = carry;
            index ++;
        }
        for(i = len1 + len2 - 1;i >= 0 ;i --) {
            if(con[i] != 0) break;
        }
        for(;i >= 0;i --) {
        	ss << con[i];
        }
        result = ss.str();
        if(result.empty()) {
        	result += '0';
        }
        return result;
    }
    
int main() {
	cout<<multiply("56789", "98765")<<endl;
	return 0;
}