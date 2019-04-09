//
//  main.c
//  LeetCode_83_删除排序链表中的重复元素
//
//  Created by 成鑫 on 2019/3/23.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * CreateList(int *array, int N) {
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tail = ret;
    for (int i = 0; i < N; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = NULL;
        node->val = array[i];
        tail->next = node;
        tail = node;
    }
    return ret;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p = head;
    while(p && p->next) {
        if (p->val == p->next->val) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    int array[5] = {1, 1, 2, 3, 3};
    struct ListNode *list = CreateList(array, 5);
    list = deleteDuplicates(list);
    return 0;
}
