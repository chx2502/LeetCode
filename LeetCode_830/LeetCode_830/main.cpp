//
//  main.cpp
//  LeetCode_830
//
//  Created by chx on 2021/1/7.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> createSection(int begin, int end) {
        return {begin, end};
    }
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int length = (int)s.length();
        if (length < 3) return result;
        
        int start = 0;
        int i = 1;
        for (; i < length; i++) {
            if (s[i] != s[i-1]) {
                if (i-start >= 3) result.push_back(createSection(start, i-1));
                start = i;
            }
        }
        if (i-start >= 3) result.push_back(createSection(start, i-1));
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = "aaa";
    vector<vector<int>> result = s.largeGroupPositions(str);
    return 0;
}
