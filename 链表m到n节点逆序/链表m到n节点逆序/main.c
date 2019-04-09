//
//  main.c
//  链表m到n节点逆序
//
//  Created by 成鑫 on 2019/3/23.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_ *next;
} ListNode;

ListNode *CreateList(int *array, int N) {
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->value = -1;
    head->next = NULL;
    ListNode *tail = head;
    for (int i = 0; i < N; i++) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->value = array[i];
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    return head;
}

ListNode *reverseList_m_n(ListNode *head, int m, int n) {
    if(head->next == NULL) return head;
    ListNode *start, *end, *p;
    int i;
    start = end = p = head;
    for (i = 0; i < m-1; i++) {
        start = start->next;
        end = end->next;
        p = p->next;
    }
    while(i++ <= n && end->next != NULL)
        end = end->next;
    p = p->next;
    start->next = NULL;
    int count = n - m + 1;
    i = 0;
    while(i++ < count) {
        ListNode *temp = p->next;
        p->next = start->next;
        start->next = p;
        p = temp;
    };
    while(start->next) start = start->next;
    start->next = end;
    return head;
}

int main(int argc, const char * argv[]) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *list = CreateList(array, 10);
    list = reverseList_m_n(list, 1, 10);
    ListNode *p = list;
    while(p->next) {
        p = p->next;
        printf("%d,", p->value);
    }
    printf("\n");
    return 0;
}
