
#include "DFS.h"
#include <numeric>
#include <algorithm>

/************************************************/
// AllGraphPaths
// n is small - recursive approach is applicable

void AllGraphPaths::findPathFromNode(const int curNode, const Graph& graph, vector<int>& curPath)
{
    curPath.push_back(curNode);
    if (curNode == m_lastNode) {
        m_graphPaths.push_back(curPath);
    } else {
        for (auto&& nextNode: graph[curNode]) {
            this->findPathFromNode(nextNode, graph, curPath);
        }
    }
    curPath.pop_back();
}

vector<vector<int>> AllGraphPaths::allPathsSourceTarget(Graph& graph)
{
    if (graph.empty()) {
        return {};
    }
    m_lastNode = static_cast<int>(graph.size() - 1UL);
    vector<int> curPath;
    m_graphPaths.clear();
    this->findPathFromNode(0, graph, curPath);
    return m_graphPaths;
}

/************************************************/
/* Straghtforward DFS+DP solution:
   1) Iterate through all of the elements. For every element - call DFS to find maximal increasing path
   2) DFS works with caching for every element - we cache that max path, so we can leverage that cache during calculation of other items
   3) Separate O(nm) matrix is used to store those paths
   4) Also we need to track the very maximal path along the way, to return it
   5) O(nm) time, O(nm) space

*/

int LongestIncrPath::getLongestPath(const int prevVal, const int i, const int j, const Vec2D& matrix)
{
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix.front().size() ||  // if index is out of bounds
        prevVal >= matrix[i][j])                                               // or sequence is non-increasing
        return 0;
    if (mpCache_[i][j] < 0) {
        const int curVal = matrix[i][j];
        mpCache_[i][j] = 1 + std::max({this->getLongestPath(curVal, i+1,j,matrix),
                              this->getLongestPath(curVal, i-1,j,matrix),
                              this->getLongestPath(curVal, i,j+1,matrix),
                              this->getLongestPath(curVal, i,j-1,matrix)});
    }
    return mpCache_[i][j];
}

int LongestIncrPath::longestIncreasingPath(Vec2D& matrix)
{
    const int M = static_cast<int>(matrix.size());
    if (M == 0)
        return 0;
    const int N = static_cast<int>(matrix.front().size());

    mpCache_.clear();
    mpCache_.resize(M,Vec(N,-1));

    int maxPath = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            maxPath = std::max(this->getLongestPath(-1,i,j,matrix), maxPath);
        }
    }
    return maxPath;
}

/************************************************/
// RoomsAndKeys
// DFS + visited + counter

void RoomsAndKeys::visit(int room, vector<vector<int>>& rooms)
{
    if (_visited[room])
        return;
    
    _visited[room] = true;
    _counter++;
    for (auto nextRoom : rooms[room]) {
        this->visit(nextRoom, rooms);
    }
}

bool RoomsAndKeys::canVisitAllRooms(vector<vector<int>>& rooms)
{
    _visited.clear();
    _visited.resize(rooms.size(), false);
    _counter = 0;

    this->visit(0, rooms);
    
    return _counter == rooms.size();
}

/************************************************/

int MaxAreaIsland::getIslandArea(const int i, const int j, vector<vector<int>>& grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid.front().size() || !grid[i][j]) {
        return 0;
    }
    grid[i][j] = 0;
    return 1 + getIslandArea(i+1, j, grid) + getIslandArea(i-1, j, grid) + 
               getIslandArea(i, j+1, grid) + getIslandArea(i, j-1, grid);
}

int MaxAreaIsland::maxAreaOfIsland(vector<vector<int>>& grid)
{
    const size_t N = grid.size();
    const size_t M = grid.front().size();
    
    int maxArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                maxArea = std::max(getIslandArea(i,j,grid), maxArea);
            }
        }        
    }

    return maxArea;
}



/************************************************/