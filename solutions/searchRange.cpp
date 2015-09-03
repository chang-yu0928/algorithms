#include <iostream>
#include <vector>

using namespace std;

void searchRange(vector<int> &nums, int target, int start, int end, vector<int> &result) {
        if(start > end) {
            return;
        }
        int mid = (start + end) / 2;
        if(nums[mid] == target) {
            if(mid - 1 >= 0 && nums[mid - 1] == target) {
                searchRange(nums, target, start, mid - 1, result);
            } else {
                result.push_back(mid);
            }
            
            if(mid + 1 <= nums.size() && nums[mid + 1] == target) {
                searchRange(nums, target, mid + 1, end, result);
            } else {
                result.push_back(mid);
            }
        } else if(nums[mid] > target) {
            searchRange(nums, target, start, mid - 1, result);
        } else {
            searchRange(nums, target, mid + 1, end, result);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        searchRange(nums, target, 0, nums.size() - 1, result);
        if(result.size() == 0) {
        	result.push_back(-1);
        	result.push_back(-1);
        }
        return result;
    }
    
    int main() {
    	vector<int> nums(6);
    	nums[0]=0;nums[1]=0;nums[2]=0;nums[3]=1;nums[4]=2;nums[5]=3;
    	vector<int> result = searchRange(nums, 0);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }