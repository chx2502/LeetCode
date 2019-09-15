//
//  main.cpp
//  LeetCode_002_两数相加
//
//  Created by 成鑫 on 2019/4/17.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret, *tail;
        ListNode *p, *q;
        int flag = 1;
        p = l1;
        q = l2;
        while(p || q) {
            int m, n;
            if (p){
                m = p->val;
                p = p->next;
            } else m = 0;
            if (q) {
                n = q->val;
                q = q->next;
            } else n = 0;
            
            int x = m + n;
            ListNode *node = new ListNode(x);
            if (flag) {
                ret = node;
                tail = node;
                flag = 0;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
        p = ret;
        while(p) {
            if (p->val >= 10) {
                if (p->next) p->next->val += 1;
                else {
                    ListNode *node = new ListNode(1);
                    p->next = node;
                }
                p->val %= 10;
            }
            p = p->next;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
