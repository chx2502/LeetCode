//
//  main.cpp
//  Huffman
//
//  Created by chx on 2019/11/25.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    bool operator < (const TreeNode *node) {
        return this->val < node->val;
    }
    bool operator > (const TreeNode *node) {
        return this->val > node->val;
    }
}  *TreeNode_ptr, *Tree;

struct cmp {
    bool operator()(Tree t1, Tree t2) {
        return t1->val > t2->val;
    }
};

Tree Huffman(vector<int> nums) {
    priority_queue<TreeNode_ptr, vector<TreeNode_ptr>, cmp> less_heap;
    for (auto num : nums) {
        TreeNode_ptr node = new TreeNode(num);
        vector<int> a;
        less_heap.push(node);
    }
    while(less_heap.size() != 1) {
        TreeNode_ptr left = less_heap.top();
        less_heap.pop();
        TreeNode_ptr right =less_heap.top();
        less_heap.pop();
        TreeNode *node = new TreeNode(left->val + right->val);
        node->left = left;
        node->right = right;
        less_heap.push(node);
    }
    return less_heap.top();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {7, 9, 8, 16, 12};
    Tree t = Huffman(nums);
    return 0;
}
