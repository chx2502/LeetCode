//
//  main.cpp
//  LeetCode_290_二进制链表转整数
//
//  Created by chx on 2020/2/27.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     把所有元素存入栈中然后依次计算 num * 2^i
     **/
//    int getDecimalValue(ListNode* head) {
//        if (!head) return 0;
//        stack<int> stk;
//        ListNode *p = head;
//        int result = 0;
//
//        while (p) {
//            stk.push(p->val);
//            p = p->next;
//        }
//        int i = 0;
//        while (!stk.empty()) {
//            int num = stk.top();
//            stk.pop();
//            result += num * pow(2, i++);
//        }
//        return result;
//    }
    /*
     优化版本：
     直接遍历链表，无需存储，无需调用 pow。
     **/
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        int result = 0;
        while (head) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

