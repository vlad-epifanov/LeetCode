
#pragma once
#include "typedefs.h"

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

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