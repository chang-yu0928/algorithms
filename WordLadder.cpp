#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
vector<int> length;
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int level;
        queue<pair<string, int> > que;
        que.push(make_pair(beginWord, 1));
        if(!wordDict.count(endWord)) wordDict.insert(endWord);
        while(!que.empty()) {
            string currWord = que.front().first;
            level = que.front().second;
            que.pop();
            for(int i = 0;i < currWord.size();i ++) {
                char temp = currWord[i];
                for(char j = 'a';j <= 'z';j ++) {
                    currWord[i] = j;
                    if(wordDict.count(currWord)) {
                        que.push(make_pair(currWord, level + 1));
                        wordDict.erase(currWord);
                    }
                }
                currWord[i] = temp;
            }
            if(!wordDict.count(endWord)) return (level + 1);
        }
        return 0;
    }
    
int main(){
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dog");
    dict.insert("log");
    //dict.insert("cog");
    //dict.insert("tot");
    dict.insert("lot");
    //dict.insert("hog");
    //dict.insert("hop");
    //dict.insert("pot");
    dict.insert("dot");    
    cout<<ladderLength(start, end, dict)<<endl;
    return 0;
}