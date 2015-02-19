#include <iostream>
#include <vector>
#include <string>
using namespace std;
void combine(string digits, int index, char container[8][6], char *buffer, vector<string> &result);
vector<string> letterCombinations(string digits) {
        vector<string> result;
        char *buffer = new char[digits.size()+1];
        char container[10][6] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combine(digits, 0, container, buffer, result);
        return result;
    }
    void combine(string digits, int index, char container[8][6], char *buffer, vector<string> &result) {
        if(digits.size() == index){
            string temp(buffer, index);
            result.push_back(temp);
            return;
        }else{
            int number = digits[index] - '2';
            int n = 0;
            if(number == 5 || number == 7){
            	n = 4;
            }else{
            	n = 3;
            }
            for(int i = 0;i < n;i ++){
                buffer[index] = container[number][i];
                combine(digits, index+1, container, buffer, result);
            }
        }
    }
int main(){
	vector<string> output = letterCombinations("23");
	for(int i = 0;i < output.size();i ++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return 0;
}