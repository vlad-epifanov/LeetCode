

#include "DP.h"
#include <cassert>

using namespace std;

bool DivGame::divisorGame(int N)
{
    if (N%2 == 0)
        return true;
    return false;
}

/* Solution:
   Tracking: SelMin, SelMax, AbsMin, LastMax
   Every step:
            1) check LastMax vs Cur
                -> update if needed
                -> update SelMax if LastMax > SelMax
                -> update SelMin && SelMax if LastMax - AbsMin > SelMax - SelMin
            2) If cur < AbsMin: AbsMin = cur, LastMax = AbsMin - Resetting

 */
int MaxProfit::maxProfit(const vector<int>& prices)
{
    if (prices.size() <= 1) {
        return 0;
    }
    int selMin(prices[0]), selMax(prices[0]), curMin(prices[0]), curMax(prices[0]);
    for (size_t i = 1; i < prices.size(); ++i) {
        int curVal = prices[i];
        if (curVal > curMax) {
            curMax = curVal;
            if (selMax < curMax) {
                selMax = curMax;
            }
            if ((curMax - curMin) > (selMax - selMin)) {
                selMin = curMin;
                selMax = curMax;
            }
        }
        if (curVal < curMin) {
            curMin = curMax = curVal;
        }
    }
    return selMax - selMin;
}
