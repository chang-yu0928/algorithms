#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> container;
        vector<int> result;
        for(int i = 0;i < numbers.size();i ++) {
            int temp = target-numbers[i];
            if(container.find(temp) != container.end()){
                result.push_back(i+1);
                result.push_back(container[temp]+1);
                break;
            }else{
            	container[numbers[i]] = i;
            }
        }
        return result;
    }

int main(){
	vector<int> input;
	input.push_back(3);
	input.push_back(2);
	input.push_back(4);
	input.push_back(5);
	vector<int> output = twoSum(input, 6);
	for(int i = 0;i < output.size();i ++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return 0;
}
