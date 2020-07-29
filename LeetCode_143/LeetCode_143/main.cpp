//
//  main.cpp
//  LeetCode_143
//
//  Created by chx on 2020/7/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        ListNode *dummy = new ListNode();
        ListNode *p = head;
        while(p) {
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (l1 || l2) {
            if (l1) {
                ListNode *temp = l1;
                l1 = l1->next;
                temp->next = nullptr;
                tail->next = temp;
                tail = tail->next;
            }
            if (l2) {
                ListNode *temp = l2;
                l2 = l2->next;
                temp->next = nullptr;
                tail->next = temp;
                tail = tail->next;
            }
        }
        return dummy->next;
    }
    
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *p, *q;
        p = q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        
        q = p->next;
        p->next = nullptr;
        q = reverse(q);
        head = merge(head, q);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
