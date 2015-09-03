#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int hashmap[128];
        memset(hashmap, -1, sizeof(hashmap));
        int start = 0, length = 0, maxLength = 0;
        for(int i = 0;i < s.size();i ++) {
            if(hashmap[s[i]] == -1) {
                length ++;
                hashmap[s[i]] = i;
            } else {
                maxLength = max(maxLength, length);
                for(int j = start;j < hashmap[s[i]];j ++) {
                    hashmap[s[j]] = -1;
                    length --;
                }
                start = hashmap[s[i]] + 1;
                hashmap[s[i]] = i;
            }
        }
        maxLength = max(maxLength, length);
        return maxLength;
    }
    
int main(){
	cout<<lengthOfLongestSubstring("abb")<<endl;
	return 0;
}