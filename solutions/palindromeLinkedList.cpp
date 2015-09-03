#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *pre;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if(fast == slow) {
            return true;
        }
        pre->next = NULL;
        pre = slow;
        slow = slow->next;
        while(slow != NULL) {
            ListNode *temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(pre != NULL && head != NULL) {
            if(pre->val != head->val) {
                return false;
            }
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
    
    int main() {
    	ListNode *head = new ListNode(1);
    	head->next = new ListNode(2);
    	head->next->next = new ListNode(3);
    	head->next->next->next = new ListNode(4);
    	head->next->next->next->next = new ListNode(3);
    	head->next->next->next->next->next = new ListNode(2);
    	head->next->next->next->next->next->next = new ListNode(1);
    	cout<<isPalindrome(head)<<endl;
    	return 0;
    }