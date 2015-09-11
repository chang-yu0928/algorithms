#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
    static bool comp(int num1, int num2) {
        string temp1 = to_string(num1) + to_string(num2);
        string temp2 = to_string(num2) + to_string(num1);
        return temp1 > temp2;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        stringstream res;
        for(int i = 0;i < nums.size();i ++) {
            res << nums[i];
        }
        return res.str();
    }

int main(){
	vector<int> input;
	input.push_back(12);
	input.push_back(121);
	// input.push_back(0);
	// input.push_back(0);
	// input.push_back(9);
	cout<<largestNumber(input)<<endl;
	return 0;
}