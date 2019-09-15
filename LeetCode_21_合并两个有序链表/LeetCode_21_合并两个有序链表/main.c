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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy, *tail, *l1_ptr, *l2_ptr;
    dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    tail = dummy;
    l1_ptr = l1;
    l2_ptr = l2;
    while(l1_ptr != NULL && l2_ptr != NULL) {
        if (l1_ptr->val < l2_ptr->val) {
            tail->next = l1_ptr;
            l1_ptr = l1_ptr->next;
        } else {
            tail->next = l2_ptr;
            l2_ptr = l2_ptr->next;
        }
        tail = tail->next;
    }
    while (l1_ptr != NULL) {
        tail->next = l1_ptr;
        tail = tail->next;
        l1_ptr = l1_ptr->next;
    }
    while (l2_ptr != NULL) {
        tail->next = l2_ptr;
        tail = tail->next;
        l2_ptr = l2_ptr->next;
    }
    return dummy->next;
}

int main(int argc, const char * argv[]) {

    return 0;
}
