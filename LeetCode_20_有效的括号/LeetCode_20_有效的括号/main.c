//
//  main.c
//  LeetCode_20_有效的括号
//
//  Created by 成鑫 on 2019/3/23.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define false 0
#define true 1
#define maxCapacity 100001
typedef int bool;

typedef struct stack_ {
    int array[maxCapacity];
    int top;
} Stack;

Stack *myStack;

void initStack(Stack *s) {
    s = (Stack *)malloc(sizeof(Stack));
    for (int i = ;; <#increment#>) {
        <#statements#>
    }
}

int push(int x) {
    
}

bool isValid(char* s) {
    int len = (int)strlen(s);
    if (len == 0) return false;
    if (len % 2 != 0) return false;
    int flag = 0;
    for (int i = 0; i < len-1; i++) {
        if (!flag) {
            if (s[i] < s[i+1])
                flag = 1;
        } else {
            if (s[i] >= s[i+1]) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *s = "()[]{}";
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++)
        printf("%c=%d\n", s[i], s[i]);
    return 0;
}
