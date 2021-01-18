#pragma once
#include "typedefs.h"

class UnionFind {
        std::vector<size_t> m_data;
    public:
        UnionFind(const size_t N);
        void unite(const size_t i, const size_t j);
        size_t find(const size_t node);
        size_t countGroups();
};

/*
1. Number of Provinces
https://leetcode.com/problems/number-of-provinces/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

*/

class ProvincesCounter {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected);
};

/*
2.
https://leetcode.com/problems/regions-cut-by-slashes/

*/

class SlashRegions {
public:
    int regionsBySlashes(std::vector<std::string>& grid);
private:
    UnionFind buildUF(std::vector<std::string>& grid);
    inline size_t getLowerIdx(const size_t i, const size_t j) {
        return (i * m_N + j) * 4 + 3;
    }
    inline size_t getUpperIdx(const size_t i, const size_t j) {
        return (i * m_N + j) * 4;
    }
    inline size_t getLeftIdx(const size_t i, const size_t j) {
        return (i * m_N + j) * 4 + 1;
    }
    inline size_t getRightIdx(const size_t i, const size_t j) {
        return (i * m_N + j) * 4 + 2;
    }
    void processCell(const size_t i, const size_t j, UnionFind& uf, const char c);
private:
    size_t m_N = 0;
};