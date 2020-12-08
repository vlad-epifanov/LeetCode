#include "Greedy.h"
#include <unordered_map>

using Hash = unordered_map<int, std::vector<int>>;

int SplitBalancedString::balancedStringSplit(const string& s)
{
    if (s.size() <= 1) {
        return 0;
    }
    // Approach: greedy algorithm, just find first balanced string
    // Approach - similar to counting braces.
    int counter = 0;
    int balance = 0;
    for (char c: s) {
        if (c == 'R') {
            balance++;
        } else {
            balance--;
        }
        if (balance == 0) {
            counter++;
        }
    }
    return counter;
}

vector<vector<int>> PeopleGrouper::groupThePeople(const vector<int>& groupSizes)
{
    vector<vector<int>> groups;
    Hash groupHash;
    for (int id = 0; id < groupSizes.size(); ++id) {
        auto& group = groupHash[groupSizes[id]];
        group.push_back(id);
        if (group.size() == groupSizes[id]) {
            groups.push_back({});
            groups.back().swap(group);
        }
    }
    return groups;
}
