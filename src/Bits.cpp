#include "Bits.h"

using namespace std;

int SingleNumber::singleNumber(vector<int>& nums)
{
    //Bits counting, O(n) / O(1)
    vector<int> counter(32,0);

    for (auto n: nums) {
        for ( int i = 0; i < 32; i++) {
            counter[i] += (n >> i) & 1;
        }
    }

    int result = 0;
    for (int i = 0; i < 32; i++) {
        char bitVal = counter[i] > 0 && counter[i] % 3 != 0 ? 1 : 0;
        result += bitVal << i;
    }

    return result;
}
