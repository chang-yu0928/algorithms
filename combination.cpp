#include <iostream>
#include <vector>

using namespace std;

void combine(vector<vector<int> > &result, vector<int> &part, int n, int k, int start) {
	if(k == 0) {
		result.push_back(part);
		return;
	}
	for(int i = start;i <= n;i ++) {
		part.push_back(i);
		combine(result, part, n, k - 1, i + 1);
		part.pop_back();
	}
}

vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> part;
        combine(result, part, n, k, 1);
        return result;
    }
    
    int main(int args, char **argv) {
    	int n = atoi(argv[1]);
    	int k = atoi(argv[2]);
    	
    	vector<vector<int> > result = combine(n, k);
    	for(int i = 0;i < result.size();i ++) {
    		for(int j = 0;j < result[i].size();j ++) {
    			cout<<result[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }