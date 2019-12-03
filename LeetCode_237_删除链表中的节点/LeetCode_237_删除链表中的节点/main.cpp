//
//  main.cpp
//  LeetCode_237_删除链表中的节点
//
//  Created by chx on 2019/11/7.
//  Copyright © 2019 成鑫. All rights reserved.
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
    /*
     思路：修改当前节点值为下一节点值，跳过下一节点。
     */
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = temp->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
