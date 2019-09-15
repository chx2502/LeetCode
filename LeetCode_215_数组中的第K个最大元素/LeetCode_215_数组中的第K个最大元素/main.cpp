//
//  main.cpp
//  LeetCode_215_数组中的第K个最大元素
//
//  Created by 成鑫 on 2019/7/12.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define INF 2147483647
/* 核心思想：建立一个最大堆然后返回第 k 次 heap.pop() 的元素 */
class Solution {
public:
    void swap(vector<int>& nums, unsigned long i, unsigned long j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void MAX_HEAPLIFY(vector<int>& nums, unsigned long i) {
        unsigned long left, right, max_index;
        const unsigned long length = nums.size()-1;
        max_index = i;
        left = i * 2;
        right = i * 2 + 1;
        if (left <= length) {
            if (nums[max_index] < nums[left])
                max_index = left;
        }
        if (right <= length){
            if(nums[max_index] < nums[right])
                max_index = right;
        }
        if (i != max_index) {
            swap(nums, i, max_index);
            MAX_HEAPLIFY(nums, max_index);
        }
        return;
    }
    void Build_MaxHeap(vector<int>& nums) {
        nums.push_back(INF);
        swap(nums, 0, nums.size()-1);       // 创建哨兵
        
        const int length = (int)nums.size()-1;
        for (int i = length/2; i >= 1; i--)
            MAX_HEAPLIFY(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1 && k==1) return nums[0];   // 优化特殊情况
        Build_MaxHeap(nums);
        for (int i = 1; i < k; i++) {
            swap(nums, 1, nums.size()-1);
            nums.pop_back();
            MAX_HEAPLIFY(nums, 1);
        }
        return nums[1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1};
    Solution s;
    s.Build_MaxHeap(nums);
    int res = s.findKthLargest(nums, 1);
    cout << "max_k = " << res << endl;
    return 0;
}
