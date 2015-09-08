#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

    void generate(string start, vector<string> &input, vector<vector<string> > &result, vector<string> &part, unordered_map<string, vector<string> > mp) {
        for(int i = 0;i < input.size();i ++) {
            if(input[i] == start) {
                part.push_back(start);
                reverse(part.begin(), part.end());
                result.push_back(part);
                part.pop_back();
                return;
            }
            part.push_back(input[i]);
            generate(start, mp[input[i]], result, part, mp);
            part.pop_back();
        }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        int level, maxLevel = INT_MAX;
        unordered_map<string, vector<string> > mp;
        queue<pair<string, int> > que;
        vector<vector<string> > result;
        vector<string> part;
        que.push(make_pair(start, 1));
        if(!dict.count(end)) dict.insert(end);
        while(!que.empty()) {
            string currWord = que.front().first;
            level = que.front().second;
            if(level > maxLevel) break;
            que.pop();
            for(int i = 0;i < currWord.size();i ++) {
                string temp = currWord;
                for(char j = 'a';j <= 'z';j ++) {
                    currWord[i] = j;
                    if(dict.count(currWord)) {
                        if(currWord == end) maxLevel = level;
                        mp[currWord].push_back(temp);
                        que.push(make_pair(currWord, level + 1));
                        if(currWord != end) dict.erase(currWord);
                    }
                }
                currWord = temp;
            }
        }
        vector<string> x;
        x.push_back(end);
        generate(start, x, result, part, mp);
        return result;
    }
    
    int main() {
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
    	vector<vector<string> > result = findLadders("hit", "cog", dict);
    	for(int i = 0;i < result.size();i ++) {
    		for(int j = 0;j < result[i].size();j ++) {
    			cout<<result[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	return 0;
    }