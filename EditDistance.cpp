#include <iostream>
#include <vector>
#include <string>
using namespace std;
	int minDistance(string word1, string word2) {
		int length1 = word1.size(), length2 = word2.size();
        vector<vector<int> > container(length1+1, vector<int>(length2+1));
        for(int i = 0;i <= length1;i ++){
        	container[i][0] = i;
        }
        for(int i = 0;i <= length2;i ++){
        	container[0][i] = i;
        }
        for(int i = 1;i <= length1;i ++){
        	for(int j = 1;j <= length2;j ++){
        		int cost = 1;
        		if(word1[i-1] == word2[j-1]){
        			cost = 0;
        		}
        		container[i][j] = min(min(container[i-1][j]+1, container[i][j-1]+1), container[i-1][j-1]+cost);
        	}
        }
        return container[length1][length2];
    }

int main(){
	string s1("sea"), s2("eat");
	cout<<minDistance(s1,s2)<<endl;
	return 0;
}