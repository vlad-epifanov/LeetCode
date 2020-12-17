#pragma once
#include "typedefs.h"
#include <map>

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/*
1. SkyLine problem
https://leetcode.com/problems/the-skyline-problem/

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

1 <= buildings.length <= 10^4
0 <= lefti < righti <= 2^31 - 1
1 <= heighti <= 2^31 - 1

*/

class SkyLine {
    multimap<int,int> calculateEventQueue(Vec2D& buildings);
public:
    Vec2D getSkyline(Vec2D& buildings);
};