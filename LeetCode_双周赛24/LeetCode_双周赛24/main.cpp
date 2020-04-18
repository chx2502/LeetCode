//
//  main.cpp
//  LeetCode_双周赛24
//
//  Created by chx on 2020/4/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    /*
     1. 逐步求和得到正数的最小值
     
     给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
     你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
     请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue
     
     输入：nums = [-3,2,-3,4,2]
     输出：5
     **/
    int minStartValue(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 1;
        int min = 0;
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
            min = sum < min ? sum : min;
        }
        return abs(min)+1;
    }
    
    /*
     2. 和为 K 的最少斐波那契数字数目
     
     给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
     斐波那契数字定义为：
     F1 = 1
     F2 = 1
     Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
     数据保证对于给定的 k ，一定能找到可行解。
     
     输入：k = 7
     输出：2
     解释：斐波那契数字为：1，1，2，3，5，8，13，……
     对于 k = 7 ，我们可以得到 2 + 5 = 7 。
     **/
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fibonacci = {1, 1};
        int index = 2;
        while(fibonacci.back() < k) {
            fibonacci.push_back(fibonacci[index-1] + fibonacci[index-2]);
            index++;
        }
        if (fibonacci.back() == k) return 1;
        else return 1 + findMinFibonacciNumbers(k - fibonacci[index-2]);
    }
    
    /*
     3. 长度为 n 的开心字符串中字典序第 k 小的字符串
     
     一个 「开心字符串」定义为：
     仅包含小写字母 ['a', 'b', 'c'].
     对所有在 1 到 s.length - 1 之间的 i ，满足 s[i] != s[i + 1] （字符串的下标从 1 开始）。
     比方说，字符串 "abc"，"ac"，"b" 和 "abcbabcbcb" 都是开心字符串，
     但是 "aa"，"baa" 和 "ababbc" 都不是开心字符串。
     给你两个整数 n 和 k ，你需要将长度为 n 的所有开心字符串按字典序排序。
     请你返回排序后的第 k 个开心字符串，如果长度为 n 的开心字符串少于 k 个，那么请你返回 空字符串。
     
     输入：n = 3, k = 9
     输出："cab"
     解释：长度为 3 的开心字符串总共有 12 个 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"] 。第 9 个字符串为 "cab"
     **/
    
    void backTracking(string curr, char last, int n,
                      string basic,
                      priority_queue<string, vector<string>, greater<string>>& pq)
    {
        if (curr.length() == n) {
            pq.push(curr);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (basic[i] == last) continue;
            curr.push_back(basic[i]);
            backTracking(curr, basic[i], n, basic, pq);
            curr.pop_back();
        }
    }
    
    string getHappyString(int n, int k) {
        priority_queue<string, vector<string>, greater<string>> pq;
        string curr = "";
        string basic = "abc";
        backTracking(curr, '0', n, basic, pq);
        for (int i = 0; i < k-1; ++i) {
            if (pq.empty()) return "";
            pq.pop();
        }
        if (pq.empty()) return "";
        return pq.top();
    }
    /*
     4. 恢复数组
     
     某个程序本来应该输出一个整数数组。但是这个程序忘记输出空格了以致输出了一个数字字符串，
     我们所知道的信息只有：数组中所有整数都在 [1, k] 之间，且数组中的数字都没有前导 0 。
     给你字符串 s 和整数 k 。可能会有多种不同的数组恢复结果。
     按照上述程序，请你返回所有可能输出字符串 s 的数组方案数。
     由于数组方案数可能会很大，请你返回它对 10^9 + 7 取余 后的结果。
     
     输入：s = "1317", k = 2000
     输出：8
     解释：可行的数组方案为 [1317]，[131,7]，[13,17]，[1,317]，[13,1,7]，[1,31,7]，[1,3,17]，[1,3,1,7]
     **/
    // 第四题解法不对
//    const int LIMIT = 1e9 + 7;
//    void cut(int curr, string s, int length, int k, int& count) {
//        if (count >= LIMIT) count %= LIMIT;
//        if (curr > length) return;
//        if (curr == length) {
//            count += 1;
//            return;
//        }
//        for (int i = 1; i <= length-curr; ++i) {
//            if (s[curr+i] == '0') continue;
//            string left = s.substr(curr, i);
//            if (stoi(left) > k) {
//                cout << stoi(left) << endl;
//                if (s[curr+i-1] == '0') return;
//                else cut(curr+i-1, s, length, k, count);
//                break;
//            } else cut(curr+i, s, length, k, count);
//        }
//    }
//    int numberOfArrays(string s, int k) {
//        int length = (int)s.length();
//        int count = 0;
//        cut(0, s, length, k, count);
//        return count;
//    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.findMinFibonacciNumbers(19);
    string str = s.getHappyString(3, 9);
    string arr = "1230";
//    int count = s.numberOfArrays(arr, 90);
    return 0;
}
