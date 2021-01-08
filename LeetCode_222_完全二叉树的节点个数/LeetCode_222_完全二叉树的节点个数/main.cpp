//
//  main.cpp
//  LeetCode_222_完全二叉树的节点个数
//
//  Created by chx on 2020/1/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
//    int countNodes(TreeNode* root) {
//        if (!root) return 0;
//        return 1 + countNodes(root->left) + countNodes(root->right);
//    }
    
    bool search(int path, TreeNode* root, int height) {
        if (!root) return false;
        int bits = 1 << (height-1);
        TreeNode *p = root;
        while(bits > 0 && p) {
            if (bits & path) p = p->right;
            else p = p->left;
            bits >>= 1;
        }
        return p != nullptr;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *p = root;
        int height = 0;
        
        while(p->left != nullptr) {
            height++;
            p = p->left;
        }
        
        int begin = 1 << height;
        int end = (1 << (height+1)) -1;
        while (begin < end) {
            int mid = begin + (end - begin+1) / 2;
            if (search(mid, root, height)) begin = mid;
            else end = mid-1;
        }
        return begin;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
