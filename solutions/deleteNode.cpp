#include <iostream>
using namespace std;

struct ListNode {
 	int val;
  	ListNode *next;
  	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
        if(node == NULL) {
            return;
        }
        ListNode *follower = node->next;
        while(follower != NULL) {
            node->val = follower->val;
            node = follower;
            follower = follower->next;
        }
        delete node;
    }
    
int main() {
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	ListNode *temp = head;
	deleteNode(head);
	cout<<temp->val<<endl;
	return 0;
}