#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int pos = nums.size() - 1, i = 0;
        while(i <= pos) {
            if(nums[i] == val) {
                swap(nums[i], nums[pos]);
                pos --;
            } else {
                i ++;
            }
        }
        return (pos + 1);
    }
    
int main(){
	int A[] = {1};
    vector<int> nums(A, A + sizeof(A)/sizeof(int));
	cout<<removeElement(nums, 1)<<endl;
	return 0;
}