#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> container;
        int length = gas.size();
        for(int i = 0;i < length;i ++){
            container.push_back(gas[i] - cost[i]);
        }
        int maxstart = 0;
        int maxcost = 0;
        for(int i = 0;i < length;i ++){
            if(container[i] > container[maxstart]){
                maxstart = i;
            }
            if(container[i] < container[maxcost]){
                maxcost = i;
            }
        }
        maxcost = (maxcost + 1)%length;
        int start1 = maxstart;
        int start2 = maxcost;
        int m1 = 0;
        int m2 = 0;
        cout<<start1<<endl;
        cout<<start2<<endl;
        for(int i = 0;i < length;i ++){
            m1 += container[start1];
            m2 += container[start2];
            cout<< "m1:"<<m1<<" m2:"<<m2<<endl;
            start1 = (start1 + 1) % length;
            start2 = (start2 + 1) % length;
        }
        if(m1 >= 0){
            return maxstart;
        }
        if(m2 >= 0){
            return maxcost;
        }
        return -1;
    }
    
int main(){
    vector<int> temp1;
    vector<int> temp2;
    temp1.push_back(4);
    temp2.push_back(5);
    cout<<canCompleteCircuit(temp1,temp2)<<endl;
}