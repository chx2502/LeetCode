//
//  main.cpp
//  LeetCode_offer_06
//
//  Created by chx on 2020/7/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        ListNode *p = head;
        while (p) {
            result.push_back(p->val);
            p = p->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
