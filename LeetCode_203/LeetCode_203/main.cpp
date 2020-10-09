//
//  main.cpp
//  LeetCode_203
//
//  Created by chx on 2020/9/12.
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
    void deleteNext(ListNode* node) {
        node->next = node->next->next;
    }

    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        if (head->val == val) return removeElements(head->next, val);
        ListNode *p = head;
        while(p && p->next) {
            while (p->next && p->next->val == val) deleteNext(p);
            p = p->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
