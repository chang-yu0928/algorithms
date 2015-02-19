#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> length;
    int stringLength;
    
    
    void find(string start, string end, unordered_set<string> &dict, int n, unordered_set<string> &checked) {
        if(start == end){
            length.push_back(n);
            checked.clear();
            return;
        }
        if(checked.find(start) != checked.end()){
            return;
        }
        checked.insert(start);
        for(int i = 0;i < stringLength;i ++){
            string tempResult = start;
            for(char x = 'a';x <= 'z';x ++){
                if(x == start[i]){
                    continue;
                }
                tempResult.replace(i, 1, 1, x);
                if(dict.find(tempResult) != dict.end() && checked.find(tempResult) == checked.end()){
                    cout<<tempResult<<endl;

                    find(tempResult, end, dict, n + 1, checked);
                }
            }
        }
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        stringLength = start.size();
        unordered_set<string> checked;
        find(start, end, dict, 1, checked);
        int min = 0;
        for(int i = 0;i < length.size();i ++){
            if(min == 0){
                min = length[i];
            }
            if(min > length[i]){
                min = length[i];
            }
        }
        return min;
    }
    
int main(){
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dog");
    dict.insert("cog");
    dict.insert("tot");
    dict.insert("hog");
    dict.insert("hop");
    dict.insert("pot");
    dict.insert("dot");    
    cout<<ladderLength(start, end, dict)<<endl;
    return 0;
}