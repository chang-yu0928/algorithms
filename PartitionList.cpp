#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};    

    ListNode *partition(ListNode *head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode *less = NULL;
        ListNode *bigger = NULL;
        ListNode *result = NULL;
        ListNode *biggerHead = NULL;
        ListNode *temp = head;
        cout<<"OK1"<<endl;
        while(temp != NULL){
            cout<<"OK2"<<endl;
            if(temp->val < x){
                if(less == NULL){
                    less = temp;
                    result = less;
                }else{
                    less->next = temp;
                    less = less->next;
                }
            }else{
                cout<<"OK~~"<<endl;
                if(bigger == NULL){
                    bigger = temp;
                    biggerHead = bigger;
                }else{
                    bigger->next = temp;
                    bigger = bigger->next;
                }
            }
            temp = temp->next;
        }
        cout<<"OK"<<endl;
        if(bigger != NULL){
            bigger->next = NULL;
        }
        if(less != NULL){
            less->next = biggerHead;
        }else{
            result = biggerHead;
        }
        return result;
    }
    
int main(){
    ListNode *x1 = new ListNode(1);
    ListNode *x2 = new ListNode(1);
    x1->next = x2;
    if(partition(x1,0) == NULL){
        cout<<"fuck"<<endl;
    }else{
        cout<<partition(x1,0)->val<<endl;
    }
    return 0;
}