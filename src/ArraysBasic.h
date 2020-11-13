

#pragma once
#include <string>
#include <vector>

#define EXPORT_SYM __declspec(dllexport)

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
Running Sum of 1d Array
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