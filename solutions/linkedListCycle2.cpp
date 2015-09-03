#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!(fast && fast->next)) return NULL;
        fast = head;
        while(slow && fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    
    int main() {
    	ListNode *head = new ListNode(0);
    	head->next = new ListNode(1);
    	head->next->next = head;
    	
    	ListNode *curr = detectCycle(head);
    	cout<<curr->val<<endl;
    	return 0;
    }