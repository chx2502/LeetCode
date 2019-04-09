//
//  main.c
//  LeetCode_26_删除排序数组中的重复项
//
//  Created by 成鑫 on 2019/3/23.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int i = 0;
    for(int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}

int main(int argc, const char * argv[]) {
    int array[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    removeDuplicates(array, 10);
    return 0;
}
