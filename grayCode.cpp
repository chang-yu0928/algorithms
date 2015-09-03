#include <iostream>
#include <vector>

using namespace std;

	vector<int> grayCode(int n) {
        vector<int> prev, curr;
        int addOn;
        for(int i = 0;i <= n;i ++) {
            if(i <= 1) {
                curr.push_back(i);
            } else {
                prev = curr;
                addOn = 1 << (i-1);
                reverse(prev.begin(), prev.end());
                for(int j = 0;j < prev.size();j ++) {
                    curr.push_back(addOn + prev[j]);
                }
            }
        }
        return curr;
    }
    
    int main(int args, char **argv) {
    	int n = atoi(argv[1]);
    	vector<int> result = grayCode(n);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }