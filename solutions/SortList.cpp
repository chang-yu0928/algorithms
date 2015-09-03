#include <iostream>
using namespace std;

struct ListNode {
    int val; 
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode* combine(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0), *tail = dummy;
        while(list1 && list2) {
            if(list1->val > list2->val) {
                tail->next = list2;
                list2 = list2->next;
            } else {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        while(list1) {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }
        while(list2) {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head, *slow = head, *prev, *list1, *list2;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        list1 = sortList(head);
        list2 = sortList(slow);
        return combine(list1, list2);
    }
    


int main(){
	ListNode *node = new ListNode(2);
	node->next = new ListNode(1);
	ListNode *result = sortList(node);
	while(result){
		cout<<result->val<<" ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}