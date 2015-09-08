#include <iostream>
#include <vector>
using namespace std;

    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (size == 0) {
            return 0;
        }
        int l = 0, r = size - 1; 
        while (l < r) {
            int m = (l + r) / 2;
            if (citations[m] < size - m) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (!citations[r]) {
            return 0;
        } else {
            return size - r;
        }
    }
    
    int main() {
    	int ci[] = {11, 15};
    	vector<int> citations(ci, ci + sizeof(ci)/sizeof(int));
    	cout<<hIndex(citations)<<endl;
    	return 0;
    }