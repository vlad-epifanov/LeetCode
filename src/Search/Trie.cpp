/********************************************************************************************
 * Implementation of Trie data structure (Prefix tree)
 ********************************************************************************************/

#include "Trie.h"

/********************************************************************************************/

Node::Node() : m_children(), m_lastWordLetter(false)
{
}

void Node::insert(const string& word, const size_t index)
{
    if (index >= word.length())
        return;
    const char c = word[index];
    if (!m_children.count(c)) {
        m_children[c] = std::make_shared<Node>();
    }
    auto pNode = m_children[c];
    if (index == (word.length()-1)) {
        // Last character - set the num
        pNode->m_lastWordLetter = true;
        return;
    }
    pNode->insert(word, index+1);
}

bool Node::search(const string& word, const size_t index)
{
    if (index >= word.length())
        return false;
    if (m_children.count(word[index])) {
        auto& pNode = m_children[word[index]];
        if (index == (word.length()-1) && pNode->m_lastWordLetter) {
            return true;
        }
        return pNode->search(word, index+1);
    }
    return false;
}

bool Node::startsWith(const string& word, const size_t index)
{
    if (index >= word.length())
        return false;
    if (m_children.count(word[index])) {
        if (index == (word.length()-1)) {
            return true;
        }
        return m_children[word[index]]->startsWith(word, index+1);
    }
    return false;
}

/********************************************************************************************/

RawNode::RawNode() : m_children(), m_lastWordLetter(false)
{
}

RawNode::~RawNode()
{
    for (auto [c, pNode] : m_children) {
        delete pNode;
    }
}

void RawNode::insert(const string& word, const size_t index)
{
    if (index >= word.length())
        return;
    const char c = word[index];
    if (!m_children.count(c)) {
        m_children[c] = new RawNode();
    }
    auto pNode = m_children[c];
    if (index == (word.length()-1)) {
        // Last character - set the num
        pNode->m_lastWordLetter = true;
        return;
    }
    pNode->insert(word, index+1);
}

bool RawNode::search(const string& word, const size_t index)
{
    if (index >= word.length())
        return false;
    if (m_children.count(word[index])) {
        auto& pNode = m_children[word[index]];
        if (index == (word.length()-1) && pNode->m_lastWordLetter) {
            return true;
        }
        return pNode->search(word, index+1);
    }
    return false;
}

bool RawNode::startsWith(const string& word, const size_t index)
{
    if (index >= word.length())
        return false;
    if (m_children.count(word[index])) {
        if (index == (word.length()-1)) {
            return true;
        }
        return m_children[word[index]]->startsWith(word, index+1);
    }
    return false;
}

/********************************************************************************************/

RecursiveTrie::RecursiveTrie() : m_rootNode(new RawNode)
{
}

RecursiveTrie::~RecursiveTrie()
{
    delete m_rootNode;
}
    
void RecursiveTrie::insert(const string& word)
{
    if (word.empty())
        return;
    m_rootNode->insert(word, 0);
}
    
bool RecursiveTrie::search(const string& word)
{
    return m_rootNode->search(word, 0);
}
    
bool RecursiveTrie::startsWith(const string& prefix)
{
    return m_rootNode->startsWith(prefix, 0);
}

/********************************************************************************************/
static const size_t ALPHABET_SIZE = 26;

Trie::Node::Node() : m_children(ALPHABET_SIZE), m_lastWordLetter(false)
{
}

bool Trie::Node::search(const string& word, const size_t index)
{
    // if (index >= word.length())
    //     return false;
    // if (m_children.count(word[index])) {
    //     auto& pNode = m_children[word[index]];
    //     if (index == (word.length()-1) && pNode->m_lastWordLetter) {
    //         return true;
    //     }
    //     return pNode->search(word, index+1);
    // }
    return false;
}

bool Trie::Node::startsWith(const string& word, const size_t index)
{
    // if (index >= word.length())
    //     return false;
    // if (m_children.count(word[index])) {
    //     if (index == (word.length()-1)) {
    //         return true;
    //     }
    //     return m_children[word[index]]->startsWith(word, index+1);
    // }
    return false;
}

Trie::Trie() : m_rootNode(new Node)
{
}

Trie::~Trie()
{
}
    
void Trie::insert(const string& word)
{
    if (word.empty())
        return;
    size_t wSize = word.size();
    auto pCurNode = m_rootNode;
    for ( size_t idx = 0; idx < wSize; idx++) {
        pCurNode = pCurNode->m_children[word[idx]];
        if (!pCurNode) {
            pCurNode.reset(new Node());
        }
    }
    pCurNode->m_lastWordLetter = true;
}
    
bool Trie::search(const string& word)
{
    return m_rootNode->search(word, 0);
}
    
bool Trie::startsWith(const string& prefix)
{
    return m_rootNode->startsWith(prefix, 0);
}