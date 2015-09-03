#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
        stack<char> sta;
        for(int i = 0;i < s.size();i ++) {
            if(s[i] == ')') {
                if(sta.top() != '(') return false;
                sta.pop();
            } else if(s[i] == '}') {
                if(sta.top() != '{') return false;
                sta.pop();
            } else if(s[i] == ']') {
                if(sta.top() != '[') return false;
                sta.pop();
            } else {
                sta.push(s[i]);
            }
        }
        return sta.empty();
    }
    
int main(){
	cout<<isValid("(()[]{}")<<endl;
	return 0;
}