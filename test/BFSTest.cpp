#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Search/BFS.h"

#include <memory>

TEST(DFS, levelOrderTest)
{
    LevelOrder lo;

    vector<Node*> ev;
    vector<shared_ptr<Node>> nodes = {std::make_shared<Node>(1,ev), std::make_shared<Node>(2,ev),
                                      std::make_shared<Node>(3,ev), std::make_shared<Node>(4,ev),
                                      std::make_shared<Node>(5,ev), std::make_shared<Node>(6,ev)};
    
    Node* root = nodes[0].get();
    root->children = {nodes[1].get(), nodes[2].get()};
    nodes[1]->children = {nodes[3].get(), nodes[4].get()};
    nodes[2]->children = {nodes[5].get()};

    EXPECT_EQ(lo.levelOrder(root),Vec2D({{1},{2,3},{4,5,6}}));
}