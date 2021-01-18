#include "UnionFind.h"
#include <unordered_set>

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***********************************************************************/
UnionFind::UnionFind(const size_t N) : m_data(N)
{
    for (int i = 0; i < N; i++) {
        m_data[i] = i;
    }
}
void UnionFind::unite(const int i, const int j)
{
    m_data[find(i)] = find(j);
}
int UnionFind::find(const int node)
{
    if (m_data[node] == node) {
        return node;
    }
    return m_data[node] = find(m_data[node]); // simple compression
}
int UnionFind::countGroups()
{
    unordered_set<int> parents;
    for (auto node: m_data) {
        parents.insert(find(node));
    }
    return static_cast<int>(parents.size());
}

/***********************************************************************/
// Let's use Union-Find with path-compression (no ranking for simplicity)
//
int ProvincesCounter::findCircleNum(vector<vector<int>>& isConnected)
{
    if (isConnected.empty() || isConnected.front().empty()) {
        return 0;
    }
    const size_t N = isConnected.size();
    UnionFind uf(N);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (isConnected[i][j]) {
                uf.unite(i,j);    
            }
        }
    }    
    return uf.countGroups();
}

/************************************************/
// Solution: build UnionFind

UnionFind SlashRegions::buildUF(std::vector<std::string>& grid)
{
    const size_t M = grid.size();
    const size_t N = grid.front().size();
    UnionFind uf(M*N*4);
    return uf;
}

int SlashRegions::regionsBySlashes(vector<string>& grid)
{
    auto uf = this->buildUF(grid);
    return uf.countGroups();
}