#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
        int container[256];
        memset(container, 0, 256);
        if(s.size() != t.size()) {
            return false;
        }
        for(int i = 0;i < s.size();i ++) {
            container[s[i]] ++;
        }
        for(int i = 0;i < t.size();i ++) {
            container[t[i]] --;
            if(container[t[i]] < 0) {
                return false;
            }
        }
        return true;
    }
    
    int main() {
    	cout<<isAnagram("a", "b")<<endl;
    	return 0;
    }