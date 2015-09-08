#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
        int len = citations.size(), count = 0;
        vector<int> table(len + 1, 0);
        for(int i = 0;i < len;i ++) {
            if(citations[i] >= len) table[len] ++;
            else table[citations[i]] ++; 
        }
        
        for(int i = len;i >= 0;i --) {
        	count += table[i];
        	if(i <= count) return i;
        }
        return 0;
    }
    
    int main() {
    	int ci[] = {3, 0, 6, 1, 5};
    	vector<int> citations(ci, ci + sizeof(ci)/sizeof(int));
    	cout<<hIndex(citations)<<endl;
    	return 0;
    }