//
//  main.cpp
//  LeetCode_28_实现strStr()
//
//  Created by 成鑫 on 2019/4/17.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        char *p, *q;
        int ret = 0;
        p = &haystack[0];
        q = &needle[0];
        while (*p != '\0') {
            ret = (int)haystack.find(*q);
            haystack.fin
            if (ret == -1) return ret;
            p = &haystack[ret];
            while (*p == *q && *p != '\0' && *q != '\0') {
                p++;
                q++;
                if (*q == '\0') return ret;
            }
            q = &needle[0];
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    int result;
    string haystack = "mississippi";
    string needle = "issipi";
    Solution s;
    result = s.strStr(haystack, needle);
    return 0;
}
