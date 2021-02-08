#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Search/Trie.h"

TEST(TrieTest, trieClassTest)
{
    Trie trie;
    trie.insert("");
    trie.insert("a");
    EXPECT_TRUE(trie.search("a"));
    EXPECT_FALSE(trie.search("b"));
    EXPECT_TRUE(trie.startsWith("a"));
    EXPECT_FALSE(trie.startsWith("b"));

    trie.insert("beta");
    EXPECT_FALSE(trie.search("bet"));
    EXPECT_TRUE(trie.search("beta"));
    EXPECT_TRUE(trie.startsWith("b"));
    EXPECT_TRUE(trie.startsWith("bet"));
    EXPECT_FALSE(trie.startsWith("bo"));

    trie.insert("beton");
    EXPECT_TRUE(trie.startsWith("b"));
    EXPECT_TRUE(trie.startsWith("bet"));
    
}
