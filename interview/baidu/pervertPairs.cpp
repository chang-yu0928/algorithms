#include <iostream>
#include <vector>
using namespace std;

int pervertPairs(vector<int> &nums, int start, int end, vector<int> &temp) {
    if(start >= end) return 0;
    int left, right, i, j, count, mid = start + ((end - start) >> 1);
    left = pervertPairs(nums, start, mid, temp);
    right = pervertPairs(nums, mid + 1, end, temp);
    i = start; j = mid + 1; count = 0;
    while(i <= mid && j <= end) {
        if(nums[i] > nums[j]) {
            count += (mid - i + 1);
            temp.push_back(nums[j]);
            j ++;
        } else {
            temp.push_back(nums[i]);
            i ++;
        }
    }
    while(i <= mid) {
        temp.push_back(nums[i]);
        i ++;
    }
    while(j <= end) {
        temp.push_back(nums[j]);
        j ++;
    }
    for(i = start;i <= end;i ++) {
        nums[i] = temp[i - start];
    }
    temp.clear();
    return (left + right + count);
}

int pervertPairs(vector<int> &nums) {
    vector<int> temp;
    return pervertPairs(nums, 0, nums.size() - 1, temp);
}

int main() {
    int input[] = {7,5,6,4};
    vector<int> nums(input, input + sizeof(input) / sizeof(int));
    cout<<pervertPairs(nums)<<endl;
    return 0;
}
