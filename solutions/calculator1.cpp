#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


//change minus to negative number.
//every time when meet a '(', save the temp result into nums, and save the sign of this result into ops.
//when meet a ')', calculate the result of nums inside () with previous result.
    int calculate(string s) {
        stack<int> nums, ops;
        int num = 0, res = 0, pos = 1;
        for(int i = 0;i < s.size();i ++) {
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else {
                res += pos * num;
                num = 0;
                if(s[i] == '+') pos = 1;
                else if(s[i] == '-') pos = -1;
                else if(s[i] == '(') {
                    nums.push(res);
                    ops.push(pos);
                    res = 0;
                    pos = 1;
                } else {
                    if(ops.size()) {
                        res = ops.top() * res + nums.top();
                        ops.pop(); nums.pop();
                    }
                }
            }
        }
        res += pos * num;
        return res;
    }
    
int main() {
	string input("(1+(4+5+2)-3)+(6+8)");
	cout<<calculate(input)<<endl;
	return 0;
}
