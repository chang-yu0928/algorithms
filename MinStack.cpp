#include <iostream>
using namespace std;
class MinStack {
    int *head;
    int *pointer;
public:
    MinStack(){
        head = NULL;
        pointer = NULL;
    }
    void push(int x) {
        if(head == NULL){
//            head = new int;
//            pointer = new int;
            head = &x;
            pointer = &x;
        }else{
            pointer += 4;
            *pointer = x;
        }
    }

    void pop() {
        int *temp = head;
        head += 4;
        delete temp;
    }

    int top() {
        return *head;
    }

    int getMin() {
        int *temp = head;
        int min = *head;
        while(temp != pointer){
            if(min > *temp){
                min = *temp;
            }
            temp += 4;
        }
        return min;
    }
};
int main(){
    MinStack temp;
    temp.push(-3);
    cout << temp.getMin() << endl;
}   
