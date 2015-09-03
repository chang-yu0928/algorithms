#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int compute(char op, int n1, int n2) {
        if(op == '+') return (n1 + n2);
        else if(op == '-') return (n1 - n2);
        else return (n1 * n2);
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> left, right, result;
        int len = input.size(), i, j, k, num = 0;
        for(i = 0;i < len;i ++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i + 1, len - i - 1));
                for(j = 0;j < left.size();j ++) {
                    for(k = 0;k < right.size();k ++) {
                        result.push_back(compute(input[i], left[j], right[k]));
                    }
                }
            }
        }
        if(result.empty()) result.push_back(atoi(input.c_str()));
        return result;
    }
    
    int main() {
    	string input("2*3-4*5");
    	vector<int> result = diffWaysToCompute(input);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    }