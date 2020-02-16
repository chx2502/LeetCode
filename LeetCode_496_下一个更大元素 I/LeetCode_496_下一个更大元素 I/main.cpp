//
//  main.cpp
//  LeetCode_496_下一个更大元素 I
//
//  Created by chx on 2020/2/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int length = (int)nums2.size();
        int N = (int)nums1.size();
        vector<int> result;
        for (int i = 0; i < N; i++) {
            bool flag = false;
            int j = 0;
            while (nums2[j] != nums1[i]) j++;
            while (++j < length) {
                if (nums2[j] > nums1[i]) {
                    result.push_back(nums2[j]);
                    flag = true;
                    break;
                }
            }
            if (!flag) result.push_back(-1);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
