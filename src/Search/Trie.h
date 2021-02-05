/********************************************************************************************
 * Implementation of Trie data structure (Prefix tree)
 ********************************************************************************************/

#pragma once
#include "typedefs.h"
#include <memory>
#include <unordered_map>

/*********************************************************************************************
208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

class Trie {
public:
    Trie();
    
    /** Inserts a word into the trie. */
    void insert(const string& word);
    
    /** Returns if the word is in the trie. */
    bool search(const string& word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix);

private:
    struct Node;
    using NodePtr = shared_ptr<Node>;

    struct Node {
        vector<NodePtr> children;
        char val;
    };

    unordered_map<char,NodePtr> m_rootMap;
};