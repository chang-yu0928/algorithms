#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
	int len = nums.size();
	int maxPro = nums[0], minPro = nums[0], result = 0;
	for(int i = 1;i < len;i ++) {
		int prevMax = maxPro;
		maxPro = max(minPro * nums[i], max(maxPro * nums[i], nums[i]));
		minPro = min(prevMax * nums[i], min(minPro * nums[i], nums[i]));
		result = max(result, maxPro);
	}
	return result;
}

int main(){
	vector<int> nums(4);
	nums[0]=2;nums[1]=3;nums[2]=-2;nums[3]=4;
	cout<<maxProduct(nums)<<endl;
	return 0;
}