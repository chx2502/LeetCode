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
     缺点：代码写得稀碎
     待改进：加入哨兵结点会简化许多
     **/
    ListNode* insert(ListNode* head, ListNode* node) {
        if (!head) return node;
        
        if (!head->next) {
            if (head->val < node->val) {
                head->next = node;
                return head;
            } else {
                node->next = head;
                return node;
            }
        }
        
        ListNode *p = head;
        ListNode *pre = NULL;
        
        while(p->val < node->val) {
            pre = p;
            p = p->next;
            if (!p) break;
        }
        if (!pre) {
            node->next = head;
            head = node;
        } else {
            pre->next = node;
            node->next = p;
        }
        return head;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *result = NULL;
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = NULL;
            result = insert(result, node);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 4};
    ListNode *head = s.createList(nums);
    ListNode *result = s.insertionSortList(head);
    return 0;
}
