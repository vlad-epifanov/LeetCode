
#include "DFS.h"
/************************************************/
// AllGraphPaths
// n is small - recursive approach is applicable

void AllGraphPaths::findPathFromNode(const int curNode)
{

}

vector<vector<int>> AllGraphPaths::allPathsSourceTarget(Graph& graph)
{
    m_curPath.clear();
    m_graphPaths.clear();
    this->findPathFromNode(0);
    return m_graphPaths;
}