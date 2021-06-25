//
//  main.cpp
//  LeetCode_211
//
//  Created by chx on 2021/4/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Trie {
    vector<Trie*> children;
    bool isEnd;
    Trie(): isEnd(false) { children.assign(26, nullptr); }
};


class WordDictionary {
private:
    Trie *root;
    bool searchPrefix(Trie *t, string& prefix, int index) {
        if (index == prefix.length()) return t->isEnd;
        if (t == nullptr && index < prefix.length()) return false;
        Trie *p = t;
        for (int i = index; i < prefix.size(); i++) {
            char c = prefix[i];
            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (p->children[j] && searchPrefix(p->children[j], prefix, index+1))
                        return true;
                }
            } else {
                c -= 'a';
                if (p->children[c]) return searchPrefix(p->children[c], prefix, index+1);
                else return false;
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *p = root;
        for (auto c : word) {
            c -= 'a';
            if (p->children[c] == nullptr) p->children[c] = new Trie();
            p = p->children[c];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        return searchPrefix(root, word, 0);
    }
};


int main(int argc, const char * argv[]) {
    WordDictionary dict;
    vector<string> words = {
//        "ran", "rune", "runner", "runs",
//        "add", "adds", "adder", "addee",
        "aaa", "ab"
    };
    vector<string> queries = {
//        "..", "r.n", "ru.n.e", "add", "add.",
//        "adde.", ".an.", "...s", "....e.",
//        ".......", "..n.r"
        "..", ".b", "a..", "."
    };
    vector<bool> result;
    for (auto word : words) dict.addWord(word);
    for (auto q : queries) {
        result.push_back(dict.search(q));
    }
    for (auto res : result)
        cout << (res == true ? "true" : "false") << " ";
    return 0;
}
