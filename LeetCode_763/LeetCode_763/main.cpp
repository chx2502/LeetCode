//
//  main.cpp
//  LeetCode_763
//
//  Created by chx on 2020/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int length = (int)S.length();
        
        unordered_map<char, int> lastPos;
        for (int i = 0; i < length; i++) {
            lastPos[S[i]] = i;
        }
        
        vector<int> result;
        int pre = -1;
        int limit = -1;
        for (int i = 0; i < length; i++) {
            int last = lastPos[S[i]];
            limit = max(limit, last);
            if (i < last || i < limit) continue;
            else {
                if (i >= limit) {
                    result.push_back(i-pre);
                    pre = i;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string S = "eaaaabaaec";
    vector<int> result = s.partitionLabels(S);
    return 0;
}
