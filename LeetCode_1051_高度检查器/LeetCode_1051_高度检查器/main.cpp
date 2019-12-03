//
//  main.cpp
//  LeetCode_1051_高度检查器
//
//  Created by chx on 2019/12/1.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     构造一个以数字值为 key 的 map 来记录每个数字出现的次数
     数字 1 出现的区间为[0, map[1])，数字 2 出现的区间为[ map[1], map[2] + map[1] )
     对于数字 0 < i < 101,在数组中所处的位置位于 [ map[i-1], map[i] + map[i-1] ) 区间
     逐一更新 map 中的值使得 map[i] 记录的是数字 i 的结束位置
     最后逐一比较 heights 中的数字 num 是否处于 [ map[num-1], map[num] ) 区间
     时间复杂度 O(n), 空间复杂度 O(n)
     **/
    int heightChecker(vector<int>& heights) {
        const int max = 101;
        vector<int> map(max, 0);
        for (auto &num : heights)
            map[num]++;
        for (int i = 1; i < max; i++)
            map[i] += map[i-1];
        
        int length = (int)heights.size();
        int count = 0;
        for (int i = 0; i < length; i++) {
            int num = heights[i];
            int start_pos = map[num-1];
            int end_pos = map[num];
            if (i < start_pos || i >= end_pos)
                count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
