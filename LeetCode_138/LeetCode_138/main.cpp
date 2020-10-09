//
//  main.cpp
//  LeetCode_138
//
//  Created by chx on 2020/9/30.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;
    
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *dummy = new Node(10001);
        Node *tail = dummy;
        Node *p = head;
        while (p) {
            Node *node = new Node(p->val);
            nodeMap[p] = node;
            tail->next = node;
            tail = tail->next;
            p = p->next;
        }
        p = head;
        Node *q = dummy->next;
        while (p && q) {
            if (p->random) q->random = nodeMap[p->random];
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
