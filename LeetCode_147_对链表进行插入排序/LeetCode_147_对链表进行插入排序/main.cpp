//
//  main.cpp
//  LeetCode_147_对链表进行插入排序
//
//  Created by chx on 2020/2/17.
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
        ListNode *head = NULL;
        ListNode *tail = NULL;
        for (auto num : nums) {
            ListNode *node = new ListNode(num);
            if (!head) {
                head = node;
                tail = node;
                continue;
            }
            tail->next = node;
            tail = tail->next;
        }
        return head;
    }
    /*
     核心思路：
     逐一取下待排序链表中的节点，插入新的已排序链表。
     优点：原地排序，无需额外空间
     **/

    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode dummy(-1);
        ListNode *p = head;
        while(p) {
            ListNode *temp = p;
            p = p->next;
            ListNode *pos = &dummy;
            while (pos->next) {
                if (temp->val < pos->next->val) break;
                else pos = pos->next;
            }
            temp->next = pos->next;
            pos->next = temp;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 4};
    ListNode *head = s.createList(nums);
    ListNode *result = s.insertionSortList(head);
    return 0;
}
