#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> weightMap;

    // 动态规划生成各数的权重
    int getWeight(map<int, int>& weightMap, int num) {
        if (weightMap[num]) return weightMap[num];
        else {
            if ((num & 1) ==1) return 1+ getWeight(weightMap, num*3+1);
            else return 1 + getWeight(weightMap, num/2);
        }
    }
    int getKth(int lo, int hi, int k) {
        weightMap[2] = 1;

        // lambda 函数实现 自定义比较函数
         auto comp = [&](int a, int b) {
            int weight_a = getWeight(weightMap, a);
            int weight_b = getWeight(weightMap, b);
            weightMap[a] = weight_a;
            weightMap[b] = weight_b;
            if (weight_a == weight_b) return a > b;
            else return  weight_a  > weight_b;
        };
        // 建立最小堆
        priority_queue<int, vector<int>, decltype(comp)> Q(comp);
        for (int i = lo; i <= hi; ++i) {
            Q.push(i);
        }

        // 找第 k 小元素
        int count = 0;
        int result = lo;
        while (!Q.empty()) {
            result = Q.top();
            Q.pop();
            count++;
            if (count == k) break;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
//    int result = s.maxNumberOfFamilies(3, reservedSeats);
    int result = s.getKth(12, 15, 2);
    return 0;
}
