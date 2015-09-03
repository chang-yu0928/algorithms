#include <iostream>
#include <stack>
#include <string>
using namespace std;

	int longestValidParentheses(string s) {
        stack<int> sta;
        sta.push(-1);
        int x, i, maxLen = 0;
        for(i = 0;i < s.size();i ++) {
        	x = sta.top();
        	if(x != -1 && s[i] == ')' && s[x] == '(') {
        		sta.pop();
        		maxLen = max(maxLen, i - sta.top());
        	} else {
        		sta.push(i);
        	}
        }
        return maxLen;
    }    
    int main() {
    	cout<<longestValidParentheses("))))())()()(()")<<endl;
    	return 0;
    }