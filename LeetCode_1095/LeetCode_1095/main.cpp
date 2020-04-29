//
//  main.cpp
//  LeetCode_1095
//
//  Created by chx on 2020/4/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>

using namespace std;

class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:

    int getSummitIndex(MountainArray &mountainArr, int begin, int end) {
        if (begin > end) return -1;
        if (begin == end) return begin;
        int mid = (begin + end) / 2;
        int curr = mountainArr.get(mid);
        if (mountainArr.get(mid-1) > curr) return getSummitIndex(mountainArr, begin, mid);
        if (mountainArr.get(mid+1) > curr) return getSummitIndex(mountainArr, mid, end);
        return mid;
    }

    int bSearch(MountainArray &mountainArr, int begin, int end, int target, int left) {
        int result = -1;
        if (begin > end) return result;
        int mid = (begin + end) / 2;
        int curr = mountainArr.get(mid);
    
        if (curr == target) result = mid;
        else if (left) {
            if (curr > target) result = bSearch(mountainArr, begin, mid-1, target, left);
            if (curr < target) result = bSearch(mountainArr, mid+1, end, target, left);
        } else {
            if (curr < target) result = bSearch(mountainArr, begin, mid-1, target, left);
            if (curr > target) result = bSearch(mountainArr, mid+1, end, target, left);
        }
        while(result >= 1 && mountainArr.get(result-1) == target) {
            result -= 1;
        }
        return result;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int begin = 0;
        int end = length-1;
        int summitIndex = getSummitIndex(mountainArr, begin, end);
        int leftIndex = bSearch(mountainArr, begin, summitIndex, target, 1);
        if (leftIndex != -1) return leftIndex;
        else return bSearch(mountainArr, summitIndex, end, target, 0);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
