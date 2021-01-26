
#pragma once
#include "typedefs.h"

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
1)  Single Number II
https://leetcode.com/problems/single-number-ii/
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
*/

class SingleNumber {
public:
    int singleNumber(vector<int>& nums);
};