#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	void generate(int left, int right, string container, int n, int sum, vector<string> &result) {
    	if(left == n && right == n) {
    		result.push_back(container);
    		return;
    	}
    	if(left != n) {
    		generate(left + 1, right, container + '(', n, sum + 1, result);
    	}
    	if(right != n && sum - 1 >= 0) {
    		generate(left, right + 1, container + ')', n, sum - 1, result);
    	}
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string container;
        vector<string> result;
        generate(0, 0, container, n, 0, result);
        return result;
    }
};

int main(){
	Solution s;
	vector<string> output;
	output = s.generateParenthesis(3);
	for(int i = 0;i < output.size();i ++) {
		cout<<output[i]<<" ";
	}
	cout<<endl;
}