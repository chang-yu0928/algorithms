#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.size() == 0) {
        	return 0;
        }
        int size = prices.size();
        if(k > size / 2) {
        	int result = 0;
        	for(int i = 1;i < size;i ++) {
        	    if(prices[i] > prices[i-1]) {
        		    result += prices[i] - prices[i-1];
        	    }
        	}
        	return result;
        }
        vector<vector<int> > mustSell(size, vector<int> (k+1, 0));
        vector<vector<int> > maxProf(size, vector<int> (k+1, 0));
        
        for(int i = 1;i < size;i ++) {
        	int diff = prices[i] - prices[i-1];
        	for(int j = 1;j <= k;j ++) {
        		mustSell[i][j] = max(mustSell[i-1][j] + diff, maxProf[i-1][j-1] + diff);
        		maxProf[i][j] = max(mustSell[i][j], maxProf[i-1][j]);
        	}
        }
        return maxProf[size-1][k];
    }
    
    
    int main() {
    	vector<int> input(4);
    	input[0]=1;input[1]=7;input[2]=4;input[3]=2;//input[4]=4;input[5]=7;
    	cout<<maxProfit(2, input)<<endl;
    	return 0;
    }