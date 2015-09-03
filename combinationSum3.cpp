#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void combinationSum3(int k, int m, int n, vector<vector<int> > &result, vector<int> &part) {
        if(k == 0 && n == 0) {
            result.push_back(part);
            return;
        }
        for(int i = m;i <= min(n, 9);i ++) {
            part.push_back(i);
            combinationSum3(k - 1, i + 1, n - i, result, part);
            part.pop_back();
        }
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> part;
        combinationSum3(k, 1, n, result, part);
        return result;
    }

int main() {
	vector<vector<int> > result = combinationSum3(2, 18);
	for(int i = 0;i < result.size();i ++) {
		for(int j = 0;j < result[i].size();j ++) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}