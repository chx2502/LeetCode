//
//  main.cpp
//  LeetCode_148_排序链表
//
//  Created by chx on 2020/2/20.
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
    ListNode* createList(vector<int>& nums) {
        int length = (int)nums.size();
        ListNode *dummy = new ListNode(INT_MIN);
        if (!length) return dummy;
        for (int i = length-1; i >= 0; i--) {
            insert(dummy, new ListNode(nums[i]));
        }
        return dummy->next;
    }
    
    void insert(ListNode* dummy, ListNode* node) {
        ListNode *temp = dummy->next;
        dummy->next = node;
        node->next = temp;
    }
    ListNode* merge(ListNode* first, ListNode* second) {
        if (first == second) return first;
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *p, *q, *tail;
        p = first;
        q = second;
        tail = dummy;
        while (p && q) {
            if (p->val < q->val) {
                tail->next = p;
                tail = tail->next;
                p = p->next;
                tail->next = NULL;
            } else {
                tail->next = q;
                tail = tail->next;
                q = q->next;
                tail->next = NULL;
            }
        }
        while (p) {
            tail->next = p;
            tail = tail->next;
            p = p->next;
            tail->next = NULL;
        }
        while (q) {
            tail->next = q;
            tail = tail->next;
            q = q->next;
            tail->next = NULL;
        }
        return dummy->next;
    }
    ListNode* splitAndSort(ListNode* head) {
        if (!head->next) return head;
        ListNode *slow, *fast;
        slow = fast = head;
        while (slow && fast) {
            if (!fast->next) break;
            fast = fast->next->next;
            if (fast) slow = slow->next;
        }
        ListNode *left = head;
        ListNode *right = slow->next;
        slow->next = NULL;
        
        return merge(splitAndSort(left), splitAndSort(right));
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        return splitAndSort(head);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 2, 1, 3};
    ListNode *list = s.createList(nums);
    ListNode *result = s.sortList(list);
    return 0;
}
