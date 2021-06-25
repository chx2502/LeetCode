//
//  main.cpp
//  LeetCode_154
//
//  Created by chx on 2020/7/22.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include <ctime>
#include <random>

using namespace std;

typedef long long ll;

class Solution {
public:
    // 递归法
    int find(vector<int>& nums, int begin, int end) {
        if (begin == end) return begin;
        if (begin == end-1) return nums[begin] < nums[end] ? begin : end;
        int mid = (begin + end) / 2;
        
        int l, m, r;
        l = nums[begin];
        m = nums[mid];
        r = nums[end];

        if (m < r)
            return find(nums, begin, mid);
        if (m > r)
            return find(nums, mid, end);
        return find(nums, begin, end-1);
    }
    
    // 非递归
    int findMin(vector<int>& nums) {
        int size = (int)nums.size();
        int begin, end, mid;
        begin = 0;
        end = size-1;
        
        while (begin < end) {
            mid = (begin + end) / 2;
            if (nums[mid] < nums[end]) end = mid;
            else if (nums[mid] > nums[end]) begin = mid+1;
            else end--;
        }
        return nums[begin];
    }
    
    vector<int> findTwice(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            // curr 可能为负数
            int index = abs(curr);
            // idnex > n 说明该位置已经被访问过 2 次，要还原
            if (index > n) index /= (n+1);
            // 下标对应关系为 nums[i] - 1 = i;
            index--;
            // 第 1 次访问，记为负数，
            if (nums[index] > 0) nums[index] *= -1;
            // 第 1 次访问，记为一个比 n 大的数，后续如果遇到这个数可以判断并还原
            else nums[index] *= -(n+1);
        }
        
        for (int i = 0; i < n; i++) {
            // 访问过两次的数 nums[i] 变为了 nums[i] * (n+1) > n
            if (nums[i] > n) result.push_back(i+1);
        }
        return result;
    }
    
    vector<int> find(vector<int> arr) {
        vector<int> nums(arr.begin(), arr.end());
        int n = (int)nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (curr < 0) continue;
            while(nums[curr] > 0) {
                nums[i] = nums[curr];
                nums[curr] = 0 - n;
                curr = nums[i];
            }
            if (nums[curr] == -n) {
                result.push_back(curr);
                nums[curr]++;
            }
        }
        return result;
    }
    
    bool compare(vector<int>& got, vector<int>& want) {
        if (got.size() != want.size()) return false;
        sort(got.begin(), got.end(), less<int>());
        for (unsigned long i = 0; i < want.size(); i++) {
            if (got[i] != want[i]) return false;
        }
        return true;
    }
    
    int getRandNumber(int begin, int end) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(begin, end);
        return dis(gen);
    }
    
    bool isLegalNumber(int x, unordered_map<int, int>& count) {
        auto it = count.find(x);
        if (it == count.end() || it->second < 2) return true;
        else return false;
    }
    
    pair<vector<int>, vector<int>> genCase(int n) {
        unordered_map<int, int> count;
        for (int i = 1; i <= n; i++) count[i] = 0;
        vector<int> input;
        vector<int> output;
        int x = -1;
        for (int i = 0; i < n; i++) {
            do {
                x = getRandNumber(1, n);
            } while(!isLegalNumber(x, count));
            count[x]++;
            input.push_back(x);
            if (count[x] == 2) output.push_back(x);
        }
        sort(output.begin(), output.end());
        return pair<vector<int>, vector<int>> {input, output};
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
//    vector<int> nums = {3, 3, 1, 3};
//    int result = s.findMin(nums);
    vector<int> nums2 = {4, 2, 2, 5, 8, 4, 1, 7, 5, 7};
    vector<int> res2 = s.find(nums2);



    return 0;
}
