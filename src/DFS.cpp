
#include "DFS.h"
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