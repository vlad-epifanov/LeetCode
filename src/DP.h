
#pragma once
#include "typedefs.h"

// Used only for quick copy-paste to LeetCode - avoid in production!


/***************************************
1) Divisor Game
https://leetcode.com/problems/divisor-game/

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
***************************************/

class DivGame {
public:
    bool divisorGame(int N);
};

/***************************************
2) Buying stocks
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
***************************************/

class MaxProfit {
public:
    int maxProfit(const vector<int>& prices);
};

/***************************************
3) Matrix Block Sum
https://leetcode.com/problems/matrix-block-sum/

Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements 
mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 
Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100

*************/
class MXBlockSum {

    int _NRows = 0;
    int _NCols = 0;

    void makeCumSum(Vec2D& mat);
    int getSubRangeSum(Vec2D& mat, int r, int c, int K);
    int getElem(Vec2D& mat, int r, int c);

public:

    Vec2D matrixBlockSum(Vec2D& mat, int K);
};


/***************************************
4)  Counting Bits
https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]
*/

class CountBits {
public:
    vector<int> countBits(int num);
};

/*
5) Count Sorted Vowel Strings
https://leetcode.com/problems/count-sorted-vowel-strings/
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
*/

class CountSortedVowels {
public:
    int countVowelStrings(int n);
};

/*
6) Count Square Submatrices with All Ones
https://leetcode.com/problems/count-square-submatrices-with-all-ones/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

class SquareCounter {
    Vec2D _cache;
    int _M;
    int _N;
    int getCountForCell(const Vec2D& matrix, const int row, const int col);
public:
    int countSquares(Vec2D& matrix);
};

class SquareCounterLoop {
    int getFromCache(const Vec2D& cache, const int row, const int col);
public:
    int countSquares(Vec2D& matrix);
};

class SquareCounterLoop2 {
public:
    int countSquares(Vec2D& matrix);
};

/*
7) Minimum Cost For Tickets
https://leetcode.com/problems/minimum-cost-for-tickets/
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

*/

class MinTicketsCost {
    vector<int> _days;
    vector<int> _costs;
    vector<int> _cache;
    int getMinCost(const int startDayPos);
    int getMinCost(const int startDayPos, const int daysInPass, const int passCost);
public:
    int mincostTickets(vector<int>& days, vector<int>& costs);
};

//Turn it upside down!

/*
8. Partition Array for Maximum Sum
https://leetcode.com/problems/partition-array-for-maximum-sum/

Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k.
 After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
*/

class PartitionMaxSum {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k);
};

/*
9. Palindromic Substrings
https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class PalindromeSubstrings {
public:
    int countSubstrings(const string& s);
};

/*
9. Count Submatrices With All Ones
https://leetcode.com/problems/count-submatrices-with-all-ones/

Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

Example 1:
Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.

*/

class SubmatrixCounter {
public:
    int numSubmat(vector<vector<int>>& mat);
};


/*
32. Longest Valid Parentheses
(Hard)
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
*/
 
class LVP {
public:
    int longestValidParentheses(string& s);
private:
    int getMaxValidSubString(string& s, const size_t pos);
private:    
    int m_curMaxLen;
    vector<int> m_lvpCache;
};