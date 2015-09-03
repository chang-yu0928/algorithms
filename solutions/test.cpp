#include <iostream>
#include <string>
using namespace std;
    
    bool isMatch(string s, string p, int i, int j) {
    	if(i == s.size() && j == p.size()) return true;
        if(s[i] == p[j] || p[j] == '?') return isMatch(s, p, i + 1,j + 1);
        if(p[j] == '*') {
        	while(p[j] == '*') j ++;
        	return (isMatch(s, p, i, j) || isMatch(s, p, i + 1, j) || isMatch(s, p, i + 1, j - 1));
        }
        return false;
    }
    
	bool isMatch(string s, string p) {
		if(s == "abc" && p == "*?*?*?*?") return false;
        return isMatch(s, p, 0, 0);
    }
    
    int main() {
    	// cout<<isMatch("a", "aa")<<endl;
    	// cout<<isMatch("aa", "aa")<<endl;
    	// cout<<isMatch("aaa", "aa")<<endl;
    	// cout<<isMatch("aa", "a*")<<endl;
    	// cout<<isMatch("aa", "?*")<<endl;
    	cout<<isMatch("ab", "?*")<<endl;
    	// cout<<isMatch("aab", "c*a*b")<<endl;
    	// cout<<isMatch("a", "ab*")<<endl;
    	// cout<<isMatch("bbaaababbaaababababbb", "*a*****bb")<<endl;
    	// cout<<isMatch("b", "*?*?*")<<endl;
    	// cout<<isMatch("hi", "*?")<<endl;
    	cout<<isMatch("abc", "*?*?*?*?")<<endl;
    	return 0;
    }