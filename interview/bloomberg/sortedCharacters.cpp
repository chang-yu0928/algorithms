#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Compare {
    bool operator()(const pair<int, char> p1, const pair<int, char> p2) {
        return (p1.first > p2.first);
    }
} compare;

void printSortedChar(string input) {
    vector<pair<int, char> > con(32);
    int index;
    for(int i = 0;i < input.size();i ++) {
        index = input[i] - 'a';
        con[index].first ++;
        con[index].second = input[i];
    }
    sort(con.begin(), con.end(), compare);
    for(int i = 0;i < con.size();i ++) {
        if(con[i].first == 0) break;
        cout<<con[i].second<<" "<<con[i].first<<endl;
    }
}
    
int main() {
    printSortedChar("welcome");
    return 0;
}

