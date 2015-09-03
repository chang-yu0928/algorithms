#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> container;
        int result;
        container.push_back(nums[0]);
        container.push_back(max(nums[0], nums[1]));
        for(int i = 2;i < nums.size() - 1;i ++) {
        	if(i - 2 >= 0) {
            	container.push_back(max(container[i-1], (container[i-2] + nums[i])));
            }
        }
        result = container[nums.size() - 2];
        container.clear();
        container.push_back(nums[1]);
        container.push_back(max(nums[1], nums[2]));
        for(int i = 3;i < nums.size();i ++) {
            container.push_back(max(container[i-2], (container[i-3] + nums[i])));
        }
        if(result < container[nums.size() - 2]) {
            result = container[nums.size() - 2];
        }
        return result;
    }
    
    int main() {
    	vector<int> nums(7);
    	nums[0] = 4;nums[1] = 1;nums[2] = 2;nums[3] = 7;nums[4] = 5;nums[5] = 3;nums[6] = 1;
    	cout<<rob(nums)<<endl;
    	return 0;
    }