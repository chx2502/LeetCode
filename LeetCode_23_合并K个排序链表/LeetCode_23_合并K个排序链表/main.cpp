//
//  main.cpp
//  LeetCode_23_合并K个排序链表
//
//  Created by 成鑫 on 2019/7/17.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
/*
 将 lists 划分为 2 部分，分别合并，递归求解，问题转化为进行 logN 次的“ 2 个有序链表合并 ”
 时间复杂度 O(NLogN), 空间复杂度 O(N)
 */
class Solution {
public:
    ListNode* mergeTwoList(ListNode *a, ListNode *b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        ListNode *l1 = a;
        ListNode *l2 = b;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while(l1 != NULL || l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
            if (l1 == NULL)
                while(l2 != NULL) {
                    tail->next = l2;
                    tail = tail->next;
                    l2 = l2->next;
                }
            if (l2 == NULL)
                while(l1 != NULL) {
                    tail->next = l1;
                    tail = tail->next;
                    l1 = l1->next;
                }
        }
        return dummy->next;
    }
    ListNode *merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = (left + right) / 2;
        return mergeTwoList(merge(lists, left, mid), merge(lists, mid+1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int size = (int)lists.size();
        if (size == 0) return NULL;
        return merge(lists, 0, size-1);
    }
};

vector< vector<int> > test_set = {
    {1, 4, 5},
    {1, 3, 4},
    {2, 6}
};

ListNode* BuildList(vector<int> array_1d) {
    ListNode *dummy, *tail;
    dummy = new ListNode(-666);
    tail = dummy;
    const int size = (int)array_1d.size();
    for (int i = 0; i < size; i++) {
        ListNode *node = new ListNode(array_1d[i]);
        tail->next = node;
        tail = tail->next;
    }
    return dummy->next;
}

vector<ListNode*> CreateLists(vector< vector<int> > array_2d) {
    vector<ListNode*> res;
    const unsigned long size = array_2d.size();
    for (int i = 0; i < size; i++) {
        ListNode *list = BuildList(array_2d[i]);
        res.push_back(list);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<ListNode*> lists = CreateLists(test_set);
    Solution s;
    ListNode *result = s.mergeKLists(lists);
    return 0;
}
