//
//  main.c
//  LeetCode_349_两个数组的交集
//
//  Created by 成鑫 on 2019/3/24.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUM 100001

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ret_array = (int *)malloc(sizeof(int) * nums1Size);
    int count = 0;
    char array[MAXNUM];
    memset(array, 0, MAXNUM);
    for (int i = 0; i < nums1Size; i++) {
        int idx = nums1[i];
        array[idx] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        int idx = nums2[i];
        if (array[idx] > 0) {
            ret_array[count++] = idx;
            array[idx] = 0;
        }
    }
    *returnSize = count;
    return ret_array;
}

int main(int argc, const char * argv[]) {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    int *result, *returnSize;
    result = intersection(nums1, 4, nums2, 2, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("%d,", result[i]);
    }
    return 0;
}
