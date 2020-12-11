
#pragma once
#include "typedefs.h"

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
1) Split a String in Balanced Strings
https://leetcode.com/problems/split-a-string-in-balanced-strings/
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
*/

class SplitBalancedString {
public:
    int balancedStringSplit(const string& s);
};

/***************************************
2) Group the People Given the Group Size They Belong To
https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.
Return a list of groups such that each person i is in a group of size groupSizes[i].
Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.

Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation: 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
*/

class PeopleGrouper {
public:
    vector<vector<int>> groupThePeople(const vector<int>& groupSizes);
};

/***************************************
3) Partition Labels
A string S of lowercase English letters is given.
We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
https://leetcode.com/problems/partition-labels/

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/

class Partitionlabels {
public:
    vector<int> partitionLabels(const string& S);
};

/***************************************
4) Find Valid Matrix Given Row and Column Sums
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements 
in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. 
In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.
Return a 2D array representing any matrix that fulfills the requirements. 
It's guaranteed that at least one matrix that fulfills the requirements exists.

Example 1:

Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
*/

class ValidMatrix {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum);
};

/***************************************
4) Minimum Add to Make Parentheses Valid
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example:
Input: "())"
Output: 1

*/

class MakeValidParString {
public:
    int minAddToMakeValid(const string& S);
};

/***************************************
5) Car Pooling
https://leetcode.com/problems/car-pooling/

You are driving a vehicle that has capacity empty seats initially available for passengers.
The vehicle only drives east (ie. it cannot turn around and drive west.)
Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains
information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.
The locations are given as the number of kilometers due east from your vehicle's initial location.
Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Example 1:
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
*/

class CarPool {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity);
};