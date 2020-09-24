//
//  main.cpp
//  LeetCode_116
//
//  Created by chx on 2020/9/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // 层序遍历，双队列实现，按层构建链表，此解法不满足 O(1) 额外空间
//    Node* connect(Node* root) {
//        if (!root) return nullptr;
//        queue<Node*> Q1, Q2;
//        Q1.push(root);
//        while (!Q1.empty()) {
//            while(!Q1.empty()) {
//                Node *node = Q1.front();
//                Q1.pop();
//                if (node->left) Q2.push(node->left);
//                if (node->right) Q2.push(node->right);
//                if (!Q1.empty()) node->next = Q1.front();
//            }
//            while (!Q2.empty()) {
//                Q1.push(Q2.front());
//                Q2.pop();
//            }
//        }
//        return root;
//    }
    void dfs(Node* node, Node* next) {
        if (!node) return;
        node->next = next;
        dfs(node->left, node->right);
        dfs(node->right, node->next != nullptr ? node->next->left : nullptr);
    }
    Node* connect(Node* root) {
        if (!root) return nullptr;
        dfs(root, nullptr);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
