#include <iostream>
#include <stack>
using namespace std;

class Tower {
private:
	stack<int> plates;
	int index;
public:
	Tower(stack<int> s, int i): plates(s), index(i) {}
	
	~Tower() {}
	
	int getIndex() {
		return index;
	}
	
	int getSize(){
		return plates.size();
	}
	
	void moveOnTop(int plate) {
		plates.push(plate);
		cout<<" to Tower No."<<index<<endl;
	}
	
	int popFromPlates(){
		int plate = plates.top();
		plates.pop();
		cout<<"move "<<plate<<" from Tower No. "<<index;
		return plate;
	}
};

void moveHanoi(int number, Tower &origin, Tower &target, Tower &buffer){
	if(number <= 0){
		return;
	}
	moveHanoi(number-1, origin, buffer, target);
	int temp = origin.popFromPlates();
	target.moveOnTop(temp);
	moveHanoi(number-1, buffer, target, origin);
}

int main(){
	stack<int> s0, s1, s2;
	Tower target(s2, 2);
	Tower buffer(s1, 1);
	s0.push(2);
	s0.push(1);
	s0.push(0);
	Tower origin(s0, 0);
	moveHanoi(3, origin, target, buffer);
	return 0;
}