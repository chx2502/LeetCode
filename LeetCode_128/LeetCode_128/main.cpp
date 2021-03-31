//
//  main.cpp
//  LeetCode_128
//
//  Created by chx on 2021/3/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
//    unordered_map<int, int> memory;
    unordered_set<int> numSet;
public:
//    int longestConsecutive(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 0) return 0;
//
//        vector<int> dp(size, 1);
//        sort(nums.begin(), nums.end());
//
//        int result = 1;
//        for (int i = 1; i < size; i++) {
//            if (nums[i] == nums[i-1]) dp[i] = dp[i-1];
//            if (nums[i] == nums[i-1] + 1) dp[i] = dp[i-1] + 1;
//            result = max(result, dp[i]);
//        }
//        return result;
//    }
    
    int longestConsecutive(vector<int>& nums) {
        for (const int& num : nums) numSet.insert(num);
        int result = 0;
        for (const int& num : numSet) {
            if (numSet.count(num-1) == 0) {
                int curr = num;
                int currLen = 1;
                while (numSet.count(curr+1)) {
                    curr++;
                    currLen++;
                }
                result = max(result ,currLen);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
