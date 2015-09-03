#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *fast = head, *slow = dummy;
        dummy->next = head;
        for(int i = 0;i < n;i ++) {
            fast = fast->next;
        }
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
    
    int main() {
    	ListNode *head = new ListNode(1);
    	head->next = new ListNode(2);
    	head->next->next = new ListNode(3);
    	head->next->next->next = new ListNode(4);
    	head->next->next->next->next = new ListNode(5);
    	
    	ListNode *newHead = removeNthFromEnd(head, 5);
    	while(newHead) {
    		cout<<newHead->val<<" ";
    		newHead = newHead->next;
    	}
    	cout<<endl;
    	return 0;
    }