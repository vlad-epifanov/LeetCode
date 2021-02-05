/********************************************************************************************
 * Implementation of Trie data structure (Prefix tree)
 ********************************************************************************************/

#include "Trie.h"

/********************************************************************************************/

Trie::Trie() : m_rootMap()
{
}
    
void Trie::insert(const string& word)
{
    if (word.empty())
        return;
    //auto pNode = getRootNode(word[0]);
}
    
bool Trie::search(const string& word)
{
    return true;
}
    
bool Trie::startsWith(const string& prefix)
{
    return true;
}

