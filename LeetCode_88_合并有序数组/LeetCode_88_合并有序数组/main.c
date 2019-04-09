//
//  main.c
//  LeetCode_88_合并有序数组
//
//  Created by 成鑫 on 2019/3/25.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *array, int left, int right) {
    if (left >= right) return;
    int pivot = array[left];
    int i, j;
    i = left;
    j = right;
    while(i < j) {
        while(i < j && array[j] >= pivot) j--;
        array[i] = array[j];
        while(i < j && array[i] <= pivot) i++;
        array[j] = array[i];
    }
    array[i] = pivot;
    quick_sort(array, left, i-1);
    quick_sort(array, i+1, right);
}

void merge(int* nums1, int m, int* nums2, int n) {
    int len = m + n;
    for (int i = m; i < len; ++i)
        nums1[i] = nums2[i-m];
    quick_sort(nums1, 0, m+n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums1[] = {0,0,3,0,0,0,0,0,0};
    int nums2[] = {-1,1,1,1,2,3};
    merge(nums1, 3, nums2, 6);
    for (int i = 0; i < 9; i++) {
        printf("%d,", nums1[i]);
    }
    printf("\nHello, World!\n");
    return 0;
}
