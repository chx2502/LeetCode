//
//  main.c
//  LeetCode_014_最长公共前缀
//
//  Created by 成鑫 on 2019/3/19.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return "";
    unsigned long minlen = strlen(strs[0]);
    int flag = 0;
    for (int i = 1; i < strsSize; i++) {
        unsigned long len = strlen(strs[i]);
        if(minlen > len)
            minlen = len;
    }
    char *result = (char *)malloc(minlen+1);
    unsigned long i;
    for (i = 0; i < minlen; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[j-1][i]) {
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    strncpy(result, strs[0], i+1);
    result[i] = '\0';
    return result;
}

int main(int argc, const char * argv[]) {
    char *strs[20] = {};
    printf("%s", longestCommonPrefix(strs, 0));
    return 0;
}
