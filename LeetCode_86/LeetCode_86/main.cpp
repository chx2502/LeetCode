//
//  main.cpp
//  LeetCode_86
//
//  Created by chx on 2020/9/24.
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
    void deleteNext(ListNode* pre) {
        if (!pre->next) return;
        ListNode *temp = pre->next->next;
        pre->next = temp;
        return;
    }
    
//    void insert(ListNode* tail, ListNode* node) {
//        tail->next = node;
//        tail = tail->next;
//        node->next = nullptr;
//    }
    
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode *res = new ListNode(-1);
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = nullptr;
        ListNode *pre = dummy;
        ListNode *p = head;
        dummy->next = head;
        while(p) {
            if (p->val < x) {
                ListNode *temp = p;
                p = p->next;
                deleteNext(pre);
                temp->next = NULL;
                if (tail) {
                    tail->next = temp;
                    tail = tail->next;
                } else {
                    res->next = temp;
                    tail = temp;
                }
            } else {
                pre = p;
                p = p->next;
            }
        }
        tail->next = dummy->next;
        return res->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
