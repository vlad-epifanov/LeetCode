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

/***********************************************************************************/
// Leverage cache containing maxSum for [0;i] subbarays
// Every iteration - pick max sum, from (cache[i-1] + arr[i]) to (cache[i-k] + max(arr[i],...arr[i-k+1]))
// O(n*k)

int PartitionMaxSum::maxSumAfterPartitioning(vector<int>& arr, int k)
{
    //indexation for cache is shifted to the right, for convenience of out-of-bounds checking
    vector<int> maxCache(arr.size()+1,0);
    for (int i = 0; i < arr.size(); ++i) {
        int curMaxVal = arr[i];
        maxCache[i+1] = curMaxVal;
        for (int j = i; j >= std::max(i-k+1,0); --j) {
            int subSeqSize = i-j+1;
            curMaxVal = std::max(curMaxVal, arr[j]);
            maxCache[i+1] = std::max(maxCache[i+1], maxCache[j] + curMaxVal*subSeqSize);
        }
    }
    return maxCache.back();
}

/*************************************************************************************/
// Solution: DP-based, caching palindromes for quick calculation new palindromes.
int PalindromeSubstrings::countSubstrings(const string& s)
{
    int strLen = static_cast<int>(s.size());
    vector<vector<bool>> pCache(strLen,vector<bool>(strLen,false));

    int psCounter = strLen;
    for (int i = strLen-2; i >= 0; --i) {
        for (int j = i+1; j < strLen; ++j) {
            const bool isPalindrome = 
                (s[i] == s[j]) &&       // symbols at the ends should be the same
                 (j <= i+2 ||           // no need to check anything else for 2- and 3- chars substrings
                  pCache[i+1][j-1]);    // ... and inner substring should be palindrome as well
            pCache[i][j] = isPalindrome;
            psCounter += isPalindrome ? 1 : 0;
        }
    }
    
    return psCounter;
}

/********************************************************************************/
// Solution:
// DP - histograms for every line. So we can use minimal height to detect rectangles
// We'll be "dragging" the min-height row, adding height to number - since there will be "height" new rectangle every time
// O(m) space, O(n*m^2) time
int SubmatrixCounter::numSubmat(vector<vector<int>>& mat)
{
    const size_t N = mat.size(); // rows
    const size_t M = mat.back().size(); // columns
    
    // Process row-by row - results for every row depend ONLY on results in the previous row
    vector<int> heights(M, 0);
    int totalCount = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            //update heights: if current cell is 0 - height is zero, otherwise - increase by one
            heights[j] = mat[i][j] * (heights[j] + mat[i][j]);
        }
        //count rectangles
        for (size_t j = 0; j < M; j++) {
            int minHeight = heights[j];
            //if current pos has non-zero height - start tracking'n'counting
            for (size_t k = j; k < M && heights[k]; k++) {
                minHeight = std::min(minHeight,heights[k]);
                totalCount += minHeight;
            }
        }
    }
    return totalCount;
}

/********************************************************************************/
/* Solution:
   - Iterate through the string
   - At the every step - check whether we can build a valid string like this:
    ( + <Valid Substring> + )
    () + <Valid Substring>
    This way we can leverage recursion / DP
*/

int LVP::getMaxValidSubString(string& s, const size_t pos)
{
    if (pos >= s.length()-1 ||  s[pos] == ')')
        return 0;

    if (m_lvpCache[pos] >= 0)
        return m_lvpCache[pos];

    int inLength = getMaxValidSubString(s, pos+1);
    m_lvpCache[pos+1] = inLength;

    if (pos + inLength + 1 >= s.length())
        return 0;

    if (s[pos + inLength + 1] != ')')
        return 0;
    
    int nextLength = 0;
    size_t nextPos = pos + inLength + 2;
    if (nextPos < s.length()) {
        nextLength = getMaxValidSubString(s, nextPos);
        m_lvpCache[nextPos] = nextLength;
    }

    int totalLength = 2 + inLength + nextLength;
    m_lvpCache[pos] = totalLength;
    return totalLength;
}

int LVP::longestValidParentheses(string& s)
{
    if (s.empty())
        return 0;
    m_curMaxLen = 0;
    m_lvpCache.clear();
    m_lvpCache.resize(s.size(),-1);

    for (size_t i = 0; i < s.size(); i++) {
        int len = getMaxValidSubString(s,i);
        m_curMaxLen = std::max(m_curMaxLen, len);
        i += len;
    }

    return m_curMaxLen;
}

/* Another version of LVP: just stack *eating* up valid strings and tracking max length during eating up*/
/*
int longestValidParentheses(string s) {
	int maxi=0;
	stack<int> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
			st.push(i);
		else
		{
			if(!st.empty()&&s[st.top()]=='(')
			{
				st.pop();
				if(st.empty())
					maxi=max(maxi,i+1);
				else
					maxi=max(maxi,i-st.top());
			}
			else
				st.push(i);
		}
	}
	return maxi;
}
*/