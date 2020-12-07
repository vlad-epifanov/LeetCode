
#include "DFS.h"
/************************************************/
// AllGraphPaths
// n is small - recursive approach is applicable

void AllGraphPaths::findPathFromNode(const int curNode, const Graph& graph)
{
    m_curPath.push_back(curNode);
    if (curNode == m_lastNode) {
        m_graphPaths.push_back(m_curPath);
    } else {
        for (auto&& nextNode: graph[curNode]) {
            this->findPathFromNode(nextNode, graph);
        }
    }
    m_curPath.pop_back();
}

vector<vector<int>> AllGraphPaths::allPathsSourceTarget(Graph& graph)
{
    if (graph.empty()) {
        return {};
    }
    m_lastNode = graph.size() - 1;
    m_curPath.clear();
    m_graphPaths.clear();
    this->findPathFromNode(0, graph);
    return m_graphPaths;
}