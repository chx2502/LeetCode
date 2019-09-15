//
//  main.cpp
//  LeetCode_347_前 K 个高频元素
//
//  Created by 成鑫 on 2019/7/14.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct element {
    int val;
    int times;
};

struct cmp {
    bool operator () (const element a, const element b) {
        return a.times < b.times;
    }
};

/*  思路：nums 中的 (元素值, 次数) 作为 map 中的 (key, value)
    构建优先队列的元素 element，出现次数 times 作为优先级
    重写优先级比较函数 cmp，出现次数大的优先级高
    map 中的元素全部压入优先队列，再出列 k 个即为解
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_map;
        priority_queue< element, vector<element>, cmp > p_queue;
        int length = (int)nums.size();
        for (int i = 0; i < length; i++)
            num_map[nums[i]]++;
        for (const auto &x : num_map) {
            element e;
            e.val = x.first;
            e.times = x.second;
            p_queue.push(e);
        }
        vector<int> res = {};
        for (int i = 0; i < k; i++) {
            element e = p_queue.top();
            res.push_back(e.val);
            p_queue.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
