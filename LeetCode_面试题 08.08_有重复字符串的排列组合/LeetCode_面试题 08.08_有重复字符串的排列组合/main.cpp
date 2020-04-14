//
//  main.cpp
//  LeetCode_面试题 08.08_有重复字符串的排列组合
//
//  Created by chx on 2020/4/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    void backTracking(string S, int begin, int length, vector<string>& result) {
        if (begin == length) {
            result.push_back(S);
            return;
        }
        
        for (int i = begin; i < length; ++i) {
            if (i > begin && (S[i] == S[i-1] || S[begin] == S[i])) continue;
            swap(S[i], S[begin]);
            backTracking(S, begin+1, length, result);
            swap(S[i], S[begin]);
        }
    }
    
    vector<string> permutation(string S) {
        vector<string> result;
        int length = (int)S.length();
        if (length == 0) return result;
        sort(S.begin(), S.end());
        backTracking(S, 0, length, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string S = "qqe";
    vector<string> result = s.permutation(S);
    return 0;
}
