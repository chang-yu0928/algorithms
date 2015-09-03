#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class MyQueue{
private:
	stack<T> olderStack;
	stack<T> newerStack;
	int _size;
public:
	MyQueue(){
		_size = 0;
	}
	~MyQueue(){}
	
	void push(T element){
		newerStack.push(element);
		_size ++;
	}
	
	T pop(){
		T result;
		if(olderStack.empty()){
			if(newerStack.empty()){
				cout<<"stack is already empty!"<<endl;
				exit(-1);
			}else{
				while(!newerStack.empty()){
					int temp = newerStack.top();
					newerStack.pop();
					olderStack.push(temp);
				}
				result = olderStack.top();
				olderStack.pop();
				_size --;
			}
		}else{
			result = olderStack.top();
			olderStack.pop();
			_size --;
		}
		return result;
	}
	
	int size(){
		return _size;
	}
};

int main(){
	MyQueue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	while(que.size() != 0){
		cout<<que.pop()<<" ";
	}
	que.push(5);
	que.push(6);
	while(que.size() != 0){
		cout<<que.pop()<<" ";
	}
	cout<<endl;
	que.pop();
	return 0;
}