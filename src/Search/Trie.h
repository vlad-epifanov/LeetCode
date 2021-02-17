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

class Node {
public:
    Node();
    void insert(const string& word, const size_t index);
    bool search(const string& word, const size_t index);
    bool startsWith(const string& word, const size_t index);
private:
    unordered_map<char, shared_ptr<Node>> m_children;
    bool m_lastWordLetter;
};

class RawNode {
public:
    RawNode();
    ~RawNode();
    void insert(const string& word, const size_t index);
    bool search(const string& word, const size_t index);
    bool startsWith(const string& word, const size_t index);
private:
    unordered_map<char, RawNode*> m_children;
    bool m_lastWordLetter;
};

using NodePtr = RawNode*;

class RecursiveTrie {
public:
    RecursiveTrie();
    ~RecursiveTrie();
    
    /** Inserts a word into the trie. */
    void insert(const string& word);
    
    /** Returns if the word is in the trie. */
    bool search(const string& word);
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix);

private:
    NodePtr m_rootNode;
};

/********************************************************************************************/
class Trie {
public:
    Trie();
    ~Trie();
    
    /** Inserts a word into the trie. */
    void insert(const string& word);
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const;
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const;

private:
    struct Node;
    using NodePtr = Node*;
    struct Node {
        Node();
        ~Node();
        vector<NodePtr> m_children;
        bool m_lastWordLetter;
    };

    NodePtr m_rootNode;
};