//
//  main.cpp
//  LeetCode_208
//
//  Created by chx on 2021/4/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.assign(26, nullptr);
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode *root;
    TrieNode* searchPrefix(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            c -= 'a';
            if (p->children[c] == nullptr) return nullptr;
            p = p->children[c];
        }
        return p;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (auto &c : word) {
            c -= 'a';
            if (p->children[c] == nullptr)
                p->children[c] = new TrieNode();
            p = p->children[c];
        }
        p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = searchPrefix(prefix);
        return node != nullptr;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
