#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int n): val(n), next(NULL) {}
};

Node *reverse(Node *head) {
	if(head == NULL){
		return NULL;
	}
	Node *tempPtrF = head, *tempPtrM = head->next, *tempPtrL = head->next;
	tempPtrF->next = NULL;
	while(tempPtrM != NULL){
		//cout<<tempPtrF->val<<" ";
		tempPtrL = tempPtrM->next;
		tempPtrM->next = tempPtrF;
		tempPtrF = tempPtrM;
		tempPtrM = tempPtrL;
	}
	//cout<<endl;
	return tempPtrF;
}

int main(){
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head = reverse(head);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}