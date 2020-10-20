//
//  main.cpp
//  LeetCode_1002
//
//  Created by chx on 2020/10/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<unordered_map<char, int>> memo(A.size());
        unordered_set<char> charSet;
//        memo.resize(A.size());
        for (int i = 0; i < A.size(); i++) {
            for (auto &c : A[i]) memo[i][c]++;
        }
        vector<string> result;
        for (auto c : A[0]) charSet.insert(c);
        for (auto c : charSet) {
            int count = INT_MAX;
            for (int i = 0; i < A.size(); i++) {
                if (memo[i].count(c)) {
                    count = min(count, memo[i][c]);
                } else count = 0;
            }
            string s;
            s.push_back(c);
            for (int j = 0; j < count; j++) result.push_back(s);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> A = {
        "bella",
        "label",
        "roller",
    };
    vector<string> result = s.commonChars(A);
    return 0;
}
