//
//  main.cpp
//  LeetCode_1140
//
//  Created by chx on 2020/4/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    const int MAX = 1e7+1;
    unordered_map<int, unordered_map<int, int>> memory;
    vector<int> acc;
    int dfs(int start, int M, int size) {
        // 如果 start 超过 piles 下标范围，返回 0
        if (start >= size) return 0;
        
        // 如果当前状态已计算过，直接返回记忆结果
        if (
            memory.find(start) != memory.end() &&
            memory[start].find(M) != memory[start].end()
            )
            return memory[start][M];
        
        // 如果 在 1 <= X <= 2M 种选择中可以拿完剩下的，则选择全拿
        if (2*M >= size-start) {
            memory[start][M] = acc[start];
            return acc[start];
        }
        
        // 如果不能拿完， 则选择让对手拿得最少的拿法
        int max_gain = 0;
        for (int X = 1; X <= 2*M; ++X) {
            int next_M = max(X, M);
            int next_max_gain = dfs(start+X, next_M, size);
            max_gain = max(max_gain, acc[start] - next_max_gain);
        }
        memory[start][M] = max_gain;
        return max_gain;
    }
    
    int stoneGameII(vector<int>& piles) {
        int size = (int)piles.size();
        if (size == 0) return 0;
        
        copy(piles.begin(), piles.end(), back_inserter(acc));
        for (int i = size-2; i >= 0; --i)
            acc[i] += acc[i+1];
        int result = 0;
        result = dfs(0, 1, size);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> piles = {2, 7, 9, 4, 4};
    int result = s.stoneGameII(piles);
    return 0;
}
