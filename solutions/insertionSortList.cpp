#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
        ListNode *list1 = new ListNode(1), *list2 = new ListNode(2), *tail = list2, *temp;
        list1->next = head;
        while(list1->next) {
        	tail = list2;
            while(tail->next && tail->next->val < list1->next->val) {
                tail = tail->next;
            }
            temp = tail->next;
            tail->next = list1->next;
            list1->next = list1->next->next;
            tail->next->next = temp;
        }
        return list2->next;
    }
    
    int main() {
    	ListNode *list = new ListNode(3);
    	list->next = new ListNode(4);
    	list->next->next = new ListNode(1);
    	ListNode *res = insertionSortList(list);
    	while(res) {
    		cout<<res->val<<" ";
    		res = res->next;
    	}
    	cout<<endl;
    	return 0;
    }