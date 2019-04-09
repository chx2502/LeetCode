//
//  main.c
//  LeetCode_007_整数反转
//
//  Created by 成鑫 on 2019/3/19.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int reverse(int x) {
    long int a = fabs(x);
    long int max = pow(2, 31);
    long int sum = 0;
    while(a != 0) {
        sum = sum * 10 + a % 10;
        a /= 10;
        if(sum >= max) {
            sum = 0;
            break;
        }
    }
    if (x < 0) sum *= -1;
    return (int)sum;
}

int main(int argc, const char * argv[]) {
    int x;
    scanf("%d", &x);
    printf("%d\n", reverse(x));
    return 0;
}
