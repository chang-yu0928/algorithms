#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int minLevel;
void findLadders(string start, string end, unordered_set<string> &dict, vector<string> &part, vector<vector<string> > &result, int level) {
        vector<string> vec;
        for(int i = 0;i < start.size();i ++) {
            char temp = start[i];
            for(char a = 'a';a <= 'z';a ++) {
                start[i] = a;
                if(dict.count(start)) {
                    dict.erase(start);
                    vec.push_back(start);
                }
            }
            start[i] = temp;
        }
        if(!dict.count(end)) {
            part.push_back(end);
            result.push_back(part);
            part.pop_back();
            minLevel = level;
        }
        if(minLevel == -1 || level < minLevel) {
            for(int i = 0;i < vec.size();i ++) {
                part.push_back(vec[i]);
                findLadders(vec[i], end, dict, part, result, level + 1);
                part.pop_back();
            }
        }
        for(int i = 0;i < vec.size();i ++) {
            dict.insert(vec[i]);
        }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        minLevel = -1;
        vector<string> part;
        vector<vector<string> > result;
        part.push_back(start);
        if(dict.count(start)) dict.erase(start);
        if(!dict.count(end)) dict.insert(end);
        findLadders(start, end, dict, part, result, 0);
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