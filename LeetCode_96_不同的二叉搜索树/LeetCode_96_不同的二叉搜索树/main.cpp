//
//  main.cpp
//  LeetCode_96_不同的二叉搜索树
//
//  Created by chx on 2019/12/9.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        /*
         核心思路：
         搜索树的数量仅与数组规模有关，与具体数字起点终点无关
         动态规划：
         对于节点群 [1.. j.. i]，其搜索树的种类数为每个节点作为根节点时的搜索树种类数
         对于节点 1 < j < i，其搜索树数量为 左子树数量 * 右子树数量
         左边节点数：j-1，右边节点数：i-j，故 j 作为根时，有 dp[j-1] * dp[i-j]种搜索树
         对于 j == 1 or j == i，只有右子树或者左子树，故使用加法，左子树/右子树 + 0
         计算 dp[n] 时，需要用到 dp[1], dp[2], ..., dp[n-1]
         因此可以将之前的结果保存起来，用来计算新的值，此处体现备忘录的思想
         dp[0] = 0, dp[1] = 1，从 i=2 开始更新 dp[i] 直到 i == n
         
         看了官方题解后，发现可优化之处：
         当 j == 1 or j == n 时，把空树看作 1 种搜索树，即 dp[0] = 1，可以把特殊情况一般化
         **/
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        int i = 1;
        while (i++ < n) {
            for (int j = 1; j <= i; j++) {
//                if (j-1 != 0 && i-j != 0)
//                    dp[i] += dp[j-1] * dp[i-j];
//                else dp[i] += (dp[j-1] + dp[i-j]);
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 3;
    int result = s.numTrees(n);
    return 0;
}
