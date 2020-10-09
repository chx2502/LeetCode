//
//  main.cpp
//  LeetCode_周赛200
//
//  Created by chx on 2020/8/2.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    /*
     第一题 统计好三元组
     给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。

     如果三元组 (arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。

     0 <= i < j < k < arr.length
     |arr[i] - arr[j]| <= a
     |arr[j] - arr[k]| <= b
     |arr[i] - arr[k]| <= c
     其中 |x| 表示 x 的绝对值。

     返回 好三元组的数量。
     
     输入：arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
     输出：4
     解释：一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)]
     
     输入：arr = [1,1,2,2,3], a = 0, b = 0, c = 1
     输出：0
     解释：不存在满足所有条件的三元组。
     **/
    void backTracking(vector<int>& curr, int start, vector<int>& arr, int& result, int a, int b, int c) {
        int curr_size = (int)curr.size();
        if (curr_size == 3) {
            result += 1;
            return;
        }
        if (start >= arr.size()) return;

        for (int i = start; i < arr.size(); i++) {
            if (curr_size == 0) {
                curr.push_back(arr[i]);
                backTracking(curr, i+1, arr, result, a, b, c);
                curr.pop_back();
            }
            if (curr_size == 1) {
                if (abs(curr[0] - arr[i]) > a) continue;
                else {
                    curr.push_back(arr[i]);
                    backTracking(curr, i+1, arr, result, a, b, c);
                    curr.pop_back();
                }
            }
            if (curr_size == 2) {
                if (abs(curr[0] - arr[i]) > c || abs(curr[1] - arr[i]) > b) continue;
                else {
                    curr.push_back(arr[i]);
                    backTracking(curr, i+1, arr, result, a, b, c);
                    curr.pop_back();
                }
            }
        }
    }
    
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        if (arr.empty()) return 0;
        int result = 0;
        vector<int> curr;
        backTracking(curr, 0, arr, result, a, b, c);
        return result;
    }
    /*
     第二题 找出数组游戏的赢家
     
     给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。

     每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

     返回赢得比赛的整数。

     题目数据 保证 游戏存在赢家。
     输入：arr = [2,1,3,5,4,6,7], k = 2
     输出：5
     输入：arr = [1,9,8,2,3,7,6,4,5], k = 7
     输出：9
     **/
    /*
     双指针 p,q 分别代表 2 个比较的数
     k >= arr.size()-1 则返回最大的数
     否则开始用 p, q 模拟比较，同时计算胜场数
     if: p > q then: q++
     else : p = q, q++
     只需要比较到 q 指向末尾即可，超过结尾的情况即 k > size-1 已在前面返回。
     **/
    int getWinner(vector<int>& arr, int k) {
        int size = (int)arr.size();
        
        if (k >= size-1) {
            // 排序影响速度
//            sort(arr.begin(), arr.end(), less<int>());
            int m = -1;
            for (auto &num : arr) m = max(m, num);
            return m;
        }
        int p, q, winner, count;
        p = 0;
        q = 1;
        winner = -1;
        count = 0;
        while (q < size) {
            bool win = arr[p] > arr[q];
            winner = win ? arr[p] : arr[q];
            if (!win) {
                p = q;
                count = 1;
            } else {
                count += 1;
            }
            if (count == k) return winner;
            q++;
        }
        return winner;
    }
    
    /*
     第三题 排布二进制网格的最少交换次数
     
     给你一个 n x n 的二进制网格 grid，每一次操作中，你可以选择网格的 相邻两行 进行交换。

     一个符合要求的网格需要满足主对角线以上的格子全部都是 0 。

     请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 -1 。

     主对角线指的是从 (1, 1) 到 (n, n) 的这些格子。
     
     输入：grid = [[0,0,1],[1,1,0],[1,0,0]]
     输出：3
     **/
    // 计算结尾的连续 0 个数
    int countZero(vector<int>& array) {
        int size = (int)array.size();
        int result = 0;
        for (int i = size-1; i >= 0; i--) {
            if (array[i] != 0) return result;
            result++;
        }
        return result;
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        int size = (int)grid.size();
        if (size == 0) return 0;
        
        vector<bool> zeroRequire(size, false);
        zeroRequire[0] = true;
        vector<int> zeroArr;
        
        // 计算每行的连续 0，检查能不能满足 [size-1, size-2 ... 1] 的 0 数量需求
        for (auto &array : grid) {
            int count = countZero(array);
            int i = count > size-1 ? size-1 : count;
            for (; i > 0; i--) {
                if (!zeroRequire[i]) {
                    zeroRequire[i] = true;
                    break;
                }
            }
            zeroArr.push_back(count);
        }
        // 无解返回 -1
        for (auto satisfied : zeroRequire)
            if (!satisfied) return -1;
        
        // 有解，模拟交换过程
        int result = 0;
        
        for (int target = 0; target < size-1; target++) {
            int require = size - 1 - target;
            for (int start = target; start < size; start++) {
                if (zeroArr[start] >= require) {
                    for (int i = start; i > target; i--) {
                        swap(zeroArr[i], zeroArr[i-1]);
                        result += 1;
                    }
                    break;
                }
            }
        }
        return result;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr1 = {1, 1, 2, 2, 3};
    vector<int> arr2 = {1, 25, 35, 42, 68, 70};
    vector<vector<int>> grid = {
        {0, 0},
        {0, 1},
    };
    int res1 = s.countGoodTriplets(arr1, 0, 0, 1);
    int res2 = s.getWinner(arr2, 1);
    int res3 = s.minSwaps(grid);
    return 0;
}
