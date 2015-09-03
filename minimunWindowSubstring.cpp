#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string minWindow(string s, string t) {
		int slen = s.size(), tlen = t.size();
		int p = 0, count = tlen, minLen = INT_MAX, minStart = 0;
        int dict[128];
        for(int i = 0;i < 128;i ++) {
        	dict[i] = -slen;
        }
        for(int i = 0;i < tlen;i ++) {
        	dict[t[i]] = dict[t[i]] > 0 ? (dict[t[i]] + 1) : 1;
        }
        for(int i = 0;i < slen;i ++) {
        	if(--dict[s[i]] >= 0) {
        		count --;
        		if(count == 0) {
        			while(++dict[s[p]] <= 0) {
        				p ++;
        			}
        			int len = i - p + 1;
        			if(len < minLen) {
        				minLen = len;
        				minStart = p;
        			}
        			p ++;
        			count = 1;
        		}
        	}
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
    
    int main() {
    	cout<<minWindow("a", "a")<<endl;
    	return 0;
    }