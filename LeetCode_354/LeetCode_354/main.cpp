//
//  main.cpp
//  LeetCode_354
//
//  Created by chx on 2021/3/4.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
//    struct cmp {
//        bool operator ()(vector<int> a, vector<int> b) {
//            return a[0] < b[0] && a[1] < b[1];
//        }
//    };
    /*
     排序后 dp
     **/
//    int maxEnvelopes(vector<vector<int>>& envelopes) {
//        int size = (int)envelopes.size();
//        auto cmp = [&](vector<int>& a, vector<int>& b) {
//            if (a[0] == b[0]) return a[1] < b[1];
//            else return a[0] < b[0];
//        };
//        sort(envelopes.begin(), envelopes.end(), cmp);
//
//        vector<int> dp(size+1, 1);
//        int result = 0;
//
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < i; j++) {
//                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
//                    dp[i] = max(dp[i], dp[j]+1);
//                }
//            }
//            result = max(result, dp[i]);
//        }
//
//        return result;
//    }
    /*
     排序后转化为最长下降子序列问题，dp 解决
     **/
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = (int)envelopes.size();
        if (size == 0) return 0;
        auto cmp = [&](vector<int>& a, vector<int>& b) {
            return a[0] != b [0] ? a[0] < b[0] : a[1] > b[1];
            
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        
//        vector<int> dp(size, 1);
//        int result = 0;
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < i; j++) {
//                if (envelopes[i][1] > envelopes[j][1]) dp[i] = max(dp[i], dp[j]+1);
//            }
//            result = max(result, dp[i]);
//        }
//        return result;
        vector<int> height;
        for (const vector<int> &e : envelopes) height.push_back(e[1]);
        return lengthOfLIS(height);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int size = (int)nums.size();
        
        vector<int> top(size, 0);
        int piles = 0;
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            int begin, end;
  
            begin = 0;
            end = piles;
            while (begin < end) {
                int mid = begin + (end-begin) / 2;
                if (top[mid] >= curr) end = mid;
                else begin = mid + 1;
            }
            if (begin == piles) piles++;
            top[begin] = curr;
        }
        return piles;
    }
    
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> envelopes = {
        {4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}
    };
    Solution s;
    int result = s.maxEnvelopes(envelopes);
    return 0;
}
