/********************************************************************************************
 * Implementation of Trie data structure (Prefix tree)
 ********************************************************************************************/

#include "Trie.h"

/********************************************************************************************/

void Trie::Node::insert(const string& word, const size_t index)
{
    if (index >= word.length())
        return;
    auto& pNode = m_children[word[index]];
    if (!pNode) {
        pNode = std::make_shared<Node>();
    }
    if (index == (word.length()-1)) {
        // Last character - set the num
        pNode->m_lastWordLetter = true;
        return;
    }
    pNode->insert(word, index+1);
}

bool Trie::Node::search(const string& word, const size_t index)
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

bool Trie::Node::startsWith(const string& word, const size_t index)
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

Trie::Trie() : m_rootNode(new Node())
{
}
    
void Trie::insert(const string& word)
{
    if (word.empty())
        return;
    m_rootNode->insert(word, 0);
}
    
bool Trie::search(const string& word)
{
    return m_rootNode->search(word, 0);
}
    
bool Trie::startsWith(const string& prefix)
{
    return m_rootNode->startsWith(prefix, 0);
}

