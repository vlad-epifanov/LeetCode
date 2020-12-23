#include "DP.h"
#include <cassert>
#include <numeric>
#include <algorithm>

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
    _NRows = static_cast<int>(mat.size());
    _NCols = static_cast<int>(mat.front().size());
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

vector<int> CountBits::countBits(int num)
{
    vector<int> res(num+1,0);
    if (num == 0) {
        return res;
    }
    // Approach: running "back-offset", increasing every time by 2 when we reach it pos
    // And take value from "-offset+1"
    int offset = 1;
    for (int i = 1; i <= num; ++i) {
        if (i == offset*2) {
            offset = i;
        }
        res[i] = res[i-offset] + 1;
    }

    return res;
}

int CountSortedVowels::countVowelStrings(int n) 
{
    if (n == 0) {
        return 0;
    }

    int totalCount = 5;
    vector<int> curIterCounters(5,0), prevIterCounters(5,1);
    for (int i = 1; i < n; i++) {
        curIterCounters[0] = totalCount;
        curIterCounters[1] = curIterCounters[0] - prevIterCounters[0];
        curIterCounters[2] = curIterCounters[1] - prevIterCounters[1];
        curIterCounters[3] = curIterCounters[2] - prevIterCounters[2];
        curIterCounters[4] = prevIterCounters[4];
        totalCount = std::accumulate(curIterCounters.begin(), curIterCounters.end(), 0);
        prevIterCounters.swap(curIterCounters);
    }
    return totalCount;
}

/***********************************************************************************************/
/* Approach - calculate auxiliary matrix where i,i shows how many square matrices starts from this cell */
//V1 - recursive:

int SquareCounter::getCountForCell(const Vec2D& matrix, const int row, const int col)
{
    if (row >= _M || col >= _N || matrix[row][col] == 0)
        return 0;
    auto& cachedVal = _cache[row][col];
    if (cachedVal == 0) {
        cachedVal = 1 + std::min({getCountForCell(matrix, row+1, col), 
                        getCountForCell(matrix, row+1, col+1),
                        getCountForCell(matrix, row, col+1)});
    }
    return cachedVal;
}

int SquareCounter::countSquares(Vec2D& matrix)
{
    _M = static_cast<int>(matrix.size());
    _N = static_cast<int>(matrix.front().size());
    _cache.clear();
    _cache.resize(_M, vector<int>(_N, 0));

    int totalCount = 0;
    for (int i = 0; i < _M; ++i) {
        for (int j = 0; j < _N; ++j) {
            totalCount += getCountForCell(matrix, i, j);
        }
    }

    return totalCount;
}

/* Bottom-up approach via loop */

int SquareCounterLoop::getFromCache(const Vec2D& cache, const int row, const int col)
{
    if (row >= cache.size() || col >= cache.front().size() || cache[row][col] == 0)
        return 0;
    return cache[row][col];
}
int SquareCounterLoop::countSquares(Vec2D& matrix)
{
    const int M = static_cast<int>(matrix.size());
    const int N = static_cast<int>(matrix.front().size());
    Vec2D cache(M, vector<int>(N, 0));
    
    int totalCount = 0;
    for (int r = M-1; r >= 0; --r) {
        for (int c = N-1; c >= 0; --c) {
            if (matrix[r][c] == 0)
                continue;
            cache[r][c] = 1 + std::min({getFromCache(cache, r,c+1),
                                        getFromCache(cache, r+1,c+1),
                                        getFromCache(cache, r+1,c),});
            totalCount += cache[r][c];
        }
    }

    return totalCount;
}

/* Turned Bottom-up */

int SquareCounterLoop2::countSquares(Vec2D& matrix)
{
    const int M = static_cast<int>(matrix.size());
    const int N = static_cast<int>(matrix.front().size());
    int totalCount = 0;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (r>0 && c>0 && matrix[r][c]>0) {
                matrix[r][c] = 1 + std::min({matrix[r-1][c], matrix[r-1][c-1], matrix[r][c-1]});
            }
            totalCount += matrix[r][c];
        }
    }
    return totalCount;
}

/***********************************************************************************/

int MinTicketsCost::getMinCost(const int startDayPos)
{
    if (_cache[startDayPos] == 0) {
        _cache[startDayPos] = std::min({getMinCost(startDayPos, 1, _costs[0]),
                     getMinCost(startDayPos, 7, _costs[1]),
                     getMinCost(startDayPos, 30, _costs[2])});
    }
    return _cache[startDayPos];
}

int MinTicketsCost::getMinCost(const int startDayPos, const int daysInPass, const int passCost)
{
    int startDay = _days[startDayPos];
    int afterPassDay = startDay + daysInPass;
    if (afterPassDay > _days.back())
        return passCost;

    int nextDayPos = startDayPos;
    while (_days[nextDayPos] < afterPassDay) {
        nextDayPos++;
    }

    return passCost + getMinCost(nextDayPos);
}

int MinTicketsCost::mincostTickets(vector<int>& days, vector<int>& costs) 
{
    if(days.empty())
        return 0;
    _days.swap(days);
    _costs.swap(costs);
    _cache.clear();
    _cache.resize(_days.size(), 0);
    return getMinCost(0);
}
