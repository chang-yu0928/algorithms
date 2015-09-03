#include <iostream>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t) {
        char container[256];
        char sets[256];
        memset(container, '#', 256);
        memset(sets, '#', 256);
        for(int i = 0;i < s.size();i ++) {
            if(container[s[i]] == '#') {
            	if(sets[t[i]] != '#') {
            		return false;
            	}
                container[s[i]] = t[i];
                sets[t[i]] = s[i];
            } else {
                if(container[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int main() {
    	cout<<isIsomorphic("qwertyuiop[]asdfghjkl;'\\zxcvbnm,./", "',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz")<<endl;
    	return 0;
    }