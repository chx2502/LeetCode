//
//  main.cpp
//  MS_02_08
//
//  Created by chx on 2021/4/27.
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *slow, *fast;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        slow = fast = dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;
        ListNode *p = dummy;
        while (p != fast) {
            p = p->next;
            fast = fast->next;
        }
        delete dummy;
        return fast;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
