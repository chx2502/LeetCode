//
//  main.cpp
//  LeetCode_19_删除链表的倒数第N个节点
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front, *back, *tmp;
        front = back = head;
        tmp = NULL;
        for (int i = 0; i < n; i++)
            back = back->next;
        if (back == NULL) return head->next;
        while(back != NULL) {
            tmp = front;
            front = front->next;
            back = back->next;
        }
        tmp->next = front->next;
        if (head == front) head = tmp;
        front = NULL;
        return head;
    }
};

vector<int> test_set = {1, 2, 3, 4};

int main(int argc, const char * argv[]) {
    ListNode *list = new ListNode(test_set[0]);
    ListNode *tail = list;
    for (int i = 1; i < test_set.size(); i++) {
        ListNode *node = new ListNode(test_set[i]);
        tail->next = node;
        tail = tail->next;
    }
        
    Solution s;
    s.removeNthFromEnd(list, 2);
    return 0;
}
