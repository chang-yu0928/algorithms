#include <iostream>
#include <vector>
using namespace std;

	//Simple solution using O(k) space.
	void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 0) return;
        k = k % len;
        vector<int> tempStorage;
        int i = len - k;
        while(i < len) {
        	tempStorage.push_back(nums[i]);
        	i ++;
        }
        i = len - k - 1;
        while(i >= 0) {
            nums[i+k] = nums[i];
            i --;
        }
        for(int i = 0;i < tempStorage.size();i ++) {
            nums[i] = tempStorage[i];
        }
    }
    
    
    //reverse solution.
    void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if(len == 0) return;
		k %= len;
        reverse(nums.begin(), nums.begin() + len - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    
    //
    
int main(){
	int nums[7]={1,2,3,4,5,6,7};
	vector<int> input(nums, nums + sizeof(nums)/sizeof(int));
	rotate(input, 8);
	for(int i = 0;i < 7;i ++){
		cout<<input[i]<<" ";
	}
	cout<<endl;
	return 0;
}