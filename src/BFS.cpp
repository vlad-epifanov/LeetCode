
#include "BFS.h"

/************************************************/

vector<vector<int>> LevelOrder::levelOrder(Node* root) {
    if (root == nullptr)
        return vector<vector<int>>();
    
    queue<pair<Node*,int>> nodeQueue;
    nodeQueue.push({root,0});
    vector<vector<int>> result;
    
    while (!nodeQueue.empty()) {
        auto [node, level] = nodeQueue.front();
        if (result.size() <= level ) {
            result.push_back({node->val});
        } else {
            result[level].push_back(node->val);
        }
        nodeQueue.pop();
        for (auto child: node->children)
            nodeQueue.push({child,level+1});
    }
    
    return result;
}

/************************************************/