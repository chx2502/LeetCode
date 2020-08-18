//
//  main.cpp
//  LeetCode_160
//
//  Created by chx on 2020/8/12.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *p, *q;
        int m, n;
        
        p = headA;
        q = headB;
        m = n = 0;

        while (p->next) {
            p = p->next;
            m++;
        }
        while (q->next) {
            q = q->next;
            n++;
        }
        if (p != q) return nullptr;
        
        if (m > n) {
            p = headB;
            q = headA;
        } else {
            p = headA;
            q = headB;
        }
        int c = abs(m-n);
        while (c--) q = q->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
