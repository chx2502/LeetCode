//
//  main.cpp
//  LeetCode_82
//
//  Created by chx on 2020/9/27.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNext(ListNode* pre) {
        if (pre && pre->next) {
            pre->next = pre->next->next;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        unordered_map<int, int> node_map;
        ListNode *p = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while (p) {
            if (node_map.count(p->val)) node_map[p->val]++;
            else node_map[p->val] = 1;
            p = p->next;
        }
        p = dummy->next;
        while (p) {
            if (node_map[p->val] > 1) deleteNext(pre);
            else pre = p;
            p = p->next;
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
