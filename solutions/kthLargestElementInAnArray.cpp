#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int start, int end) {
        int big = start;
        for(int i = start;i < end;i ++) {
            if(nums[i] > nums[end]) {
            	swap(nums[i], nums[big]);
                big ++;
            }
        }
        swap(nums[big], nums[end]);
        return big;
    }
    int findKthLargest(vector<int> &nums, int k, int start, int end) {
        if(start >= end) return nums[end];
        int index = partition(nums, start, end), x = index - start + 1;
        if(x > k) {
            return findKthLargest(nums, k, start, index - 1);
        } else if(x < k) {
            return findKthLargest(nums, k - x, index + 1, end);
        } else {
            return nums[index];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }
    
    int main() {
    	int x[] = {2,1};
    	vector<int> nums(x, x + sizeof(x)/sizeof(int));
    	cout<<findKthLargest(nums, 1)<<endl;
    	return 0;
    }