#include "Greedy.h"
#include <unordered_map>

using Hash = unordered_map<int, std::vector<int>>;

/*******************************************************************************/
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

/*******************************************************************************/
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

/*******************************************************************************/
vector<int> Partitionlabels::partitionLabels(const string& S)
{
    if (S.empty()) {
        return {0};
    }

    // Find last positions for each letter
    vector<int> last(26,-1);
    for (int i = 0; i < S.length(); ++i) {
        char c = S[i];
        last[c-'a'] = i;
    }

    // Calculate strings and lengths
    vector<int> res;
    int curPos = 0;
    while (curPos < S.length()) {
        char c = S[curPos];
        int lastPos = last[c-'a'];
        int prevPos = curPos;
        while(curPos < lastPos) {
            //be greedy - get as far as possible:
            //if any letter inside the range is met outside the range - extend the range
            curPos++;
            c = S[curPos];
            lastPos = std::max(lastPos, last[c-'a']);
        }
        res.push_back(lastPos-prevPos+1);
        curPos = lastPos+1;
    }
    
    return res;
}

