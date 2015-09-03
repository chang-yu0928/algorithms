#include <iostream>
#include <vector>
#include <string>
using namespace std;
    bool isMatch(string s, string p) {
    	int len1 = s.size(), len2 = p.size(), i, j;
    	vector<vector<bool> > match(len1 + 1, vector<bool>(len2 + 1));
    	match[0][0] = true;
    	for(i = 2;i < len2 + 1;i ++) {
    		if(p[i-1] == '*') match[0][i] = match[0][i-2];
    		else match[0][i] = false;
    	}
    	for(i = 1;i < len1 + 1;i ++) {
    		for(j = 1;j < len2 + 1;j ++) {
    			if(p[j-1] != '*') {
    				if(s[i-1] == p[j-1] || p[j-1] == '.') match[i][j] = match[i-1][j-1];
    				else match[i][j] = false;
    			} else {
    				if(s[i-1] == p[j-2] || p[j-2] == '.') {
    					match[i][j] = match[i-1][j-1] || match[i-1][j] || match[i][j-2];    //一个 || 多个 || 零个
    				} else {
    					match[i][j] = match[i][j-2];
    				}
    			}
    		}
    	}
    	return match[len1][len2];
    }
    
    int main() {
    	cout<<isMatch("aa", "a")<<endl;
    	cout<<isMatch("aa", "aa")<<endl;
    	cout<<isMatch("aaa", "aa")<<endl;
    	cout<<isMatch("aa", "a*")<<endl;
    	cout<<isMatch("aa", ".*")<<endl;
    	cout<<isMatch("ab", ".*")<<endl;
    	cout<<isMatch("aab", "c*a*b")<<endl;
    	cout<<isMatch("a", "ab*")<<endl;
    	cout<<isMatch("aaba", "ab*a*c*a")<<endl;
    	return 0;
    }