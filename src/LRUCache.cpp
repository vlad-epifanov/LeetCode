#include "LRUCache.h"

LRUCache::LRUCache(int capacity) :
    _capacity(capacity),
    _storage(),
    _queue()
{
}

int LRUCache::get(int key)
{
    if (!_storage.count(key)) {
        return -1;
    }
    auto iter = _storage[key];
    int val = iter->second;
    _queue.erase(iter);
    _queue.push_front({key, val});
    _storage[key] = _queue.begin();
    return val;
}

void LRUCache::put(int key, int value) 
{
    if (_capacity == 0)
        return;
    if (_storage.count(key)) {
        _queue.erase(_storage[key]);
    }
    if (_queue.size() >= _capacity) {
        _storage.erase(_queue.back().first);
        _queue.pop_back();
    }
    _queue.push_front({key, value});
    _storage[key] = _queue.begin();
}
