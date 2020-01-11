//
//  main.cpp
//  LeetCode_559_N叉树的最大深度
//
//  Created by chx on 2020/1/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

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
     递归解法:
     分别计算各子树的深度，取其中深度最大的 max，返回 max+1。
     **/
    int maxDepth(Node* root) {
        if (!root) return 0;
        int max = 0;
        for (auto &child : root->children) {
            int depth = maxDepth(child);
            if (max < depth) {
                max = depth;
            }
        }
        return max+1;
    }
    /*
     非递归解法：
     双队列实现层次遍历，
     队列 1 存放当前层的节点，队列 2 存放下一层节点，
     每次队列 1 为空则深度 depth 增加 1，同时将队列 2 中节点压入队列 1。
     **/
//    int maxDepth(Node* root) {
//        if (!root) return 0;
//        queue<Node*> current_level, next_level;
//        current_level.push(root);
//        int depth = 0;
//        while (!current_level.empty()) {
//            Node *temp = current_level.front();
//            for (auto &child : temp->children) {
//                next_level.push(child);
//            }
//            current_level.pop();
//            if (current_level.empty()) {
//                depth += 1;
//                while (!next_level.empty()) {
//                    current_level.push(next_level.front());
//                    next_level.pop();
//                }
//            }
//        }
//        return depth;
//    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
