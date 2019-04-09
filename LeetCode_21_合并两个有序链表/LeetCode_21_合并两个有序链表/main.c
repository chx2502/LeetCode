//
//  main.c
//  LeetCode_21_合并两个有序链表
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

struct ListNode * CreateList(int N) {
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *tail = ret;
    for (int i = 0; i < N; i++) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = NULL;
        scanf("%d", &node->val);
        tail->next = node;
        tail = node;
    }
    return ret;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1->next == NULL) return l2;
    if (l2->next == NULL) return l1;
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->next = NULL;
    struct ListNode *p, *q, *tail;
    p = l1->next;
    q = l2->next;
    tail = ret;
    while (p != NULL && q != NULL) {
        if (p->val <= q->val) {
            tail->next = p;
            p = p->next;
        } else {
            tail->next = q;
            q = q->next;
        }
        tail = tail->next;
    }
    if (p == NULL)
        tail->next = q;
    if (q == NULL)
        tail->next = p;
    return ret;
}

int main(int argc, const char * argv[]) {
    struct ListNode *l1 = CreateList(3);
    struct ListNode *l2 = CreateList(3);
    l1 = mergeTwoLists(l1, l2);
    struct ListNode *p = l1->next;
    while (p) {
        printf("%d,", p->val);
        p = p->next;
    }
    return 0;
}
