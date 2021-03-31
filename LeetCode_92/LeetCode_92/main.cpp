//
//  main.cpp
//  LeetCode_92
//
//  Created by chx on 2020/7/14.
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
    ListNode* reverse(ListNode *head, ListNode *end) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = head;
        while (p && p != end) {
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
            if (temp->next == nullptr) temp->next = end;
        }
        return dummy->next;
    }
    
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        if (!head) return NULL;
//        if (m == n) return head;
//        int count = 1;
//        ListNode *p, *q, *pre;
//        pre = p = q = head;
//        while (count < m && p) {
//            pre = p;
//            p = p->next;
//            count++;
//        }
//        q = p;
//        while (count <= n && q) {
//            q = q->next;
//            count++;
//        }
//        if (pre != p) pre->next = reverse(p, q);
//        else head = reverse(p, q);
//        return head;
//    }
    
    pair<ListNode*, ListNode*> reverseList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = head;
        while (p) {
            ListNode *temp = p;
            p = p->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        ListNode *result = dummy->next;
        delete dummy;
        return {result, head};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p, *q;
        p = q = dummy;
        int count = 0;
        while (count < right) {
            if (count < left-1) p = p->next;
            q = q->next;
            count++;
        }
        ListNode *remain = q->next;
        q->next = nullptr;
        pair<ListNode*, ListNode*> newList = reverseList(p->next);
        p->next = newList.first;
        q = newList.second;
        q->next = remain;
        return dummy->next;
    }
    int binarySearch(int left, int right, int* arr, int target) {
        int mid = -1;
        while(left <= right) {
            mid = left + right;
            int curr = arr[mid];
            if (curr == target) return mid;
            if (curr > target) {
                right = mid-1;
            }
            if (curr < target) {
                left = mid+1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {1, 2, 3, 4, 5, 7};
    Solution s;
    int result = s.binarySearch(0, 5, a, 3);
    return 0;
}
