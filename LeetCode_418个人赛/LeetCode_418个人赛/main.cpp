//
//  main.cpp
//  LeetCode_418个人赛
//
//  Created by chx on 2020/4/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

/**
 1. 拿硬币
 桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。
 */
//
//class Solution {
//public:
//    int minCount(vector<int>& coins) {
//        int result = 0;
//        int size = (int)coins.size();
//        if (size == 0) return result;
//        for (auto &num : coins) {
//            result += num/2 + num%2;
//        }
//        return result;
//    }
//};

/*
 2. 传递信息
 小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：

 有 n 名玩家，所有玩家编号分别为 0 ～ n-1，其中小朋友 A 的编号为 0
 每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
 每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
 给定总玩家数 n，以及按 [玩家编号,对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A (编号 0 ) 经过 k 轮传递到编号为 n-1 的小伙伴处的方案数；若不能到达，返回 0。

 示例 1：

 输入：n = 5, relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], k = 3

 输出：3

 解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->3->4。
 示例 2：

 输入：n = 3, relation = [[0,2],[2,1]], k = 2

 输出：0

 解释：信息不能从小 A 处经过 2 轮传递到编号 2
 限制：

 2 <= n <= 10
 1 <= k <= 5
 1 <= relation.length <= 90, 且 relation[i].length == 2
 0 <= relation[i][0],relation[i][1] < n 且 relation[i][0] != relation[i][1]
 **/
//class Solution {
//public:
//    vector<vector<int>> graph;
//    void bfs(int curr, int step, int n, int k, int &result) {
//        if (step == k) {
//            if (curr == n-1) result += 1;
//            return;
//        }
//        for (int i = 0; i < n; ++i) {
//            if (graph[curr][i] == 1) bfs(i, step+1, n, k, result);
//        }
//    }
//    int numWays(int n, vector<vector<int>>& relation, int k) {
//        graph = vector<vector<int>>(n, vector<int>(n, 0));
//        for (auto &element : relation) {
//            graph[element[0]][element[1]] = 1;
//        }
//        int result = 0;
//        bfs(0, 0, n, k, result);
//        return result;
//    }
//};

/*
 3. 剧情触发时间
 在战略游戏中，玩家往往需要发展自己的势力来触发各种新的剧情。一个势力的主要属性有三种，分别是文明等级（C），资源储备（R）以及人口数量（H）。在游戏开始时（第 0 天），三种属性的值均为 0。

 随着游戏进程的进行，每一天玩家的三种属性都会对应增加，我们用一个二维数组 increase 来表示每天的增加情况。这个二维数组的每个元素是一个长度为 3 的一维数组，例如 [[1,2,1],[3,4,2]] 表示第一天三种属性分别增加 1,2,1 而第二天分别增加 3,4,2。

 所有剧情的触发条件也用一个二维数组 requirements 表示。这个二维数组的每个元素是一个长度为 3 的一维数组，对于某个剧情的触发条件 c[i], r[i], h[i]，如果当前 C >= c[i] 且 R >= r[i] 且 H >= h[i] ，则剧情会被触发。

 根据所给信息，请计算每个剧情的触发时间，并以一个数组返回。如果某个剧情不会被触发，则该剧情对应的触发时间为 -1 。

 示例 1：

 输入： increase = [[2,8,4],[2,5,0],[10,9,8]] requirements = [[2,11,3],[15,10,7],[9,17,12],[8,1,14]]

 输出: [2,-1,3,-1]

 解释：

 初始时，C = 0，R = 0，H = 0

 第 1 天，C = 2，R = 8，H = 4

 第 2 天，C = 4，R = 13，H = 4，此时触发剧情 0

 第 3 天，C = 14，R = 22，H = 12，此时触发剧情 2

 剧情 1 和 3 无法触发。
 示例 2：

 输入： increase = [[0,4,5],[4,8,8],[8,6,1],[10,10,0]] requirements = [[12,11,16],[20,2,6],[9,2,6],[10,18,3],[8,14,9]]

 输出: [-1,4,3,3,3]
 示例 3：

 输入： increase = [[1,1,1]] requirements = [[0,0,0]]

 输出: [0]
 **/

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n = (int)requirements.size();
        vector<int> result(n, -1);
        int end_time = (int)increase.size();
        int time = 0;
        int C, R, H;
        C = R = H = 0;
        vector<vector<int>> matrix;
        for (int i = 0; i < end_time; ++i) {
            C += increase[i][0];
            R += increase[i][1];
            H += increase[i][2];
            matrix.push_back({C, R, H});
        }
        while (time < end_time) {
            for (int i = 0; i < n; ++i) {
                if (result[i] > -1) continue;
                if (matrix[time][0] >= requirements[i][0] &&
                    matrix[time][1] >= requirements[i][1] &&
                    matrix[time][2] >= requirements[i][2]) {
                    result[i] = time + 1;
                }
            }
            time += 1;
        }
        return result;
    }
};

/*
 4. 最小跳跃次数
 为了给刷题的同学一些奖励，力扣团队引入了一个弹簧游戏机。游戏机由 N 个特殊弹簧排成一排，编号为 0 到 N-1。初始有一个小球在编号 0 的弹簧处。若小球在编号为 i 的弹簧处，通过按动弹簧，可以选择把小球向右弹射 jump[i] 的距离，或者向左弹射到任意左侧弹簧的位置。也就是说，在编号为 i 弹簧处按动弹簧，小球可以弹向 0 到 i-1 中任意弹簧或者 i+jump[i] 的弹簧（若 i+jump[i]>=N ，则表示小球弹出了机器）。小球位于编号 0 处的弹簧时不能再向左弹。

 为了获得奖励，你需要将小球弹出机器。请求出最少需要按动多少次弹簧，可以将小球从编号 0 弹簧弹出整个机器，即向右越过编号 N-1 的弹簧。

 示例 1：

 输入：jump = [2, 5, 1, 1, 1, 1]

 输出：3

 解释：小 Z 最少需要按动 3 次弹簧，小球依次到达的顺序为 0 -> 2 -> 1 -> 6，最终小球弹出了机器。
 **/

/*
class Solution {
public:
    
//    int jumpCount(int curr, vector<int>& jump, int n, int &count) {
//        if (curr >= n-1) return count;
//        int leftStep = left_max(curr, jump, n);
//        int rightStep = curr + jump[curr];
//        int nextStep;
//        if (leftStep != -1) {
//            nextStep = leftStep + jump[leftStep] > rightStep + jump[rightStep] ? leftStep : rightStep;
//        } else nextStep = rightStep;
//        count += 1;
//        return jumpCount(nextStep, jump, n, count);
//    }
//
//    int left_max(int curr, vector<int>& jump, int n) {
//        if (curr == 0) return 0;
//        int max = curr;
//        int result = -1;
//        for (int i = curr-1; i >= 0; --i) {
//            if (max < i + jump[i]) {
//                max = i + jump[i];
//                result = i;
//            }
//        }
//        return result;
//    }
    const int INF = 1e6;
//    int jp(int curr,
//           vector<int>& dist,
//           vector<int>& leftMax,
//           vector<int>& leftIndex,
//           int n, int &count) {
//        if (curr == -1) return INF;
//        if (dist[curr] >= n) return count + 1;
//        else {
//            count += 1;
//            return min(
//                       jp(leftIndex[curr], dist, leftMax, leftIndex, n, count),
//                       jp(dist[curr], dist, leftMax, leftIndex, n, count)
//                       );
//        }
//    }
//
//    int minJump(vector<int>& jump) {
//        int result = 0;
//        int n = (int)jump.size();
//        int count = 0;
//        vector<int> dist;
//        vector<int> leftMax(n, 0);
//        vector<int> leftIndex(n, -1);
//        leftMax[0] = -1;
//        for (int i = 0; i < n; ++i) {
//            dist.push_back(i+jump[i]);
//        }
//        for (int i = 1; i < n; ++i) {
//            int a, b;
//            a = leftMax[i-1];
//            b = dist[i-1];
//            if (a < b) {
//                leftIndex[i] = i-1;
//                leftMax[i] = b;
//            } else {
//                leftIndex[i] = leftIndex[i-1];
//                leftMax[i] = a;
//            }
//        }
//        result = jp(0, dist, leftMax, leftIndex, n, count);
//        return result;
//    }
//    int minJump(vector<int>& jump) {
//        int N = (int)jump.size();
//        jump[N-1] = 1;
//        vector<int> temp(jump.begin(), jump.end());
//        for (int i = N-2; i >= 0; --i) {
//            temp[i] = i+temp[i] >= N ? 1 : 1+temp[i+temp[i]];
//        }
//        int left, right;
//        left = 0;
//        right = N-1;
//        while (left < right) {
//            if (temp[right] <= 2) {
//                right--;
//                continue;
//            }
//            if (temp[left] >= temp[right]) left += 1;
//            else {
//                temp[right] = temp[left] + 1;
//                right--;
//            }
//        }
//        for (int i = left-1; i >= 0; --i) {
//            temp[i] = 1 + temp[i + jump[i]];
//        }
//        return temp[0];
//    }
};
*/
int main(int argc, const char * argv[]) {
    Solution s;
//    vector<vector<int>> relation = {
//        {0, 2},
//        {2, 1},
//    };
//    vector<vector<int>> increase = {
//        {0, 4, 5},
//        {4, 8, 8},
//        {8, 6, 1},
//        {10, 10, 0},
//    };
//    vector<vector<int>> requirements = {
//        {12, 11, 16},
//        {20, 2, 6},
//        {9, 2, 6},
//        {10, 18, 3},
//        {8, 14, 9},
//    };
//    vector<int> result = s.getTriggerTime(increase, requirements);
//    int result = s.numWays(3, relation, 2);
    vector<int> jump = {2, 5, 1, 1, 1, 1};
//    int result = s.minJump(jump);
    return 0;
}
