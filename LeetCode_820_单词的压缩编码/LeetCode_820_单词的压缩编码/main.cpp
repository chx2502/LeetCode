//
//  main.cpp
//  LeetCode_820_单词的压缩编码
//
//  Created by chx on 2020/3/28.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    // 加入集合，移除集合中每个元素的后缀
    int minimumLengthEncoding(vector<string>& words) {
        int size = (int)words.size();
        if (size == 0) return 0;
        int result = 0;
        set<string> s;
        for (auto &word : words) {
            s.insert(word);
        }
        for (auto &word : s) {
            int begin = 1;
            while (begin != word.length()) {
                string temp = word.substr(begin, word.length());
                auto iter = s.find(temp);
                if (iter != s.end()) s.erase(iter);
                begin += 1;
            }
        }
        for (auto &word : s) {
            result += word.size()+1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> words = {"time", "me"};
    int res = s.minimumLengthEncoding(words);
    return 0;
}
