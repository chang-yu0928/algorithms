#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isScramble(string s1, string s2) {
        int length = s1.size();
        if(s1 == s2) {
            return true;
        }
        int count[26] = {0};
        for(int i = 0;i < length;i ++) {
            count[s1[i] - '0'] ++;
            count[s2[i] - '0'] --;
        }
        for(int i = 0;i < 26;i ++) {
            if(count[i] != 0) {
                return false;
            }
        }
        for(int i = 1;i < length;i ++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, length-i), s2.substr(i, length-i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(length-i, i)) && isScramble(s1.substr(i, length-i), s2.substr(0, length-i)))
                return true;
        }
        return false;
    }
    
    int main() {
    	cout<<isScramble("b", "a")<<endl;
    	return 0;
    }