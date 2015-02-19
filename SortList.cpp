#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    ListNode *partition(ListNode *head, ListNode *tail){
        ListNode *temp = head->next;
        ListNode *end;
        if(tail == NULL){
            end = NULL;
        }else{
            end = tail->next;
        }
        cout<<"partition0:"<<head->val<<endl;
        ListNode *tempHead, *tempTailHead, *tempTail;
        int flag1 = 0,flag2 = 0;
        while(temp != tail){
            if(temp->val < head->val){
                if(flag1 == 0){
                    tempHead = temp;
                    flag1 = 1;
                }else{
                    tempHead->next = temp;
                    tempHead = temp;
                }
            }else{
                if(flag2 == 0){
                    tempTailHead = temp;
                    tempTail = temp;
                    flag2 = 1;
                }else{
                    tempTail->next = temp;
                    tempTail = temp;
                }
            }
            temp = temp->next;
            cout<<"partition:"<<temp->val<<endl;
        }
        tempTail->next = end;
        tempHead->next = head;
        head->next = tempTailHead;
        return head;
    }
    ListNode *quickSort(ListNode *head, ListNode *tail){
        if(head == NULL || head == tail){
            return head;
        }
        if(head->next == tail){
            if(head->val > tail->val){
                ListNode *temp = head;
                head = tail;
                head->next = 
            }
        }
        ListNode *pin = partition(head, tail);
        quickSort(head, pin);
        pin = pin->next;
        quickSort(pin, tail);
        return pin;
    }
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *newHead = head, *temp = head;
        while(temp != NULL){
            if(temp->val < newHead->val){
                newHead = temp;
            }
            temp = temp->next;
        }
        quickSort(head, NULL);
        return newHead;
    }
     
    
    

int main(){
    ListNode *head = new ListNode(2);
    ListNode *temp = new ListNode(1);
    head->next = temp;
    cout<<sortList(head)->val<<endl;
    return 0;
}