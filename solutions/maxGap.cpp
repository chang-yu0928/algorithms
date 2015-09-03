#include <iostream>
#include <vector>

using namespace std;

int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        int m = INT_MIN, n = INT_MAX, maxGap = INT_MIN;
        vector<int> maximum(nums.size(), INT_MIN), minimun(nums.size(), INT_MAX);
        for(int i = 0;i < nums.size();i ++) {
            if(m < nums[i]) {
                m = nums[i];
            }
            if(n > nums[i]) {
                n = nums[i];
            }
        }
        for(int i = 0;i < nums.size();i ++) {
            int index = (double) (nums[i] - n) / (m - n) * (nums.size() - 1);
            maximum[index] = max(maximum[index], nums[i]);
            minimun[index] = min(minimun[index], nums[i]);
        }
        int pre = maximum[0];
        for(int i = 1;i < nums.size();i ++) {
            if(maximum[i] == INT_MIN)
                continue;
            maxGap = max(maxGap, (minimun[i] - pre));
            pre = maximum[i];
        }
        return maxGap;
    }
    
    int main() {
    	vector<int> nums(2);
    	nums[0] = 1;nums[1] = 10000000;
    	cout<<maximumGap(nums)<<endl;
    	return 0;
    }