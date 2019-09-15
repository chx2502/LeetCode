//
//  main.cpp
//  LeetCode_24_两两交换链表中的节点
//
//  Created by 成鑫 on 2019/7/16.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 非递归解法:
 三指针分别指向 交换节点 1， 交换节点 2，下一次交换的起始节点
 头结点尾插法依次插入 节点 2， 节点 1
 单独处理剩余节点为 1 的情况
 这题代码写的比较挫
*/
class Solution {
public:
//    // 非递归解法
//    ListNode* swapPairs(ListNode* head) {
//        ListNode *first, *second, *tmp, *res, *tail;
//        bool flag = true;
//        tmp = head;
//        res = new ListNode(0);
//        tail = res;
//        while (tmp != NULL) {
//            first = tmp;
//            second = first->next;
//            if (first == NULL || second == NULL) {
//                if (first != NULL) {
//                    tail->next = first;
//                    tail = tail->next;
//                }
//                return res->next;
//            }
//            tmp = second->next;
//            tail->next = second;
//            second->next = first;
//            tail = first;
//            tail->next = NULL;
//            if (flag) {
//                head = second;
//                flag = false;
//            }
//        }
//        return res->next;
//    }
    
    // 递归解法
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};

vector<int> test_set = {1};

int main(int argc, const char * argv[]) {
    ListNode *list = new ListNode(test_set[0]);
    ListNode *tail = list;
    for (int i = 1; i < test_set.size(); i++) {
        ListNode *node = new ListNode(test_set[i]);
        tail->next = node;
        tail = tail->next;
    }
    Solution s;
    ListNode *res = s.swapPairs(list);
    return 0;
}
