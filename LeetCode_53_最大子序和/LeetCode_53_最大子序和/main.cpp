//
//  main.cpp
//  LeetCode_53_最大子序和
//
//  Created by 成鑫 on 2019/6/30.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

#define N_INF -2147483648

using namespace std;

class Solution {
public:
    int max_2(int a, int b) {
        return a > b ? a : b;
    }
    int max_3(int a, int b, int c) {
        return max_2(max_2(a, b), c);
    }
    int maxCrossSub(int low, int high, int mid, vector<int>& nums) {
        int left_sum, right_sum, left, right, sum;
        left_sum = right_sum = N_INF;
        
        left = mid;
        sum = 0;
        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            if (left_sum < sum) {
                left_sum = sum;
                left = i;
            }
        }
        
        right = mid+1;
        sum = 0;
        for (int i = mid+1; i <= high; i++) {
            sum += nums[i];
            if (right_sum < sum) {
                right_sum = sum;
                right = i;
            }
        }
        return left_sum + right_sum;
    }
    
    int maxSub(int low, int high, vector<int>& nums) {
        if (high == low) return nums[low];
        else {
            int mid = (low + high) / 2;
            int left_sum, right_sum, cross_sum;
            left_sum = maxSub(low, mid, nums);
            right_sum = maxSub(mid+1, high, nums);
            cross_sum = maxCrossSub(low, high, mid, nums);
            return max_3(left_sum, right_sum, cross_sum);
        }
    }
    
    int maxSubArray(vector<int>& nums) {
        int size = (int)nums.size();
        return maxSub(0, size-1, nums);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
