#include "Greedy.h"
#include <unordered_map>
#include <map>
#include <algorithm>

using Hash = unordered_map<int, std::vector<int>>;

/*******************************************************************************/
int SplitBalancedString::balancedStringSplit(const string& s)
{
    if (s.size() <= 1) {
        return 0;
    }
    // Approach: greedy algorithm, just find first balanced string
    // Approach - similar to counting braces.
    int counter = 0;
    int balance = 0;
    for (char c: s) {
        if (c == 'R') {
            balance++;
        } else {
            balance--;
        }
        if (balance == 0) {
            counter++;
        }
    }
    return counter;
}

/*******************************************************************************/
vector<vector<int>> PeopleGrouper::groupThePeople(const vector<int>& groupSizes)
{
    vector<vector<int>> groups;
    Hash groupHash;
    for (int id = 0; id < groupSizes.size(); ++id) {
        auto& group = groupHash[groupSizes[id]];
        group.push_back(id);
        if (group.size() == groupSizes[id]) {
            groups.push_back({});
            groups.back().swap(group);
        }
    }
    return groups;
}

/*******************************************************************************/
vector<int> Partitionlabels::partitionLabels(const string& S)
{
    if (S.empty()) {
        return {0};
    }

    // Find last positions for each letter
    vector<int> last(26,-1);
    for (int i = 0; i < S.length(); ++i) {
        char c = S[i];
        last[c-'a'] = i;
    }

    // Calculate strings and lengths
    vector<int> res;
    int curPos = 0;
    while (curPos < S.length()) {
        char c = S[curPos];
        int lastPos = last[c-'a'];
        int prevPos = curPos;
        while(curPos < lastPos) {
            //be greedy - get as far as possible:
            //if any letter inside the range is met outside the range - extend the range
            curPos++;
            c = S[curPos];
            lastPos = std::max(lastPos, last[c-'a']);
        }
        res.push_back(lastPos-prevPos+1);
        curPos = lastPos+1;
    }
    
    return res;
}

/******************************************************************************/
Vec2D ValidMatrix::restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
{
    //2d result matrix, RowxCol
    size_t numCol = colSum.size(), numRow = rowSum.size();
    Vec2D result(numRow, vector<int>(numCol,0));

    // from top-left to bottom-right, take smallest candidate at every step
    int curRow = 0, curCol = 0;
    while (curRow < numRow && curCol < numCol) {
        if (rowSum[curRow] < colSum[curCol]) {
            result[curRow][curCol] = rowSum[curRow];
            colSum[curCol] -= rowSum[curRow];
            curRow++;
        } else {
            result[curRow][curCol] = colSum[curCol];
            rowSum[curRow] -= colSum[curCol];
            curCol++;
        }
    }

    return result;
}

/*
Alternate solution with for loop (n^n iterations instead of 2n, but less branching):
    for(int i=0;i<r.size();i++) {
        for(int j=0;j<c.size();j++) {
            int m=min(r[i],c[j]);
            dp[i][j]=m;
            r[i]-=m;
            c[j]-=m;
        }
    }
    return dp;
*/

/******************************************************************************/
int MakeValidParString::minAddToMakeValid(const string& S)
{
    //Approach:
    //1) Open - balance +1, close - balance -1. If go negative - count and go back to 0
    //2) In the end - add balance to negative counter
    int balance = 0, negCounter = 0;
    for (auto c : S) {
        balance += (c == '(') ? 1 : -1;
        if (balance < 0) {
            negCounter++;
            balance = 0;
        }
    }
    return balance + negCounter;
}

/**********************************************************************/
// Assumption: input is always correct
bool CarPool::carPooling(vector<vector<int>>& trips, int capacity)
{
    //Approach: ordered map, where we cache load/unload stops
    // map kilometer to passengers balance
    // + - passengers come in
    // - - passengers come out
    map<int,int> stops;
    for (auto& trip: trips) {
        stops[trip[1]] += trip[0];
        stops[trip[2]] -= trip[0];
    }
    int curLoad = 0;
    for (auto& [stop, passBalance] : stops) {
        curLoad += passBalance;
        if (curLoad > capacity) {
            return false;
        }
    }
    return true;
}

/**********************************************************************/
//Assumption - strings have the same size, all the symbols - lower-case latins
// O(2n*logn) + O(n)
bool StringBreaker::checkIfCanBreak(string& s1, string& s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    int champ = 0; // 0 - no champ, 1 - s1, 2 - s2
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) {
            if (champ == 2)
                return false;
            champ = 1;
        } else if (s1[i] < s2[i]) {
            if (champ == 1)
                return false;
            champ = 2;
        }
    }
    return true;
}

/*
Simpler code: count cases when s1 >= s2 and s2 >= s1 -
and to break that number should be equal to L .
int l = s1.length();
int x = 0, y = 0;
for(int i = 0; i < l; i++) {
    if(s1[i] >= s2[i]) x++;
    if(s1[i] <= s2[i]) y++;
}
if(x == l || y == l)
    return true;
return false;

*/

/**********************************************************************/