#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string addBinary(string a, string b) {
        int len1 = a.size() - 1, len2 = b.size() - 1, carry = 0, sum;
        stringstream result;
        string res;
        while(len1 >= 0 && len2 >= 0) {
            sum = (a[len1 --] - '0') + (b[len2 --] - '0') + carry;
            carry = sum / 2;
            sum %= 2;
            result << sum;
        }
        while(len1 >= 0) {
            sum = (a[len1 --] - '0') + carry;
            carry = sum / 2;
            sum %= 2;
            result << sum;
        }
        while(len2 >= 0) {
            sum = (b[len2 --] - '0') + carry;
            carry = sum / 2;
            sum %= 2;
            result << sum;
        }
        if(carry) result << carry;
        res = result.str();
        reverse(res.begin(), res.end());
        return res;
    }
    
int main(){
	cout<<addBinary("1","111")<<endl;
	return 0;
}