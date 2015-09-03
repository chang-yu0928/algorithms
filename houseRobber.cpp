#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> goods(len);
        goods[0] = nums[0];
        goods[1] = max(nums[0], nums[1]);
        for(int i = 2;i < len;i ++) {
            goods[i] = max(goods[i-1], goods[i-2] + nums[i]);
        }
        return goods[len-1];
    }
    
    int main() {
    	vector<int> nums(4);
    	nums[0] = 2;nums[1] = 1;nums[2] = 1;nums[3] = 2;
    	cout<<rob(nums)<<endl;
    	return 0;
    }