#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len == 0){
            return 0;
        }
        int buy = prices[0];
        int sale = prices[len-1];
        int buyIndex = 0;
        int saleIndex = len-1;
        int profit = 0;
        while(buyIndex < saleIndex){
            for(int i = 0;i < saleIndex;i ++){
                buyIndex ++;
                if(buy >= prices[i]){
                    buy = prices[i];
                    cout<<"buy"<<buy<<endl;
                }else{
                    break;
                }
            }
            cout<<buyIndex<<endl;
            for(int i = saleIndex;i >= buyIndex - 1;i --){
                saleIndex --;
                if(sale <= prices[i]){
                    sale = prices[i];
                    cout<<"sale"<<sale<<endl;
                }else{
                    break;
                }
            }
            if(profit < sale - buy){
                profit = sale - buy;
            }
        }
        return profit;
    }
    
int main(){
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(1);
    temp.push_back(4);
    cout<<maxProfit(temp)<<endl;
    return 0;
}