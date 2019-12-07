//
//  main.cpp
//  LeetCode_589_N叉树的前序遍历
//
//  Created by chx on 2019/12/4.
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
     栈实现，子节点逆序入栈
     **/
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if (!root) return ret;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *temp = stk.top();
            stk.pop();
            if (!temp->children.empty()) {
                int length = (int)temp->children.size();
                while(length--) stk.push(temp->children[length]);
            }
            ret.push_back(temp->val);
        }
        return ret;
    }
    /*
     下面写错了，写成了层序遍历
     **/
    vector<int> levelorder(Node* root) {
        vector<int> ret;
        if (!root) return ret;
        queue<Node*> nq;
        nq.push(root);
        while(!nq.empty()) {
            Node *temp = nq.front();
            nq.pop();
            if (!temp->children.empty()) {
                for (auto &child : temp->children) {
                    nq.push(child);
                }
            }
            ret.push_back(temp->val);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
