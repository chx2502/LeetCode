//
//  main.cpp
//  LeetCode_382
//
//  Created by chx on 2020/10/20.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int size;
    unordered_map<int, ListNode*> node_map;
public:
    Solution(ListNode* head) {
        ListNode *p = head;
        int index = 0;
        size = 0;
        while (p) {
            node_map[index++] = p;
            p = p->next;
        }
        size = index;
    }
    
    int getRandom() {
        return node_map[rand() % size]->val;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
