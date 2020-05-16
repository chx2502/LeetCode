//
//  main.cpp
//  LeetCode_25
//
//  Created by chx on 2020/5/16.
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
    
    ListNode *reverse(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = head;
        while (p) {
            ListNode *temp = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = temp;
        }
        return dummy->next;
    }
    
    void merge(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) return;
        ListNode *p = l1;
        while (p->next) p = p->next;
        p->next = l2;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        vector<ListNode*> listArray;
        ListNode *p = head;
        bool flag = true;
        while (p) {
            listArray.push_back(p);
            int count = 0;
            ListNode *pre = p;
            while (p && count < k) {
                pre = p;
                p = p->next;
                count += 1;
            }
            if (count < k) flag = false;
            pre->next = NULL;
        }
        for (auto &list : listArray) list = reverse(list);
        if (!flag) listArray.back() = reverse(listArray.back());
        for (int i = 1; i < listArray.size(); ++i) merge(listArray[0], listArray[i]);
        return listArray[0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
