//
//  main.cpp
//  LeetCode_445_两数相加 II
//
//  Created by chx on 2020/4/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     不修改原链表解法
     可优化的地方：将两链表补为一样长，简化处理
     **/
    
    void insert(ListNode *list, ListNode *node) {
        node->next = list->next;
        list->next = node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode *result = new ListNode(-1);
        
        ListNode *p, *q;
        p = l1;
        q = l2;
        
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        
        while (p) {
            stk1.push(p);
            p = p->next;
        }
        while (q) {
            stk2.push(q);
            q = q->next;
        }
        bool overflow = false;
        while (!stk1.empty() && !stk2.empty()) {
            int sum = stk1.top()->val + stk2.top()->val;
            stk1.pop();
            stk2.pop();
            if (overflow) sum += 1;
            if (sum >= 10) {
                sum %= 10;
                overflow = true;
            } else overflow = false;
            ListNode *node = new ListNode(sum);
            insert(result, node);
        }
        while (!stk1.empty()) {
            ListNode *node = stk1.top();
            stk1.pop();
            if (overflow) node->val += 1;
            if (node->val >= 10) {
                node->val %= 10;
                overflow = true;
            } else overflow = false;
            insert(result, node);
        }
        while (!stk2.empty()) {
            ListNode *node = stk2.top();
            stk2.pop();
            if (overflow) {
                node->val += 1;
                if (node->val >= 10) {
                    node->val %= 10;
                } else overflow = false;
            }
            insert(result, node);
        }
        if (overflow) insert(result, new ListNode(1));
        
        return result->next;
    }
    
    /*
     基础解法
     **/
    
//    ListNode* reverseList(ListNode *list) {
//        if (!list) return NULL;
//        ListNode dummy(-1);
//        ListNode *p = list;
//        while (p) {
//            ListNode *temp = p->next;
//            p->next = dummy.next;
//            dummy.next = p;
//            p = temp;
//        }
//        return dummy.next;
//    }
//
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        if (l1 == nullptr) return l2;
//        if (l2 == nullptr) return l1;
//
//        l1 = reverseList(l1);
//        l2 = reverseList(l2);
//        ListNode *p, *q, *tail;
//        p = l1;
//        q = l2;
//        tail = l1;
//        while (p != nullptr && q != nullptr) {
//            int sum = p->val + q->val;
//            if (sum >= 10) {
//                sum %= 10;
//                if (p->next) p->next->val += 1;
//                else p->next = new ListNode(1);
//            }
//            p->val = sum;
//            if (p->next == nullptr) tail = p;
//            p = p->next;
//            q = q->next;
//        }
//        if (q != nullptr) tail->next = q;
//        if (p != nullptr) {
//            while (p) {
//                if (p->val >= 10) {
//                    p->val %= 10;
//                    if (p->next) p->next->val += 1;
//                    else p->next = new ListNode(1);
//                }
//                p = p->next;
//            }
//        }
//        l1 = reverseList(l1);
//        return l1;
//    }
    
    ListNode* createList(vector<int>& nums) {
        int length = (int)nums.size();
        ListNode *dummy = new ListNode(INT_MIN);
        if (!length) return dummy;
        for (int i = length-1; i >= 0; i--) {
            listInsert(dummy, new ListNode(nums[i]));
        }
        return dummy->next;
    }

    void listInsert(ListNode* dummy, ListNode* node) {
        ListNode *temp = dummy->next;
        dummy->next = node;
        node->next = temp;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {9, 9};
    vector<int> nums2 = {9};
    ListNode *l1 = s.createList(nums1);
    ListNode *l2 = s.createList(nums2);
    ListNode *result = s.addTwoNumbers(l1, l2);
    return 0;
}
