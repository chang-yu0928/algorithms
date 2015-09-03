#include <iostream>
#include <vector>
using namespace std;

void combine(vector<int> &candidates, int target, vector<vector<int> > &result, vector<int> mediate, int start);

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
                combine(candidates, target - candidates[i], result, mediate, i);
                mediate.pop_back();
            }
        }
    }
    


int main() {
	vector<int> input;
	input.push_back(2);
	input.push_back(2);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	vector<vector<int> > result = combinationSum(input, 5);
	for(int i = 0;i < result.size();i ++) {
		for(int j = 0;j < result[i].size();j ++) {
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}