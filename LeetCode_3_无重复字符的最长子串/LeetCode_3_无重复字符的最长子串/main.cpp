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

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int length = (int)s.length();
        if (length == 0) return 0;
        
        int result = 1;
        vector<int> alpha_map(128, -1);
        int start = 0;
        
        for (int i = 0; i < length; ++i) {
            char c = s[i];
            if (alpha_map[c] == -1 || alpha_map[c] < start)
                result = max(result, i-start+1);
            else start = alpha_map[c]+1;
            alpha_map[c] = i;
        }
        
        return result;

    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string test = "abcabcbb";
    Solution s;
    int result = s.lengthOfLongestSubstring(test);
//    cout << (int)'A' << " " << (int)'Z' << " " << (int)'z' - (int)'A' << endl;
    return 0;
}
