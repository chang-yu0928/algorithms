#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

    vector<string> tokenlize(string &s) {
        string num;
        vector<string> result;
        for(int i = 0;i < s.size();i ++) {
            if(s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else if(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
                if(num.size() != 0) {
                    result.push_back(num);
                    num.clear();
                }
                result.push_back(string(1, s[i]));
            } else {
                if(num.size() != 0) {
                    result.push_back(num);
                    num.clear();
                }
            }
        }
        if(num.size() != 0) {
            result.push_back(num);
        }
        return result;
    }

    int calculate(string s) {
        stack<int> nums;
        stack<string> calculators;
        vector<string> tokens = tokenlize(s);
        for(int i = 0;i < tokens.size();i ++) {
            if(tokens[i] == "-" || tokens[i] == "+") {
                calculators.push(tokens[i]);
            } else if(tokens[i] == "*") {
                int num1 = nums.top();
                nums.pop();
                int num2 = atoi(tokens[++i].c_str());
                nums.push(num1 * num2);
            } else if(tokens[i] == "/") {
                int num1 = nums.top();
                nums.pop();
                int num2 = atoi(tokens[++i].c_str());
                nums.push(num1 / num2);
            }else {
                nums.push(atoi(tokens[i].c_str()));
            }
        }
        int result = 0;
        while(!calculators.empty()) {
            string c = calculators.top();
            calculators.pop();
            int num = nums.top();
            nums.pop();
            if(c == "+") {
                result += num;
            } else {
                result -= num;
            } 
        }
        int num = nums.top();
        nums.pop();
        result += num;
        return result;
    }
    
int main() {
    string input("3+5 / 2 ");
    cout<<calculate(input)<<endl;
    return 0;
}