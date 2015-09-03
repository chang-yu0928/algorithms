#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode *rotateRight(ListNode *head, int k) {
        ListNode *temp1 = head;
        
        //find length of the linked list.
        int length = 0;
        while(temp1 != NULL){
            temp1 = temp1->next;
            length ++;
        }
        
        if(k >= length || length == 0){
            return head;
        }
        //find start point of rotated node.
        int count = 0;
        temp1 = head;
        while(count != length - k - 1){
            temp1 = temp1->next;
            count ++;
        }
        
        //start rotate
        int flag = true; //find the new head;
        ListNode *insect = temp1;
        temp1 = temp1->next;
        insect->next = NULL;

        while(temp1 != NULL){
            ListNode *temp = temp1;
            temp1 = temp1->next;
            if(flag){
                temp->next = head;
                head = temp;
                insect = head;
                flag = false;
            }else{
                temp->next = insect->next;
                insect->next = temp;
                insect = temp;
            }
        }
        return head;
    }
    
int main(){
    ListNode *temp1 = new ListNode(1);
    ListNode *temp2 = new ListNode(2);
    ListNode *temp3 = new ListNode(3);
    ListNode *temp4 = new ListNode(4);
    ListNode *temp5 = new ListNode(5);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = NULL;
    ListNode *p = rotateRight(temp1, 4);
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}