#include <iostream>
#include <vector>
#include <stack>
using namespace std;
    int minimumTotal(vector<vector<int> >& triangle) {
        int len = triangle.size();
        vector<int> sum(triangle[len - 1]);
        for(int i = len - 2;i >= 0;i --) {
            for(int j = 0;j <= i;j ++) {
                sum[j] = triangle[i][j] + min(sum[j], sum[j+1]);
            }
        }
        return sum[0];
    }

int main(){
    vector<vector<int> > v;
    vector<int> temp1;
    vector<int> temp2;
    vector<int> temp3;
    temp1.push_back(-1);
    temp2.push_back(2);
    temp2.push_back(3);
    temp3.push_back(1);
    temp3.push_back(-1);
    temp3.push_back(-3);
    v.push_back(temp1);
    v.push_back(temp2);
    v.push_back(temp3);
    cout<<v[0][0]<<"\n"<<v[1][0]<<" "<<v[1][1]<<"\n"<<v[2][0]<<" "<<v[2][1]<<" "<<v[2][2]<<endl;
    cout<<minimumTotal(v)<<endl;
    return 0;
}