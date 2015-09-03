#include <iostream>
#include <vector>

using namespace std;
	
	void permute(vector<vector<int> > &result, vector<int> &nums, vector<int> part, vector<bool> available) {
		if(part.size() == nums.size()) {
			result.push_back(part);
			return;
		}
		for(int i = 0;i < nums.size();i ++) {
			if(available[i]) {
				available[i] = false;
				part.push_back(nums[i]);
				permute(result, nums, part, available);
				part.pop_back();
				available[i] = true;
			}
		}
	}

	vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> part;
        vector<bool> available(nums.size(), true);
        permute(result, nums, part, available);
        return result;
    }
    
    int main() {
    	vector<int> nums(3);
    	nums[0] = 1; nums[1] = 2; nums[2] = 3;
    	vector<vector<int> > result = permute(nums);
    	for(int i = 0;i < result.size();i ++) {
    		for(int j = 0;j < result[i].size();j ++) {
    			cout<<result[i][j] <<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }