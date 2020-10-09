//
//  main.cpp
//  LeetCode_117
//
//  Created by chx on 2020/9/28.
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
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node *curr = root;
        while (curr) {
            Node *dummy = new Node(101);
            Node *pre = dummy;
            
            while (curr) {
                if (curr->left) {
                    pre->next = curr->left;
                    pre = pre->next;
                }
                if (curr->right) {
                    pre->next = curr->right;
                    pre = pre->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
        }
        
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
