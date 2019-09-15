//
//  main.cpp
//  二叉树的基本操作
//
//  Created by 成鑫 on 2019/7/27.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "math.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL) {};
};

struct AVLTree {
    TreeNode *root;
    TreeNode *nil;
    AVLTree(): root(NULL), nil(NULL) {}
};

TreeNode *LL_Rotate(TreeNode *A) {
    TreeNode *B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}

TreeNode *RR_Rotate(TreeNode *A) {
    TreeNode *B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}

TreeNode *LR_Rotate(TreeNode *A) {
    A->left = RR_Rotate(A->left);
    return LL_Rotate(A);
}

TreeNode *RL_Rotate(TreeNode *A) {
    A->right = LL_Rotate(A->right);
    return RR_Rotate(A);
}

int HeightOfTree(TreeNode *T) {
    if (!T) return 0;
    
    int L_Height, R_Height, Max_Height;
    TreeNode *p = T;
    L_Height = HeightOfTree(T->left);
    R_Height = HeightOfTree(T->right);
    Max_Height = L_Height > R_Height ? L_Height : R_Height;
    return Max_Height + 1;
}

TreeNode* Insert(TreeNode *root, int x) {
    if (!root) {
        TreeNode *node = new TreeNode(x);
        root = node;
        return root;
    } else if (x < root->val) {
        root->left = Insert(root->left, x);
        if (HeightOfTree(root->left) - HeightOfTree(root->right) == 2) {
            if (x < root->left->val) root = LL_Rotate(root);
            else root = LR_Rotate(root);
        }
    } else if (x >= root->val) {
        root->right = Insert(root->right, x);
        if (HeightOfTree(root->right) - HeightOfTree(root->left) == 2) {
            if (x > root->right->val) root = RR_Rotate(root);
            else root = RL_Rotate(root);
        }
    }
    return root;
}

void CreateAVLTree(AVLTree *T, vector<int> val_array) {
    for (auto x : val_array) T->root = Insert(T->root, x);
}

TreeNode* CreateBinaryTree(vector<int> val_array) {
    TreeNode *root = NULL;
    const long int size = val_array.size();
    if (size == 0) return root;

    vector<TreeNode*> node_array;
    node_array.push_back(NULL);
    for (int i = 0; i < size; i++) {
        if (val_array.at(i) != (int)NULL) {
            TreeNode *node = new TreeNode(val_array.at(i));
            node_array.push_back(node);
        } else node_array.push_back(NULL);
    }
    root = node_array.at(1);
    for (int i = 1; i <= size/2; i++) {
        TreeNode *node = node_array.at(i);
        if (!node) continue;
        int left_idx, right_idx;
        left_idx = i * 2;
        right_idx = i * 2 + 1;
        if (left_idx <= size) node->left = node_array.at(left_idx);
        if (right_idx <= size) node->right = node_array.at(right_idx);
    }
    return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector< vector<int> > ret;
    if (!root) return ret;
    queue<TreeNode*> queue_curr, queue_next;
    queue_curr.push(root);
    
    do {
        while(!queue_next.empty()) {
            queue_curr.push(queue_next.front());
            queue_next.pop();
        }
        
        vector<int> tmp;
        TreeNode *node;
        while(!queue_curr.empty()) {
            node = queue_curr.front();
            if (node->left) queue_next.push(node->left);
            if (node->right) queue_next.push(node->right);
            queue_curr.pop();
            tmp.push_back(node->val);
        }
        ret.push_back(tmp);
    } while(!queue_next.empty());
    
    return ret;
}

bool isBalanced(TreeNode* root) {
    if (!root) return true;
    if (fabs(HeightOfTree(root->left) - HeightOfTree(root->right)) > 2)
        return false;
    else return isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> test = {1, 2, 2, 3, 3, NULL, NULL, 4, 4};
    TreeNode *tree = CreateBinaryTree(test);
    bool result = isBalanced(tree);
//    AVLTree *AVL_Tree = new AVLTree();
//    CreateAVLTree(AVL_Tree, test);
//    vector<vector<int>> level_walk = levelOrder(AVL_Tree->root);
//    for (auto array : level_walk) {
//        for (auto val : array)
//            cout << val << " ";
//        cout << endl;
//    }
    return 0;
}
