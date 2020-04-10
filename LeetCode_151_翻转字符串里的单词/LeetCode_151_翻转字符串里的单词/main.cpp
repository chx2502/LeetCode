//
//  main.cpp
//  LeetCode_151_翻转字符串里的单词
//
//  Created by chx on 2020/4/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    /*
     依赖于 <sstream> 中的 istringstream，可以轻松获得以空格分割的子串
     **/
    string reverseWords(string s) {
        int length = (int)s.length();
        if (length == 0) return s;
        
        string result = "";
        string temp;
        istringstream str(s);
        while (str >> temp) {
            if (result.length() == 0)
                result = temp + result;
            else result = temp + " " + result;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solu;
    string s = "a good   example";
    string result = solu.reverseWords(s);
    return 0;
}
