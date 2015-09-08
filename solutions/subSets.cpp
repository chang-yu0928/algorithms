#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int> > result;
        vector<int> part;
        result.push_back(part);
        sort(nums.begin(), nums.end());
        for(int i = 0;i < len;i ++) {
            int dummy = result.size();
            for(int j = 0;j < dummy;j ++) {
                part = result[j];
                part.push_back(nums[i]);
                result.push_back(part);
            }
        }
        return result;
    }
    
    int main() {
    	vector<int> nums;
    	nums.push_back(1);nums.push_back(2);nums.push_back(3);
    	vector<vector<int> > result = subsets(nums);
    	for(int i = 0;i < result.size();i ++) {
    		for(int j = 0;j < result[i].size();j ++) {
    			cout<<result[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }