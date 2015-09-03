#include <iostream>
#include <vector>
using namespace std;

void combine(vector<int> &candidates, int target, vector<vector<int> > &result, vector<int> mediate, int start);

vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> mediate;
        combine(candidates, target, result, mediate, 0);
        return result;
    }
    
    void combine(vector<int> &candidates, int target, vector<vector<int> > &result, vector<int> mediate, int start) {
        for(int i = start;i < candidates.size();i ++) {
            if(target - candidates[i] == 0) {
                mediate.push_back(candidates[i]);
                result.push_back(mediate);
            } else if(target - candidates[i] > 0) {
                mediate.push_back(candidates[i]);
                combine(candidates, target - candidates[i], result, mediate, i+1);
                mediate.pop_back();
            }
            while(candidates[i] == candidates[i + 1]) i ++;
        }
    }
    


int main() {
	vector<int> input;
	input.push_back(1);
	input.push_back(1);

	vector<vector<int> > result = combinationSum2(input, 1);
	for(int i = 0;i < result.size();i ++) {
		for(int j = 0;j < result[i].size();j ++) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}