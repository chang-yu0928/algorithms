#include <iostream>
#include <stack>
using namespace std;

bool checkParentheses(string input) {
	if(input.size() % 2 != 0) {
		return false;
	}
	stack<char> container; //store all ( ,[ and {.
	
	for(int i = 0;i < input.size();i ++) {
		if(input[i] == '(' || input[i] == '[' || input[i] == '{') {
			container.push(input[i]);
		} else if(input[i] == ')') {
			char temp = container.top();
			container.pop();
			if(temp != '(') {
				return false;
			}
		} else if(input[i] == '}') {
			char temp = container.top();
			container.pop();
			if(temp != '{') {
				return false;
			}
		} else if(input[i] == ']') {
			char temp = container.top();
			container.pop();
			if(temp != '[') {
				return false;
			}
		} else {
			cout<<"wrong input, not only (){}[]"<<endl;
			return false;
		}
	}
	return container.empty();
}

int main() {
	cout<<checkParentheses("{(){}[]")<<endl;
	return 0;
}