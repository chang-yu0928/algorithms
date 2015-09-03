#include <iostream>
#include <vector>
#include <string>
using namespace std;
void letterCombinations(string digits, int i, vector<string> &mapping, vector<string> &result, string &part) {
        if(i == digits.size()) {
            result.push_back(part);
            return;
        }
        int index = digits[i] - '0';
        for(int j = 0;j < mapping[index].size();j ++) {
            part += mapping[index][j];
            letterCombinations(digits, i + 1, mapping, result, part);
            part.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping(10), result;
        string part;
        mapping[0] = " ";mapping[1] = "";mapping[2] = "abc";mapping[3] = "def";mapping[4] = "ghi";
        mapping[5] = "jkl";mapping[6] = "mno";mapping[7] = "pqrs";mapping[8] = "tuv";mapping[9] = "wxyz";
        letterCombinations(digits, 0, mapping, result, part);
        return result;
    }
int main(){
	vector<string> output = letterCombinations("1");
	for(int i = 0;i < output.size();i ++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return 0;
}