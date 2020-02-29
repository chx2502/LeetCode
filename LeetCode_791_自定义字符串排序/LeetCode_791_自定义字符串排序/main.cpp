//
//  main.cpp
//  LeetCode_791_自定义字符串排序
//
//  Created by chx on 2020/2/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     利用 hashmap M 来存储字符的排序关系，S 中没有的字符随便分配排序关系。
     然后对 T 进行排序
     **/
//    string customSortString(string S, string T) {
//        int S_len = (int)S.length();
//        int T_len = (int)T.length();
//        map<char, int> M;
//        for (int i = 0; i < S_len; ++i) M[S[i]] = i;
//        for (int i = 0; i < T_len; ++i) {
//            char c = T[i];
//            if (M.find(c) == M.end())
//                M[c] = S_len + i;
//        }
//        // lambda : [&] (type A, type B)->return-type { code };
//        sort(T.begin(), T.end(), [&] (char A, char B) -> bool { return M[A] < M[B]; });
//        return T;
//    }
    /*
     官方题解的方法
     **/
    string customSortString(string S, string T) {
//        int S_len = (int)S.length();
//        int T_len = (int)T.length();
        vector<int> count(128, 0);
        
        for (auto &c : T) count[c]++;
        T = "";
        for (auto &c : S) {
            while(count[c]) {
                T.push_back(c);
                count[c]--;
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            while(count[c]) {
                T.push_back((char)c);
                count[c]--;
            }
        }
        return T;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    string S = "cba";
    string T = "abcd";
    string result = s.customSortString(S, T);
    return 0;
}
