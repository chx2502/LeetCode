//
//  main.cpp
//  LeetCode_109_有序链表转换二叉搜索树
//
//  Created by chx on 2019/12/5.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    /*
     核心思路：
     给出的单链表已经有序，则树根为中间元素
     中间元素两端的链表分别为左右子树
     递归地生成左右子树树根
     **/
//    TreeNode* helper(ListNode* head, ListNode *tail) {
//        if (!head) return NULL;
//        ListNode *fast, *slow, *slow_pre;
//        fast = slow = slow_pre = head;
//        while (fast != tail) {
//            fast = fast->next;
//            if (fast != tail) fast = fast->next;
//            slow_pre = slow;
//            slow = slow->next;
//        }
//        TreeNode *root = new TreeNode(slow->val);
//        if (head != slow) root->left = helper(head, slow_pre);
//        if (tail != slow) root->right = helper(slow->next, tail);
//        return root;
//    }
    
    /*
     解法 2：
     用快慢指针每次找链表的中间点，
     以中间点为中心，分出 2 个链表作为左右子树
     分别生成左右子树
     当 head == mid 时要结束寻找
     **/
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
//        ListNode *tail = head;
//        while (tail->next != nullptr)
//            tail = tail->next;
//        return helper(head, tail);
        ListNode *slow, *fast, *pre;
        pre = slow = fast = head;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        if (head != slow) root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
