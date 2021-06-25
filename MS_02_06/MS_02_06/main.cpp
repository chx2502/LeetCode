//
//  main.cpp
//  MS_02_06
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
    ListNode* reverseList(ListNode *head) {
        if (!head) return nullptr;
        ListNode *dummy = new ListNode(-1);
        while (head) {
            ListNode *temp = head;
            head = head->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast, *slow;
        fast = slow = dummy;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverseList(slow->next);
        ListNode *p, *q;
        p = dummy->next;
        q = slow->next;
        while (p != slow->next && q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
