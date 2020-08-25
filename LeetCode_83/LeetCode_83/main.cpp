//
//  main.cpp
//  LeetCode_83
//
//  Created by chx on 2020/8/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode *p, *q;
        p = q = head;
        while (p && q) {
            q = p->next;
            while(q && q->val == p->val) q = q->next;
            p->next = q;
            p = q;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
