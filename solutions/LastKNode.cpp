#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v): val(v), next(NULL) {}
};

Node *lastKNode(Node* head, int k) {
	Node *fast = head, *slow = head;
	for(int i = 0;i < k;i ++) {
		if(fast == NULL) {
			break;
		}
		fast = fast->next;
	}
	
	while(fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	
	return slow;
}

int main() {
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next->next = new Node(9);
	head->next->next->next->next->next->next->next->next->next = new Node(10);
	cout<<lastKNode(head, 11)->val<<endl;
	return 0;
}