//
//  main.cpp
//  LeetCode_206_反转链表
//
//  Created by chx on 2020/1/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *p = head->next;
        head->next = NULL;
        while (p) {
            ListNode *temp = head;
            head = p;
            p = p->next;
            head->next = temp;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
