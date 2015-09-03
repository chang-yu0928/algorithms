#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Compare {
public:
	bool operator() (int a, int b) {
		return a > b;
	}
};


int main() {
	priority_queue<int,vector<int>,Compare> pq;
	pq.push(5);
	pq.push(52);
	pq.push(15);
	pq.push(53);
	pq.push(3);
	pq.push(10);
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	return 0;
}