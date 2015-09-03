#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode **head, int k) {
	ListNode *tail = *head, *prev = *head, *temp;
	*head = (*head)->next;
	for(int i = 0;i < k-1;i ++) {
		temp = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = temp;
	}
	tail->next = *head;
	*head = tail;
	return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
		if(k <= 1) {
			return head;
		}
        ListNode* countLength = head;
        int length = 0;
        while(countLength) {
        	countLength = countLength->next;
        	length ++;
        }
        ListNode *curr = head;
        if(length >= k) {
        	head = reverse(&curr, k);
        	length -= k;
        }
        while(length >= k) {
        	ListNode *temp = curr;
        	curr = curr->next;
        	temp->next = reverse(&curr, k);
        	length -= k;
        }
        return head;
    }
    
    int main() {
    	ListNode* head = new ListNode(1);
    	head->next = new ListNode(2);
    	head->next->next = new ListNode(3);
    	head->next->next->next = new ListNode(4);
    	head->next->next->next->next = new ListNode(5);
    	ListNode* result = reverseKGroup(head, 3);
    	while(result) {
    		cout<<result->val<<" ";
    		result = result->next;
    	}
    	cout<<endl;
    	return 0;
    }