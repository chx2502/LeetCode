//
//  main.cpp
//  LeetCode_429_N叉树的层序遍历
//
//  Created by 成鑫 on 2019/8/4.
//  Copyright © 2019 成鑫. All rights reserved.
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
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<Node*> q1, q2;
        q2.push(root);
        do {
            while (!q1.empty()) {
                Node *node = q1.front();
                q1.pop();
                q2.push(node);
            }
            vector<int> tmp;
            while (!q2.empty()) {
                Node *node = q2.front();
                q2.pop();
                for (auto element : node->children)
                    q1.push(element);
                tmp.push_back(node->val);
            }
            ret.push_back(tmp);
        } while(!q1.empty());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
