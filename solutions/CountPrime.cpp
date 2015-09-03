#include <iostream>
using namespace std;

int countPrimes(int n) {
    bool visit[2000000] = {};
    int p[200000] = {};
    int res = 0;
    for(int i = 3;i < n;i += 2) {
        if(!visit[i]) {
            p[res ++] = i;
        }
        for(int j = 0;j < res && i * p[j] < n;j ++) {
            visit[i*p[j]] = true;
            cout<<i<<" "<<p[j]<<" "<<i * p[j] <<endl;
            if(i % p[j] == 0) {
                break;
            }
        }
    }
    return res + (n > 2 ? 1: 0);
}

int main() {
    int n = 100;
    countPrimes(100);
    return 0;
}

