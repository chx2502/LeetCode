#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        // 0-1 背包，从 stones 中拿一半的石子，使石子总重量最接近 sum/2
        int n = (int)stones.size();
        int weight = sum/2;
        // vector<vector<int>> dp(n+1, vector<int>(weight+1, 0));

        vector<int> dp(weight+1, 0);

        for (int i = 1; i <= n; i++) {
            int s = stones[i-1];
            for (int w = weight; w >= 0; w--) {
                // if (w >= s) {
                    // dp[i][w] = max(dp[i-1][w], dp[i-1][w-s] + s);
                // } else dp[i][w] = dp[i-1][w];
                if (w >= s) dp[w] = max(dp[w], dp[w-s] + s);
            }
        }
        // return sum - 2 * dp[n][weight];
        return sum - 2 * dp[weight];
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = s.lastStoneWeightII(stones);
    cout << result << endl;
}