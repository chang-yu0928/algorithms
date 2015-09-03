#include <iostream>
#include <stack>
using namespace std;

stack<int> sort(stack<int> input){
	stack<int> result;
	while(!input.empty()){
		int temp = input.top();
		input.pop();
		while(!result.empty() && result.top() < temp){
			input.push(result.top());
			result.pop();
		}
		result.push(temp);
	}
	return result;
}

int main(){
	stack<int> s;
	s.push(5);
	s.push(5);
	s.push(6);
	s.push(1);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(7);
	s.push(8);
	stack<int> x = sort(s);
	while(!x.empty()){
		cout<<x.top()<<" ";
		x.pop();
	}
	cout<<endl;
	return 0;
}