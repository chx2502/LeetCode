//
//  main.cpp
//  LeetCode_169_多数元素
//
//  Created by chx on 2020/3/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    /*
     散列表法
     **/
    int majorityElement(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 1) return nums[0];
        size /= 2;
        map<int, int> M;
        for (auto &num : nums) {
            M[num]++;
            if (M[num] > size) return num;
        }
        return -1;
    }
    /*
     投票法
     **/
//    int majorityElement(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 1) return nums[0];
//
//        int count = 0;
//        int candidate = nums[0];
//        for (auto &num : nums) {
//            if (count == 0) {
//                candidate = num;
//                count = 1;
//                continue;
//            }
//            if (num == candidate) count++;
//            else count--;
//        }
//        return candidate;
//    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
