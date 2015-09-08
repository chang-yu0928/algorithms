//Ask if there is zero in the previous array.
//How to deal with the zeros.
//Can we use division.
#include <iostream>
#include <vector>

using namespace std;

//O(n), O(n)
vector<int> productArray(vector<int> nums) {
    int size = nums.size(), prod = 1;
    vector<int> left(size), result(size);
    for(int i = 0;i < size;i ++) {
        left[i] = prod;
        prod *= nums[i];
    }
    prod = 1;
    for(int i = size - 1;i >= 0;i --) {
        result[i] = left[i] * prod;
        prod *= nums[i];
    }
    return result;
}

//O(n), O(1)

vector<int> productArray2(vector<int> nums) {
    int size = nums.size(), prod = 1;
    vector<int> result(size);
    for(int i = 0;i < size;i ++) {
        result[i] = prod;
        prod *= nums[i];
    }
    prod = 1;
    for(int i = size - 1;i >= 0;i --) {
        result[i] = result[i] * prod;
        prod *= nums[i];
    }
    return result;
}

int main() {
    int arr[] = {10, 3, 5, 6, 2};
    vector<int> nums(arr, arr + 5);
    vector<int> result = productArray2(nums);
    for(int i = 0;i < result.size();i ++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
