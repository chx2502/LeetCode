//
//  main.c
//  LeetCode_009_回文数
//
//  Created by 成鑫 on 2019/3/19.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>

typedef int bool;

#define false 0
#define true 1

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int array[11] = {0};
    int i = 0;
    while(x > 0) {
        array[i++] = x % 10;
        x /= 10;
    }
    array[i--] = -1;
    int *p, *q;
    p = array;
    q = &array[i];
    while(p < q) {
        if (*p != *q) return false;
        p++;
        q--;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int x;
    scanf("%d", &x);
    if (isPalindrome(x)) printf("ture\n");
    else printf("false\n");
    return 0;
}
