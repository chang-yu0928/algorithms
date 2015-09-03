#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
		string curr = "1";
        for(int j = 1;j < n;j ++) {
        	string next;
        	char x = curr[0];
        	int count = 1;
        	for(int i = 0;i < curr.size();i ++) {
        		while(i + 1 < curr.size() && curr[i+1] == x) {
        			count ++;
        			i ++;
        		}
        		next += to_string(count);
        		next += x;
        		if(i+1 < curr.size()) {
        			x = curr[i+1];
        			count = 1;
        		}
        	}
        	curr = next;

        }
        return curr;
    }
    
    int main() {
    	cout<<countAndSay(5)<<endl;
    	return 0;
    }