#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    bool isPalindrome(ListNode* head) {
        ListNode *p = head, *q = head;
        int len = 0;
        while(p) {
            len ++;
            p = p->next;
        }
        p = NULL;
        q = head;
        for(int i = 0;i < len / 2;i ++) {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        if(len % 2) {
            q = q->next;
        }
        while(p != NULL && q != NULL) {
            if(p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
    
    
int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(1);
    cout<<isPalindrome(head)<<endl;
    return 0;
}