

#pragma once
#include "typedefs.h"

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
1) Running Sum of 1d Array
https://leetcode.com/problems/running-sum-of-1d-array/

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
***************************************/

class EXPORT_SYM RunningSum {
public:
    vector<int> runningSum(const vector<int>& nums);
};

/*
2) Shuffle array
*/

class Shuffle {
public:
    vector<int> shuffle(vector<int>& nums, int n);
};


/*
3) Subrectangle Queries
https://leetcode.com/problems/subrectangle-queries/

Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and supports two methods:

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
2. getValue(int row, int col)

Returns the current value of the coordinate (row,col) from the rectangle.
*/

class SubrectangleQueries {
    vector<vector<int>> m_rectangle;
    size_t m_colN, m_rowN;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle);
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue);
    int getValue(int row, int col);
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

/*
4) Container With Most Water
https://leetcode.com/problems/container-with-most-water/
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.
*/

class MostWater {
public:
    int maxArea(vector<int>& height);
};

/*
5) Transpose matrix
https://leetcode.com/problems/transpose-matrix/
*/

class TransposeMatrix {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A);
};