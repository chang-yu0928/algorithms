#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void permute(vector<int> &nums, int i, int n, vector<vector<int> > &result) {
        if(i == n) {
            result.push_back(nums);
        }
        int prev = nums[i];
        for(int j = i;j < n;j ++) {
            if(j != i && (nums[j] == prev || nums[j] == nums[i])) continue;
            prev = nums[j];
            swap(nums[i], nums[j]);
            permute(nums, i+1, n, result);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        permute(nums, 0, nums.size(), result);
        return result;
    }
    
    int main() {
    	vector<int> nums;
    	nums.push_back(3);nums.push_back(3);nums.push_back(0);nums.push_back(0);nums.push_back(2);nums.push_back(3);nums.push_back(2);
    	vector<vector<int> > result = permuteUnique(nums);
    	for(int i = 0;i < result.size();i ++) {
    		for(int j = 0;j < result[i].size();j ++) {
    			cout<<result[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }