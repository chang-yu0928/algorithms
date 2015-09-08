#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int partition(vector<pair<int, int> > &counts, int start, int end) {
    int less = end, i = start + 1;
    while(i <= less) {
        if(counts[i].first < counts[start].first) {
            swap(counts[i], counts[less]);
            less --;
        } else {
            i ++;
        }
    }
    swap(counts[start], counts[less]);
    return less;
}


int quickSelect(vector<pair<int, int> > &counts, int k, int start, int end) {
    if(start >= end) return end;
    int pos = partition(counts, start, end);
    if(pos > k) {
        return quickSelect(counts, k, start, pos - 1);
    } else if(pos < k) {
        return quickSelect(counts, k - pos, pos + 1, end);
    } else {
        return pos;
    }
}


vector<int> findNum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    vector<pair<int, int> > counts;
    vector<int> result;
    for(int i = 0;i < nums.size();i ++) {
        mp[nums[i]] ++;
    }
    
    for(auto it = mp.begin();it != mp.end();it ++) {
        counts.push_back(make_pair(it->second, it->first));
    }
    int res = quickSelect(counts, k - 1, 0, counts.size() - 1);
    for(int i = 0;i <= res;i ++) {
        result.push_back(counts[i].second);
    }
    return result;
}

int main() {
    int a[] = {1,2,3,4,2,3,4,4,4,3};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    vector<int> res = findNum(nums, 4);
    for(int i = 0;i < res.size();i ++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
