//
//  main.cpp
//  LeetCode_234
//
//  Created by chx on 2020/9/23.
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
    
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = head;
        while(p) {
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = head;
        ListNode *q = reverseList(slow);
        while (p && q) {
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
