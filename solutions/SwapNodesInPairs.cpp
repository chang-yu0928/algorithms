#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *first = head, *second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
    
int main(){
    ListNode *temp = new ListNode(1);
    temp->next = new ListNode(2);
    temp->next->next = new ListNode(3);
    //temp->next->next->next = new ListNode(4);
    ListNode *p = swapPairs(temp);
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}