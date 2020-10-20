//
//  main.cpp
//  LeetCode_739
//
//  Created by chx on 2020/10/19.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int size = (int)T.size();
        stack<int> stk;
        vector<int> result(size, 0);
        
        for (int i = 0; i < size; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int preIdx = stk.top();
                result[preIdx] = i-preIdx;
                stk.pop();
            }
            stk.push(i);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> T = { 73,74,75,71,69,72,76,73 };
    vector<int> result = s.dailyTemperatures(T);
    return 0;
}
