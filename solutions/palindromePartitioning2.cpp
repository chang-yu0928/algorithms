#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minCut(string s) {
		int len = s.size();
		if(len < 1) {
			return 0;
		}
		vector<vector<bool> > isPalin(len, vector<bool>(len, false));
		vector<int> cut(len + 1);
		for(int i = 0;i <= len;i ++) {
			cut[i] = i - 1;
		}
        for(int i = 1; i < len;i ++) {
        	for(int j = i;j >= 0;j --) {
        		if(s[i] == s[j] && (i - j < 2 || isPalin[i-1][j+1])) {
        			isPalin[i][j] = true;
        			cut[i+1] = min(cut[i+1], cut[j] + 1);
        		}
        	}
        }
        return cut[len];
    }
    
    int main() {
    	cout<<minCut("cabababcbc")<<endl;
    	return 0;
    }