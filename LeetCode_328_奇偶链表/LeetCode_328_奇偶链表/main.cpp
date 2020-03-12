//
//  main.cpp
//  LeetCode_328_奇偶链表
//
//  Created by chx on 2020/3/12.
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
    /*
     核心思路：
     三指针找奇数节点尾插。
     tail, pre, odd 分别指向尾插位置，待插入的奇数节点前一个节点，待插入的奇数节点。
     插入完成后，尾结点前移，pre 前移，odd 移到到 pre->next，若 pre 或 odd 指空则插入完毕。
     **/
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode *tail, *odd, *pre;
        tail = odd = pre = head;
        pre = tail->next;
        if (pre) odd = pre->next;
        if (!pre || !odd) return head;
        
        do {
            pre->next = odd->next;
            odd->next = tail->next;
            tail->next = odd;
            tail = odd;
            pre = pre->next;
            if (pre) odd = pre->next;
        } while(pre != nullptr && odd != nullptr);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
