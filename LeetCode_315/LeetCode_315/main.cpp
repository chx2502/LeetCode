//
//  main.cpp
//  LeetCode_315
//
//  Created by chx on 2020/7/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 知识点：
 离散化索引， 树状数组。
 树状数组介绍：https://www.cnblogs.com/xenny/p/9739600.html
 离散化索引：将给定的 nums 数组排序后去重，每个数字从小到大装入新数组，新数组的下标即为这些数字的索引号。
 lower_bound(first, last, value): 返回指向范围 [first, last) 中首个不小于（即大于或等于） value 的元素的迭代器，或若找不到这种元素则返回 last
 unique(first, last): 从来自范围 [first, last) 的相继等价元素组消除首元素外的元素，并返回范围的新逻辑结尾的尾后迭代器。
 参考题解：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/ji-suan-you-ce-xiao-yu-dang-qian-yuan-su-de-ge-s-7/
 **/

class Solution {
private:
    vector<int> buckets;
    vector<int> prefix_sum;
    
    void Init(int size) {
        prefix_sum.resize(size);
    }
    
    // 将给定的 nums 数组排序后去重，每个数字从小到大装入新数组，新数组的下标即为这些数字的索引号。
    // [5, 2, 6, 1] -> [1, 2, 5, 6] 对应索引 [0, 1, 2, 3]
    // 则 buckets = [1, 2, 5, 6], prefix_sum[0, 1, 2, 3] 对应当前 [1, 2, 5, 6] 的前缀和
    void Discretization(vector<int>& nums) {
        buckets.assign(nums.begin(), nums.end());
        sort(buckets.begin(), buckets.end(), less<int>());
        buckets.erase(unique(buckets.begin(), buckets.end()), buckets.end());
    }
    
    // 查询 x 在 prefix_sum 中的下标，即查询 x 在 buckets 中的下标
    int getId(int x) {
        return (int)(lower_bound(buckets.begin(), buckets.end(), x) - buckets.begin()) + 1;
    }
    
    // lowBit 为专门称呼，一种快速计算树状数组下标规律的方法
    int lowBit(int x) {
        return x & (-x);
    }
    
    // 按照树状数组的规律更新前缀和
    void updatePrefixSum(int pos) {
        while (pos < prefix_sum.size()) {
            prefix_sum[pos] += 1;
            pos += lowBit(pos);
        }
    }
    
    // 查询对应位置的前缀和
    int query(int pos) {
        int result = 0;
        while (pos > 0) {
            result += prefix_sum[pos];
            pos -= lowBit(pos);
        }
        return result;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return {};
        
        vector<int> result;
        Discretization(nums);
        Init(size+1);
        
        for (int i = size-1; i >= 0; --i) {
            int pos = getId(nums[i]);
            result.push_back(query(pos-1));
            updatePrefixSum(pos);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = s.countSmaller(nums);
    return 0;
}
