//
//  main.cpp
//  LeetCode_133
//
//  Created by chx on 2020/8/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> node_map;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node *result = new Node(node->val);
        node_map[result->val] = result;
        for (auto &neighbor : node->neighbors) {
            if (node_map.find(neighbor->val) == node_map.end())
                result->neighbors.push_back(cloneGraph(neighbor));
            else result->neighbors.push_back(node_map[neighbor->val]);
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    
    return 0;
}
