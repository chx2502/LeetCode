//
//  main.cpp
//  LeetCode_45
//
//  Created by chx on 2020/5/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     动态规划求解：
     设置一个 memory 数组用来记忆每个下标 i 的最优解，
     即 memory[i] 是下标 i 跳到终点的最少步数。
     对于下标 curr_idx，其可达范围为 [ curr_idx+1, curr_idx+nums[curr_idx] ]
     若终点在该区间内，说明下标 curr_idx 处可以一步到位，memory[curr_idx] = 1
     若无法一步到位，则从能跳到最远处开始找最小步数，
     更新 memory[curr_idx] = min(memory[curr_idx], memory[next_step])
     
     两处针对性优化：
     1. 若当前点 curr_idx 能够 1 步 跳到终点，对于 [0, curr_idx-1] 中不能 1 步跳到的点，
        curr_idx 是最佳落脚点，故用 best_choice 记录 curr_idx
     2.对于既不能 1 步到位也不能跳到 best_choice 的点，3 步是他们能得到的最优解
    **/
    const int MAX = 0x3FFFFFFF;
    vector<int> memory;
    int best_choice = MAX;
    
    void jp(int curr_idx, vector<int>& nums, int size) {
        int steps = MAX;
        for (int i = curr_idx+nums[curr_idx]; i > curr_idx; --i) {
            if (i >= size-1) {
                // 可以 1 步跳到，作为 [0, i-1] 区间的 best_choice
                memory[curr_idx] = 1;
                best_choice = curr_idx;
                return;
            }
            if (curr_idx+nums[curr_idx] >= best_choice) {
                // 能够跳到 best_choice，memory[i] = 1+1 = 2
                memory[curr_idx] = 2;
                return;
            }
            // 不能 1 步跳到终点，由远及近寻找最优解
            steps = min(steps, 1 + memory[i]);
            // 针对性优化，对于不能 1 步到终点且到不了 best_choice 的 i，3 步肯定为最优解，可以提前结束
            if (steps == 3) break;
        }
        memory[curr_idx] = steps;
    }
    
    int jump(vector<int>& nums) {
        int size = (int)nums.size();
        memory = vector<int>(size, MAX);
        memory[size-1] = 0;
        // 倒序求解，保证在计算下标 i 时， [i+1, size-1] 区间已是最优解
        for (int i = size-2; i >= 0; --i)
            jp(i, nums, size);
        return memory[0];
    }
};
// 5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
int main(int argc, const char * argv[]) {
    vector<int> nums = { 5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5
    };
    Solution s;
    int reusult = s.jump(nums);
    return 0;
}

