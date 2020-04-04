//
//  main.cpp
//  LeetCode_42_接雨水
//
//  Created by chx on 2020/4/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int trapOfRange(vector<int>& height, int begin, int end, int& min) {
        if (begin >= end) return 0;
        int result = 0;
        for (int i = begin+1; i < end; ++i) {
            if (height[i] < min) {
                result += min-height[i];
                height[i] = min;
            }
        }
        return result;
    }
    
    int trap(vector<int>& height) {
        int size = (int)height.size();
        if (size == 0) return 0;
        int left, right, min;
        left = 0;
        right = size-1;
        min = 0;
        
        int result = 0;
        while (left < right && left < size && right >= 0) {
            while (left < size && min >= height[left]) left++;
            while (right >= 0 && min >= height[right]) right--;
            if (left < size && right >= 0) {
                min = height[left] < height[right] ? height[left] : height[right];
                result += trapOfRange(height, left, right, min);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> height = {2, 0, 2};
    Solution s;
    int result = s.trap(height);
    return 0;
}
