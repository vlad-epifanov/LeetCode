#pragma once
#include "typedefs.h"
#include <map>

#include <unordered_map>
#include <list>

/*
1. LRU Cache
https://leetcode.com/problems/lru-cache/

*/

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
};