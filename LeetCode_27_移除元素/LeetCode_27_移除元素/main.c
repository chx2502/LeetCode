//
//  main.c
//  LeetCode_27_移除元素
//
//  Created by 成鑫 on 2019/3/24.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val)
            nums[size++] = nums[i];
    }
    return size;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
