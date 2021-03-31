//
//  main.cpp
//  LeetCode_23_合并K个排序链表
//
//  Created by 成鑫 on 2019/7/17.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    /*
     方法 2：
     将所有节点放入一个最小堆，然后全部取出来生成新链表
     **/
    ListNode* mergeByHeap(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1);
        auto node_cmp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(node_cmp)> pq(node_cmp);
        
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i]) pq.push(lists[i]);
        
        ListNode *tail = dummy;
        while (!pq.empty()) {
            ListNode *smallest = pq.top();
            pq.pop();
            ListNode *temp = smallest->next;
            tail->next = smallest;
            tail = tail->next;
            smallest->next = nullptr;
            if (temp) pq.push(temp);
        }
        return dummy->next;
    }
    
    
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
    
    /*
    将 lists 划分为 2 部分，分别合并，递归求解，问题转化为进行 logN 次的“ 2 个有序链表合并 ”
    时间复杂度 O(kNlogk), 空间复杂度 O(k)
    */
    ListNode *merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = (left + right) / 2;
        return mergeTwoList(merge(lists, left, mid), merge(lists, mid+1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int size = (int)lists.size();
        if (size == 0) return NULL;
//        return merge(lists, 0, size-1);
        return mergeByHeap(lists);
    }
};

vector< vector<int> > test_set = {
    {1, 4, 5},
    {1, 3, 4},
    {2, 6}
};


ListNode* solve(ListNode* head) {
    if (!head) return nullptr;
    
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    
    ListNode *p = head;
    while (p) {
        pq.push(p);
        p = p->next;
    }
    ListNode *dummy = new ListNode(-1);
    while (!pq.empty()) {
        ListNode *node = pq.top();
        pq.pop();
        node->next = dummy->next;
        dummy->next = node;
    }
    ListNode *result = dummy->next;
    delete dummy;
    return result;
}


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

int minK(vector<vector<int>>& matrix, vector<int> &P, int k) {
    int size = (int)matrix.size();
    vector<int> pointers(size, 0);
    int count = 0;
    set<int> selected;
    for (auto &row : P) {
        selected.insert(row);
    }
    
    int result = INT_MAX;
    while (count < k) {
        int min = INT_MAX;
        int shouldMove = -1;
        for (int i = 0; i < size; i++) {
            if (selected.count(i) == 0 || pointers[i] == matrix[i].size()) continue;
            int curr = matrix[i][pointers[i]];
            if (curr < min) {
                min = curr;
                shouldMove = i;
            }
        }
        result = min;
        pointers[shouldMove]++;
        count++;
    }
    return result;
}


int main(int argc, const char * argv[]) {
//    vector< vector<int> > test_set = {
//        {1, 4, 5},
//        {1, 3, 4},
//        {2, 6}
//    };
//    vector<ListNode*> lists = CreateLists(test_set);
    Solution s;
//    ListNode *result = s.mergeKLists(lists);
    vector<int> ls = { 4, 1, 3, 2 };
    ListNode *l = BuildList(ls);
    ListNode *res = solve(l);
    
    vector<vector<int>> tt = {
        {1, 2, 3,}, {6, 9, 10}, {12, 11, 4}
    };
    for (auto &arr : tt) sort(arr.begin(), arr.end());
    vector<int> P = {1, 2};
    int res2 = minK(tt, P, 4);
    return 0;
}
