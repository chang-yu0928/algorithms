#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
        int lastS = -1, lastP = -1, i, j, len1 = s.size(), len2 = p.size();
        for(i = 0, j = 0;i < len1;i ++, j ++) {
            if(p[j] == '*') {
                lastS = i;
                lastP = j;
                i --;
            } else {
                if(p[j] != '?' && p[j] != s[i]) {
                    if(lastS >= 0) {
                        i = lastS ++;
                        j = lastP;
                    } else return false;
                }
            }
        }
        while(j < len2 && p[j] == '*') j ++;
        return (j == len2);
    }
    
    int main() {
    	cout<<isMatch("a", "aa")<<endl;
    	cout<<isMatch("aa", "aa")<<endl;
    	cout<<isMatch("aaa", "aa")<<endl;
    	cout<<isMatch("aa", "a*")<<endl;
    	cout<<isMatch("aa", "?*")<<endl;
    	cout<<isMatch("ab", "?*")<<endl;
    	cout<<isMatch("aab", "c*a*b")<<endl;
    	cout<<isMatch("a", "ab*")<<endl;
    	cout<<isMatch("bbaaababbaaababababbb", "*a*****bb")<<endl;
    	cout<<isMatch("b", "*?*?*")<<endl;
    	cout<<isMatch("hi", "*?")<<endl;
    	cout<<isMatch("ba", "*a*")<<endl;
    	return 0;
    }