#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int len = prices.size(), profit = 0;
        if(len == 0) return profit;
        vector<int> left(len), right(len);
        left[0] = 0;
        right[len-1] = 0;
        for(int i = 1;i < len;i ++) {
            profit += (prices[i] - prices[i-1]);
            if(profit < 0) profit = 0;
            left[i] = max(left[i-1], profit);
        }
        profit = 0;
        for(int i = len - 2;i >= 0;i --) {
            profit += (prices[i+1] - prices[i]);
            if(profit < 0) profit = 0;
            right[i] = max(right[i+1], profit);
        }
        for(int i = 0;i < len;i ++) {
            profit = max(profit, (left[i] + right[i]));
        }
        return profit;
    }
    
    int main() {
    	//vector<int> prices();
    	//prices
    	vector<int> prices;
    	cout<<maxProfit(prices)<<endl;
    	return 0;
    }