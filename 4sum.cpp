#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int length = num.size();
        if(length < 4){
            return result;
        }
        for(int i = 0;i < length-3;i ++){
            for(int j = i+1;j < length-2;j ++){
                int k = j+1;
                int r = length-1;
                while(k < r){
                    int sum = num[i] + num[j] + num[k] + num[r];
                    //cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<" "<<num[r]<<endl;
                    if(sum > target){
                    	r --;
                        while(num[r] == num[r+1] && r > k) r --;
                    }else if(sum < target){
                    	k ++;
                        while(num[k] == num[k-1] && k < r) k ++;
                    }else{
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[k]);
                        temp.push_back(num[r]);
                        result.push_back(temp);
                        r --;
                        k ++;
                        while(num[r] == num[r+1] && r > k) r --;
                        while(num[k] == num[k-1] && k < r) k ++;
                    }
                }
                while(num[j] == num[j+1] && j < length) j ++;
            }
            while(num[i] == num[i+1] && i < length) i ++;
        }
        return result;
    }
int main(){
	vector<int> input;
	input.push_back(-1);
	input.push_back(2);
	input.push_back(2);
	input.push_back(-5);
	input.push_back(0);
	input.push_back(-1);
	input.push_back(4);
	/*input.push_back(1);
	input.push_back(0);
	input.push_back(-1);
	input.push_back(0);
	input.push_back(2);
	input.push_back(-2);*/
	vector<vector<int> > output = fourSum(input, 3);
	for(int i = 0;i < output.size();i ++){
		for(int j = 0;j < output[i].size();j ++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}