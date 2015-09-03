#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool checkPalindrome(string s, int end) {
        int length = end / 2;
        for(int i = 0;i <= length;i ++) {
            if(s[i] != s[end - i]) {
                return false;
            }
        }
        return true;
    }
    
    string shortestPalindrome(string s) {
        int end = s.size() - 1;
        stringstream ss;
        for(int i = end; i > 0;i --) {
            if(s[i] != s[0]) {
                ss << s[i];
            } else {
                if(!checkPalindrome(s, i)) {
                    ss << s[i];
                } else {
                    break;
                }
            }
        }
        ss << s;
        return ss.str();
    }
    
    int main() {
    	cout<<shortestPalindrome("abcd")<<endl;
    	return 0;
    }