//
//  main.cpp
//  LeeCode_303_区域和检索-数组不可变
//
//  Created by chx on 2019/12/12.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> array;
    int size;
    /*
     常规写法
     **/
//    NumArray(vector<int>& nums) {
//        array = nums;
//    }
//
//    int sumRange(int i, int j) {
//        int sum = 0;
//        while(i <= j) {
//            sum += array[i];
//            i++;
//        }
//        return sum;
//    }
    NumArray(vector<int>& nums) {
        array = nums;
        size = (int)nums.size();
        for (int i = 1; i < size; ++i) {
            array[i] += array[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if (i > j) return 0;
        if (i == 0) return array[j];
        if (i == j) return array[i] - array[i-1];
        else return array[j] - array[i-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    int result = obj->sumRange(2, 5);
    return 0;
}
