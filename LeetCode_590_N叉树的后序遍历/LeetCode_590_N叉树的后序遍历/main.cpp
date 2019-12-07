//
//  main.cpp
//  LeetCode_590_N叉树的后序遍历
//
//  Created by chx on 2019/12/3.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    /*
     递归解法
     **/
//    vector<int> ret;
//    vector<int> postorder(Node* root) {
//        if (!root) return ret;
//        if (!root->children.empty()) {
//            for (auto &child : root->children)
//                postorder(child);
//        }
//        ret.push_back(root->val);
//        return ret;
//    }
    /*
     非递归解法：
     两个栈，一个用来收纳还没被遍历的节点，另一个用来保存遍历结果。
     一个栈，弹出的节点用头插法插入 ret 数组中
     **/
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (!root) return ret;
    
        stack<Node*> source;
//        stack<Node*> target;
        source.push(root);
        while (!source.empty()) {
            Node *node = source.top();
            source.pop();
        
            if (!node->children.empty()) {
                for (auto &child : node->children) {
                    source.push(child);
                }
            }
            ret.push_back(node->val);
        }
//        while (!target.empty()) {
//            ret.push_back(target.top()->val);
//            target.pop();
//        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> nums = {{1}, {3, 2, 4}, {5, 6}};
    
    return 0;
}
