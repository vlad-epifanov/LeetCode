#include "UnionFind.h"
#include <unordered_set>

// Used only for quick copy-paste to LeetCode - avoid in production!


/***********************************************************************/
UnionFind::UnionFind(const size_t N) : m_data(N)
{
    for (int i = 0; i < N; i++) {
        m_data[i] = i;
    }
}
void UnionFind::unite(const size_t i, const size_t j)
{
    m_data[find(i)] = find(j);
}
size_t UnionFind::find(const size_t node)
{
    if (m_data[node] == node) {
        return node;
    }
    return m_data[node] = find(m_data[node]); // simple compression
}
size_t UnionFind::countGroups()
{
    unordered_set<size_t> parents;
    for (auto node: m_data) {
        parents.insert(find(node));
    }
    return parents.size();
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
    return static_cast<int>(uf.countGroups());
}

/************************************************/
// Solution: build UnionFind

void SlashRegions::processCell(const size_t i, const size_t j, UnionFind& uf, const char c)
{
    auto upNode = this->getUpperIdx(i,j);
    auto lowNode = this->getLowerIdx(i,j);
    auto leftNode = this->getLeftIdx(i,j);
    auto rightNode = this->getRightIdx(i,j);
    switch (c) {
        case ' ':
            uf.unite(upNode, lowNode);
            uf.unite(leftNode, rightNode);
            uf.unite(leftNode, upNode);
            break;
        case '/':
            uf.unite(upNode, leftNode);
            uf.unite(rightNode, lowNode);
            break;
        case '\\':
            uf.unite(upNode, rightNode);
            uf.unite(leftNode, lowNode);
            break;
    };
}

UnionFind SlashRegions::buildUF(std::vector<std::string>& grid)
{
    const size_t M = grid.size();
    const size_t N = grid.front().length();
    UnionFind uf(M*N*4);
    /*
    Every cell in original grid is represented like this in UF:
    \ 0 /
    1 X 2
    / 3 \
    So we'll build UF by:
    1) Process cell itself
    2) Merge with right cell
    3) Merge with left cell
    */
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            processCell(i,j,uf,grid[i][j]);
            if (i < M-1) {
                uf.unite(getLowerIdx(i,j),getUpperIdx(i+1,j));
            }
            if (j < N-1) {
                uf.unite(getRightIdx(i,j),getLeftIdx(i,j+1));
            }            
        }
    }
    return uf;
}

int SlashRegions::regionsBySlashes(vector<string>& grid)
{
    m_N = grid.front().size();
    auto uf = this->buildUF(grid);
    return static_cast<int>(uf.countGroups());
}