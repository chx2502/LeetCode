//
//  main.cpp
//  LeetCode_61_旋转链表
//
//  Created by 成鑫 on 2019/7/17.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 核心思路：
 算出链表长度 size，从而处理掉 k >= size 的情况，缺点是遍历一遍 list 会增加耗时
 然后求解 list 向右循环位移 k % size 位，用快慢指针 first, second
 first 找到倒数第 k 个元素的前一个元素，second 指向末尾元素
 位移后的第一个元素 res 即为 first->next，末尾元素为 first，连接点为 second
 */
class Solution {
public:
    int SizeofList(ListNode* list) {
        ListNode *p = list;
        int size = 0;
        while (p) {
            size++;
            p = p->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 0) return head;
        int size;
        size = SizeofList(head);
        if (k >= size) return rotateRight(head, k % size);
        ListNode *first, *second, *res;
        first = second = head;
        for (int i = 0; i < k; i++)
            second = second->next;
        while(second->next) {
            first = first->next;
            second = second->next;
        }
        res = first->next;
        second->next = head;
        first->next = NULL;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
