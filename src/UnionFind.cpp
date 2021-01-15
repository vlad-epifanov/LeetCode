#include "UnionFind.h"
#include <unordered_set>

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***********************************************************************/
// Let's use Union-Find with path-compression (no ranking for simplicity)
//
vector<int> ProvincesCounter::buildUF(vector<vector<int>>& isConnected)
{
    const int N = isConnected.size();
    vector<int> uf(N);
    for (int i = 0; i < N; i++) {
        uf[i] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isConnected[i][j]) {
                uf[find(i,uf)] = find(j,uf);
            }
        }
    }
    return uf;
}

int ProvincesCounter::find(const int startNode, vector<int>& uf)
{
    if (uf[startNode] == startNode) {
        return startNode;
    }
    return uf[startNode] = find(uf[startNode], uf); // simple compression
}

int ProvincesCounter::countRegions(vector<int>& uf)
{
    unordered_set<int> parents;
    for (auto node: uf) {
        parents.insert(find(node, uf));
    }
    return parents.size();
}

int ProvincesCounter::findCircleNum(vector<vector<int>>& isConnected)
{
    if (isConnected.empty() || isConnected.front().empty()) {
        return 0;
    }
    vector<int> unionFind = buildUF(isConnected);
    return countRegions(unionFind);
}
