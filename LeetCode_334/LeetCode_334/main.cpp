//
//  main.cpp
//  LeetCode_334
//
//  Created by chx on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /*
     O(n^2) 常规递增子序列解法
      **/
//    bool increasingTriplet(vector<int>& nums) {
//        int size = (int)nums.size();
//
//        vector<int> dp(size, 1);
//
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < i; j++) {
//                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
//                if (dp[i] == 3) return true;
//            }
//        }
//        return false;
//    }
    /*
     O(n)时间 O(1)空间解法
     **/
    bool increasingTriplet(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 3) return false;
        
        int small, mid;
        small = mid = INT_MAX;
        
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            if (curr <= small) small = curr;
            else if (curr < mid) mid = curr;
            if (curr > mid) return true;
        }
        return false;
    }

    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << 0x80000000-1 << " " << INT_MAX << " " << int(pow(2, 31))-1 << endl;
    return 0;
}
