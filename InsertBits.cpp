#include <iostream>
#include <bitset>
using namespace std;

int insertBits(int n, int m, int i, int j) {
	int allones = ~0;
	int left = allones << (j + 1);
	int right = ((1 << i) - 1);
	int mask = left | right;
	int n_cleared = n & mask;
	int m_shifted = m << i;
	return n_cleared | m_shifted;
}

int main() {
    int temp1 = 100;
    int temp2 = 28;
    int temp3 = insertBits(temp1, temp2, 8, 12);
    bitset<sizeof(int) * 8> bit_int1(temp1);
    bitset<sizeof(int) * 8> bit_int2(temp2);
    bitset<sizeof(int) * 8> bit_int3(temp3);
    cout<<bit_int1<<endl;
    cout<<bit_int2<<endl;
    cout<<bit_int3<<endl;
    return 0;
}
