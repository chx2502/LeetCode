//
//  main.cpp
//  LeetCode_17.13
//
//  Created by chx on 2020/7/9.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieTree {
public:
    vector<TrieTree*> next;
    bool isEnd;
    TrieTree() {
        next = vector<TrieTree*>(128, nullptr);
        isEnd = false;
    }
    
    void insert(string s) {
        int length = (int)s.length();
        TrieTree *curr = this;
        
        for (int i = length-1; i >=0; --i) {
            int pos = s[i] - 'a';
            if (curr->next[pos] == nullptr) {
                curr->next[pos] = new TrieTree();
            }
            curr = curr->next[pos];
        }
        curr->isEnd = true;
    }
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        
        int length = (int)sentence.length();
        if (length == 0) return 0;
        if (dictionary.size() == 0) return length;
        
        TrieTree *dictionaryTree = new TrieTree();
        for (auto word : dictionary)
            dictionaryTree->insert(word);
        
        const int INF = 0x3f3f3f3f;
        vector<int> dp(length+1, INF);
        dp[0] = 0;
        
        for (int i = 1; i <= length; ++i) {
            dp[i] = dp[i-1] + 1;
            TrieTree *curr = dictionaryTree;
            for (int j = i; j > 0; --j) {
                int c = sentence[j-1] - 'a';
                if (curr->next[c] == nullptr) {
                    break;
                } else if (curr->next[c]->isEnd) {
                    dp[i] = min(dp[i], dp[j-1]);
                }
                if (dp[i] == 0) break;
                curr = curr->next[c];
            }
        }
        return dp[length];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<string> dictionary = {"looked", "just", "like", "her", "brother"};
    string sentence = "jesslookedjustliketimherbrother";
    int result = s.respace(dictionary, sentence);
    return 0;
}
