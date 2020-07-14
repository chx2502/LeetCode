//
//  main.cpp
//  LeetCode_92
//
//  Created by chx on 2020/7/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode *head, ListNode *end) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = head;
        while (p && p != end) {
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
            if (temp->next == nullptr) temp->next = end;
        }
        return dummy->next;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        if (m == n) return head;
        int count = 1;
        ListNode *p, *q, *pre;
        pre = p = q = head;
        while (count < m && p) {
            pre = p;
            p = p->next;
            count++;
        }
        q = p;
        while (count <= n && q) {
            q = q->next;
            count++;
        }
        if (pre != p) pre->next = reverse(p, q);
        else head = reverse(p, q);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
