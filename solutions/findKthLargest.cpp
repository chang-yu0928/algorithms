#include <iostream>
#include <vector>

using namespace std;

	int partition(vector<int>& nums, int start, int end, int pivot) {
        int big = start;
        swap(nums[pivot], nums[end]);
        for(int i = start;i < end;i ++) {
            if(nums[i] > nums[end]) {
            	swap(nums[i], nums[big]);
                big ++;
            }
        }
        swap(nums[big], nums[end]);
        return big;
    }
    int findKthLargest(vector<int>& nums, int start, int end, int k) {
    	while(start < end) {
	        int mid = (start + end)/2;
	        int pos = partition(nums, start, end, mid);
	        if(pos > k) {
	            end = pos - 1;
	        } else if(pos < k) {
	            start = pos + 1;
	        } else {
	            return nums[pos];
	        }
	    }
	    return nums[start];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k - 1);
    }
    
    int main() {
    	vector<int> input(1);
    	input[0] = 2;//input[1] = 1;//input[2] = 0;//input[3] = 5;input[4] = 6;input[5] = 4;
    	cout<<findKthLargest(input, 1)<<endl;
    	//swap(input[0], input[1]);
    	for(int i = 0;i < input.size();i ++) {
    		cout<<input[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }