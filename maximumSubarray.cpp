#include <iostream>
#include <vector>
using namespace std;

	int maxSum;
	void maxSubArray(vector<int>& nums, int start, int end) {
		if(start > end) return;
		int mid = start + ((end - start) >> 1), sum = 0, left = 0, right = 0;
		maxSubArray(nums, start, mid - 1);
		maxSubArray(nums, mid + 1, end);
		for(int i = mid - 1;i >= start;i --) {
			sum += nums[i];
			left = max(left, sum);
		}
		sum = 0;
		for(int i = mid + 1;i <= end;i ++) {
			sum += nums[i];
			right = max(right, sum);
		}
		maxSum = max(maxSum, left + right + nums[mid]);
	}

	int maxSubArray(vector<int>& nums) {
        maxSum = INT_MIN;
        maxSubArray(nums, 0, nums.size()-1);
        return maxSum;
    }
    
    int main() {
    	vector<int> nums(1);
    	nums[0]=-2;//nums[1]=1;nums[2]=-3;nums[3]=4;nums[4]=-1;nums[5]=2;nums[6]=1;nums[7]=-5;nums[8]=4;
    	cout<<maxSubArray(nums)<<endl;
    	return 0;
    }