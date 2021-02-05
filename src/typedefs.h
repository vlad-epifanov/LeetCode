#pragma once

#include <string>
#include <vector>
#include <iostream>

#define EXPORT_SYM __declspec(dllexport)

#define LEETCODE_MODE

// Used only for quick copy-paste to LeetCode - avoid in production!
#ifdef LEETCODE_MODE
    using namespace std;
#endif

using Graph = std::vector<std::vector<int>>;
using Vec2D = std::vector<std::vector<int>>;
using Vec = std::vector<int>;