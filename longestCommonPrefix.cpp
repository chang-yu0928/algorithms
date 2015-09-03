#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string sub;
        if(len == 0) return sub;
        sub = strs[0];
        for(int i = 1;i < strs.size();i ++) {
            while(strs[i].find(sub) != 0) {
                sub.pop_back();
            }
        }
        return sub;
    }
    
    int main() {
    	return 0;
    }