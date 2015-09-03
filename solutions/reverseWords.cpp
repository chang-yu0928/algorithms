#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s) {
		int start = -1, i = 0;
		while(i < s.size()) {
			if(s[i] == ' ') {
				if(i - 1 == -1 || s[i-1] == ' ') {
					s.erase(i, 1);
					i --;
				} else {
					reverse(s.begin() + start + 1, s.begin() + i);
					start = i;
				}
			}
			i ++;
		}
		if(s[i-1] != ' ') reverse(s.begin() + start + 1, s.end());
		else s.erase(i-1, 1);
		reverse(s.begin(), s.end());
    }
    
    int main() {
    	string s("the sky is  blue    ");
    	reverseWords(s);
    	cout<<s<<endl;
    	return 0;
    }