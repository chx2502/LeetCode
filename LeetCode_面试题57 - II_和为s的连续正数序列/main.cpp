#include <iostream>
#include <vector>

using namespace std;

/*
    输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

    序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    输入：target = 9
    输出：[[2,3,4],[4,5]]
 * */

class Solution {
public:
    /*
     * 核心思路：
     * 动态规划。
     * 设置数组 dp，dp[n] 存储 1 到 n 之和，
     * 1 < n < (target / 2 + 1)，故数组长度为 target/2 + 2，
     * 设置双指针 i，j，令 i < j，则 dp[j]-dp[i] 为区间 [i+1, j] 之和
     * 当 dp[j] - dp[i] == target 时，数列 [i+1, j] 为一个解，j 后移寻找下一个解
     * 当 dp[j] - dp[i] > target 时，i 后移
     * 当 dp[j] - dp[i] < target 时，j 后移
     * */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        if (target < 2) return result;
        int N = target/2 + 2;
        int i, j;
        i = 0;
        j = 1;
        vector<int> dp(N, 0);

        while (j < N) {
            dp[j] = dp[j-1] + j;
            int sum = dp[j] - dp[i];
            if (sum == target) {
                vector<int> temp;
                for (int k = i+1; k <= j; ++k)
                    temp.push_back(k);
                result.push_back(temp);
            }

            if (sum > target) i++;
            else j++;
        }
        return result;
    }
    /*
     * 优化：无需存储前 n 项和，直接用等差数列求和公式求解 [i+1, j] 之和
     * */
//    vector<vector<int>> findContinuousSequence(int target) {
//        vector<vector<int>> result;
//        if (target < 2) return result;
//        int i, j, N;
//        N = target / 2 + 2;
//        i = 0;
//        j = 2;
//        while (j < N) {
//            int sum = (i + 1 + j) * (j-i) / 2;
//            if (sum == target) {
//                vector<int> temp;
//                for (int k = i+1; k <= j; ++k)
//                    temp.push_back(k);
//                result.push_back(temp);
//            }
//            if (sum > target) i++;
//            else j++;
//        }
//        return result;
//    }
};

int main() {
    Solution s;
    int target = 9;
    vector<vector<int>> result = s.findContinuousSequence(target);
    return 0;
}
