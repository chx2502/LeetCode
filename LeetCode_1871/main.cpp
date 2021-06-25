/*
给你一个下标从 0 开始的二进制字符串 s 和两个整数 minJump 和 maxJump 。一开始，你在下标 0 处，且该位置的值一定为 '0' 。当同时满足如下条件时，你可以从下标 i 移动到下标 j 处：

i + minJump <= j <= min(i + maxJump, s.length - 1) 且
s[j] == '0'.
如果你可以到达 s 的下标 s.length - 1 处，请你返回 true ，否则返回 false 。

输入：s = "011010", minJump = 2, maxJump = 3
输出：true
解释：
第一步，从下标 0 移动到下标 3 。
第二步，从下标 3 移动到下标 5 。

输入：s = "01101110", minJump = 2, maxJump = 3
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-vii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int length = (int)s.length();
        vector<int> pre(length, 0);
        vector<int> dp(length, 0);
        dp[0] = 1;
        for (int i = 0; i < minJump; i++) pre[i] = 1;
        int left, right, total;
        for (int i = minJump; i < length; i++) {
            if (s[i] == '0') {
                left = i - maxJump;
                right = i - minJump;
                if (left > 0) total = pre[right] - pre[left-1];
                else total = pre[right];
                if (total > 0) dp[i] = 1;
            }
            pre[i] = pre[i-1] + dp[i];
        }
        return dp[length-1] > 0;
    }
};

int main() {
    Solution s;
    string str = "0000000000";
    int minJump = 8;
    int maxJump = 8;
    bool result = s.canReach(str, minJump, maxJump);
    cout << result << endl;
}