//
//  main.cpp
//  LeetCode_146
//
//  Created by chx on 2020/7/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct DLinkNode {
    DLinkNode *pre;
    DLinkNode *next;
    int key;
    int val;
    DLinkNode(int k, int v) : key(k), val(v), next(nullptr), pre(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int curr;
    DLinkNode *head;
    DLinkNode *tail;
    unordered_map<int, DLinkNode*> node_map;
    
    void Insert(DLinkNode *node) {
        tail->next = node;
        node->pre = tail;
        tail = tail->next;
    }
    
    void moveToTail(DLinkNode *node) {
        if (node == tail) return;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = nullptr;
        tail->next = node;
        node->pre = tail;
        tail = tail->next;
    }
    
    void removeHead() {
        DLinkNode *temp = head->next;
        if (!temp) return;
        node_map.erase(temp->key);
        head->next = temp->next;
        if (temp->next) temp->next->pre = head;
    }
public:

    LRUCache(int capacity) {
        head = new DLinkNode(-1, -1);
        tail = head;
        this->capacity = capacity;
        this->curr = 0;
    }
    
    int get(int key) {
        if (node_map.find(key) == node_map.end()) return head->val;
        DLinkNode *node = node_map[key];
        moveToTail(node);
        return node->val;
    }
    
    void put(int key, int value) {
        DLinkNode *node;
        if (node_map.find(key) != node_map.end()) {
            node = node_map[key];
            node->val = value;
            moveToTail(node);
            return;
        }
        node = new DLinkNode(key, value);
        if (capacity > curr) {
            Insert(node);
            curr++;
        } else {
            removeHead();
            Insert(node);
        }
        node_map[key] = tail;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
