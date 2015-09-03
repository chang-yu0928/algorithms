#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target, int left, int right) {
	if(left > right) {
		return false;
	}
	int mid = (left + right) / 2;
	if(nums[mid] == target) {
		return true;
	}
	if(nums[right] == nums[left]) {
		return (search(nums, target, mid + 1, right) || search(nums, target, left, mid - 1));
	} 
	if(nums[mid] <= nums[right]) {
		if(target > nums[mid] && target <= nums[right])
			return search(nums, target, mid + 1, right);
		else
			return search(nums, target, left, mid - 1);
	} 
	if(nums[mid] >= nums[left]) {
		if(target >= nums[left] && target < nums[mid])
			return search(nums, target, left, mid - 1);
		else
			return search(nums, target, mid + 1, right);
	}
	return false;
}

bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
    
    int main() {
    	vector<int> input;
    	input.push_back(4);input.push_back(5);input.push_back(1);input.push_back(2);input.push_back(3);input.push_back(3);
    	cout<<search(input, 6)<<endl;
    	return 0;
    }