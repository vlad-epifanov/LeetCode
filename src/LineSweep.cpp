#include "LineSweep.h"

#include <map>
#include <set>
#include <iostream>

/*
Suggested solution:
1) Use pre-populated Events Queue for Adding/Removing buildings
    - values are high, but number of buildings is small!
2) Process events one by one from Events Queue, picking the maximum leftover height
    Via using a Heap to keep current Max
3) We should make final decision after handling all the Events for particular Pos

Alternate solution:
 - use vector<pair<int,int>> instead of multimap and sort it - the same O(nlogn)
 but will be more memory-efficient/cache-friendly
*/

multimap<int,int> SkyLine::calculateEventQueue(Vec2D& buildings)
{
    multimap<int,int> evtQueue;
    for (auto& building: buildings) {
        evtQueue.insert({building[0], building[2]});
        evtQueue.insert({building[1], -building[2]});
    }
    return evtQueue;
}

Vec2D SkyLine::getSkyline(Vec2D& buildings)
{
    // O(nlogn) to build the evt Q
    multimap<int, int> evtQueue = this->calculateEventQueue(buildings);
    multiset<int> curHeights;
    curHeights.insert(0);

    Vec2D skyline;
    int lastPos = 0, lastHeight = 0;
    for (auto &[curPos, cmd] : evtQueue) {
        int curHeight = *curHeights.rbegin();
        // If position and height have changed - we're ready to submit result to skyline
        if (curPos > lastPos && lastHeight != curHeight) {
            skyline.push_back({lastPos, curHeight});
            lastHeight = curHeight;
        }
        if (cmd < 0) {
            curHeights.erase(curHeights.find(abs(cmd)));
        } else {
            curHeights.insert(cmd);
        }
        lastPos = curPos;
    }
    // Add zero in the end
    skyline.push_back({lastPos, 0});

    return skyline;
}
