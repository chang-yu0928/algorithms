#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, len = gas.size(), require = 0, tank = 0;
        for(int i = 0;i < len;i ++) {
            if(tank < 0) {
                require += tank;
                tank = 0;
                start = i;
            }
            tank += gas[i];
            tank -= cost[i];
        }
        if(tank + require >= 0) {
            return start;
        }
        return -1;
    }
    
int main(){
    vector<int> temp1(4);
    vector<int> temp2(4);
    temp1[0]=99;temp1[1]=98;temp1[2]=97;temp1[3]=100;
    temp2[0]=100;temp2[1]=100;temp2[2]=100;temp2[3]=97;
    //temp1[0]=1;temp1[1]=2;temp1[2]=3;temp1[3]=4;temp1[4]=5;
    //temp2[0]=3;temp2[1]=4;temp2[2]=5;temp2[3]=1;temp2[4]=2;
    cout<<canCompleteCircuit(temp1,temp2)<<endl;
}