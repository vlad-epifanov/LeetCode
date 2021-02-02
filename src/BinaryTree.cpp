#include "BinaryTree.h"

#include <queue>

using namespace std;

/************************************************************************************************/
// Auxiliary classes and functions for trees

void releaseTree(TreeNode* root)
{
    if (!root)
        return;
    releaseTree(root->left);
    releaseTree(root->right);
    delete root;
}

vector<int> TreeSerializer::serializeTree(TreeNode *root, size_t treeSize)
{
    if (!root || treeSize == 0)
        return {};
    
    m_serializedTree.clear();
    m_serializedTree.resize(treeSize);
    serializeSubTree(root);
    return m_serializedTree;
}

void TreeSerializer::serializeSubTree(TreeNode *root, int startIdx)
{   
    if (startIdx >= m_serializedTree.size())
        return;
    m_serializedTree[0] = root ? root->val : INT_MAX;
    serializeSubTree(root->left, startIdx*2 + 1);
    serializeSubTree(root->right, startIdx*2 + 2);
}

TreeNode* TreeSerializer::deserializeSubTree(const vector<int>& tree, int startIdx)
{
    if (startIdx >= tree.size() || tree[startIdx] == INT_MAX )
        return nullptr;
    TreeNode* node = new TreeNode{tree[startIdx],nullptr,nullptr};
    node->left = deserializeSubTree(tree, startIdx*2 + 1);
    node->right = deserializeSubTree(tree, startIdx*2 + 2);
    return node;
}

TreeNode* TreeSerializer::deserializeTree(const vector<int>& tree)
{
    if (tree.empty())
        return nullptr;
    return deserializeSubTree(tree);
}

/************************************************************************************************/
bool nodesAreEqual(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2 || (root1->val != root2->val))
        return false;
    return true;
}

bool FlipChecker::flipEquivSubtree(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
        return true;

    if (nodesAreEqual(root1->left, root2->left) && nodesAreEqual(root1->right, root2->right)) {
        return flipEquivSubtree(root1->left, root2->left) && flipEquivSubtree(root1->right, root2->right);
    }
    else if (nodesAreEqual(root1->left, root2->right) && nodesAreEqual(root1->right, root2->left)) {
        return flipEquivSubtree(root1->left, root2->right) && flipEquivSubtree(root1->right, root2->left);
    }
    return false;    
}

bool FlipChecker::flipEquiv(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2 || (root1->val != root2->val))
        return false;

    return flipEquivSubtree(root1, root2);
}

/************************************************************************************************/

int MaxLevelSum::maxLevelSum(TreeNode* root)
{
    if (!root)
        return 0;

    int curMax=INT_MIN, maxLevel, curLevel = 0;
    
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    while(!nodeQueue.empty()){
        int curSum = 0, numNodes = nodeQueue.size();
        curLevel++;

        while(numNodes--){
            TreeNode *p = nodeQueue.front();
            curSum += p->val;
            if(p->left)
                nodeQueue.push(p->left);
            if(p->right)
                nodeQueue.push(p->right);
            nodeQueue.pop();
        }
        
        if(curMax < curSum){
            curMax = curSum;
            maxLevel = curLevel;
        }
    }
    
    return maxLevel; 
}
