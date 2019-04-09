//
//  main.c
//  LeetCode_242_有效的字母异位词
//
//  Created by 成鑫 on 2019/3/24.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef int bool;

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;
    char *p;
    int array[2][256];
    for (int i = 0 ; i < 2; i++) {
        for (int j = 0; j < 256; j++)
            array[i][j] = 0;
    }
    p = s;
    while(*p != '\0') {
        int idx = *p;
        array[0][idx] += 1;
        p++;
    }
    p = t;
    while(*p != '\0') {
        int idx = *p;
        array[1][idx] += 1;
        p++;
    }
    p = s;
    while(*p != '\0') {
        int idx = *p;
        if (array[0][idx] != array[1][idx])
            return false;
        else p++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    char *s = "anagram";
    char *t = "nagaram";
    int result = isAnagram(s, t);
    printf("%d\n", result);
    return 0;
}
