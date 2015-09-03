#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

	void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *dummy = new ListNode(0), *tail = dummy, *fast = head, *slow = head, *prev = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(fast) prev = prev->next;
        slow = prev->next;
        prev->next = NULL;
        prev = NULL;
        while(slow) {
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        while(prev && head) {
            tail->next = head;
            head = head->next;
            tail->next->next = prev;
            tail = prev;
            prev = prev->next;
        }
        while(head) {
            tail->next = head;
            head = head->next;
        }
        head = dummy->next;
    }    
    
    
int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	reorderList(head);
	while(head != NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}