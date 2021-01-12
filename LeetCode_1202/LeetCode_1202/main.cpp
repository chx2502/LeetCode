//
//  main.cpp
//  LeetCode_1202
//
//  Created by chx on 2021/1/11.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;
/*
 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，
 其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
 
 示例 1:
 输入：s = "dcab", pairs = [[0,3],[1,2]]
 输出："bacd"
 解释：
 交换 s[0] 和 s[3], s = "bcad"
 交换 s[1] 和 s[2], s = "bacd"
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
private:
    unordered_map<int, pair<int, char>> uf;
    unordered_map<int, vector<pair<int, char>>> group;
    vector<int> groupSize;
    int count;
    
    void merge(vector<pair<int, char>>& groupA, vector<pair<int, char>>& groupB) {
        for (auto &element : groupB) {
            groupA.push_back(element);
        }
    }
    
    void connect(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB) return;
        
        if (groupSize[rootA] < groupSize[rootB]) {
            uf[rootA].first = rootB;
            groupSize[rootB] += groupSize[rootA];
            groupSize[rootA] = groupSize[rootB];
            merge(group[rootB], group[rootA]);
            group.erase(rootA);
        } else {
            uf[rootB].first = rootA;
            groupSize[rootA] += groupSize[rootB];
            groupSize[rootB] = groupSize[rootA];
            merge(group[rootA], group[rootB]);
            group.erase(rootB);
        }
        count--;
    }
    
    int findRoot(int x) {
        while (uf[x].first != x) {
            uf[x].first = uf[uf[x].first].first;
            x = uf[x].first;
        }
        return x;
    }
    int groupCount() {
        return count;
    }
    void initializeUF(string s) {
        int n = (int)s.length();
        count = 0;
        groupSize.assign(n, 0);
        for (int i = 0; i < n; i++) {
            pair<int, char> curr(i, s[i]);
            uf[i] = curr;
            group[i].push_back(curr);
            groupSize[i] = 1;
            count++;
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        initializeUF(s);
        for (auto &p : pairs) {
            connect(p[0], p[1]);
        }
        
        int groups = groupCount();
        if (groups == s.length()) return s;
        if (groups == 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        auto cmp = [&](pair<int, char>& a, pair<int, char>& b) {
            return a.second < b.second;
        };
        
        string result(s.length(), '/');
        for (auto g : group) {
            vector<int> indexes;
            for (auto &element : g.second) indexes.push_back(element.first);
            sort(indexes.begin(), indexes.end());
            sort(g.second.begin(), g.second.end(), cmp);
            for (int i = 0; i < indexes.size(); i++) g.second[i].first = indexes[i];
            for (auto &element : g.second) result[element.first] = element.second;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "udyyek";
    vector<vector<int>> pairs = {
        {3, 3},
        {3, 0},
        {5, 1},
        {3, 1},
        {3, 4},
        {3, 5},
    };
    string result = solve.smallestStringWithSwaps(s, pairs);
    return 0;
}
