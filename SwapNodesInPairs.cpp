#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *swapPairs(ListNode *head) {
        ListNode *temp = head;
        ListNode *former;
        ListNode *latter;
        ListNode *prev = NULL;
        while(temp != NULL && temp->next != NULL){
            former = temp;
            latter = temp->next;
            temp = temp->next->next;
            latter->next = former;
            former->next = temp;
            if(prev != NULL){
                prev->next = latter;
            }else{
                head = latter;
            }
            prev = former;
        }
        return head;
    }
    
int main(){
    ListNode *temp1 = new ListNode(1);
    ListNode *temp2 = new ListNode(2);
    temp1->next = temp2;
    temp2->next = NULL;
    ListNode *p = swapPairs(temp1);
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}