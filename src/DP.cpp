

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

/*********************************************/

void MXBlockSum::makeCumSum(Vec2D& mat)
{
    //Sum Rows
    for (auto& row : mat) {
        for (int c = 1; c < _NCols; ++c) {
            row[c] += row[c-1];
        }
    }
    //Sum Cols
    for (int c = 0; c < _NCols; ++c) {
        for (int r = 1; r < _NRows; ++r) {
            mat[r][c] += mat[r-1][c];
        }
    }
}

int MXBlockSum::getElem(Vec2D& mat, int r, int c)
{
    if (r < 0 || c < 0 )
        return 0;
    r = std::min(r, _NRows-1);
    c = std::min(c, _NCols-1);    
    return mat[r][c];
}

int MXBlockSum::getSubRangeSum(Vec2D& mat, int r, int c, int K)
{
    return getElem(mat,r+K,c+K) + getElem(mat,r-K-1,c-K-1) - getElem(mat,r+K,c-K-1) - getElem(mat,r-K-1,c+K);
}

Vec2D MXBlockSum::matrixBlockSum(Vec2D& mat, int K)
{
    _NRows = mat.size();
    _NCols = mat.front().size();
    // Prepare CumSum matrix from original matrix
    this->makeCumSum(mat);

    Vec2D result(_NRows,Vec(_NCols,0));
    for (int r = 0; r < _NRows; ++r) {
        for (int c = 0; c < _NCols; ++c) {
            result[r][c] = this->getSubRangeSum(mat, r, c, K);
        }
    }    
    return result;
}
