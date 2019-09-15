//
//  main.cpp
//  LeetCode_3_无重复字符的最长子串
//
//  Created by 成鑫 on 2019/8/18.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int ato_idx(char c) {
        return (int)c;
    }
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int length = (int)s.length();
        vector<int> map(128, 0);
        int start, end;
        start = end = 0;
        int maxlen = 0;
        while(end < length) {
            char c = s[end];
            int idx = ato_idx(c);
            if (map[idx] > 0) {
                start = start > map[idx] ? start : map[idx];
                map[idx] = end+1;
                if (start > end) end = start;
            } else map[idx] = end+1;
            maxlen = end - start + 1 > maxlen ? end - start + 1 : maxlen;
            end += 1;
        }
        return maxlen;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string test = " ";
    Solution s;
    int result = s.lengthOfLongestSubstring(test);
    cout << (int)'A' << " " << (int)'Z' << " " << (int)'z' - (int)'A' << endl;
    return 0;
}
