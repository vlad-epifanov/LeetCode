

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
 */
int MaxProfit::maxProfit(const vector<int>& prices)
{
    if (prices.size() <= 1) {
        return 0;
    }
    int maxProfit = 0;
    int curMin(prices[0]);
    for (size_t i = 1; i < prices.size(); ++i) {
        int curVal = prices[i];
        if (curVal < curMin) {
            curMin = curVal;
        } else {
            maxProfit = std::max(maxProfit, curVal - curMin);
        }

    }
    return maxProfit;
}
