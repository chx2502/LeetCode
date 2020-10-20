//
//  main.cpp
//  LeetCode_692
//
//  Created by chx on 2020/10/19.
//

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int size = (int)words.size();
        if (size == 0) return words;
        
        vector<string> result;
        unordered_map<string, int> memory;
        auto cmp = [&](string a, string b) {
            if (memory[a] == memory[b]) return a.compare(b) < 0;
            else return memory[a] > memory[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < size; i++) {
            string word = words[i];
            memory[word]++;
        }
        
        for (auto item : memory) {
            string word = item.first;
            if (pq.size() < k) pq.push(word);
            else {
                if (cmp(word, pq.top())) {
                    pq.pop();
                    pq.push(word);
                }
            }
        }
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> words = {"aaa", "aa", "a"};
    int k = 4;
    vector<string> result = s.topKFrequent(words, k);
    return 0;
}
