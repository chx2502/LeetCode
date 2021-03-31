//
//  main.cpp
//  LeetCode_链表求和
//
//  Created by chx on 2021/3/3.
//

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    string listToString(ListNode* head) {
        string result = "";
        while (head) {
            result += to_string(head->val);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result == "" ? "0" : result;
    }

//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        long long sum = stoll(listToString(l1)) + stoll(listToString(l2));
//        string ssum = to_string(sum);
//        ListNode *dummy = new ListNode(-1);
//        for (auto &c : ssum) {
//            ListNode *node = new ListNode(c-'0');
//            node->next = dummy->next;
//            dummy->next = node;
//        }
//        return dummy->next;
//    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        s1 = listToString(l1);
        s2 = listToString(l2);
        if (s1.length() < s2.length()) {
            string zeros(s2.length()-s1.length(), '0');
            s1 = zeros + s1;
        }
        if (s1.length() > s2.length()) {
            string zeros(s1.length()-s2.length(), '0');
            s2 = zeros + s2;
        }
        int len = (int)max(s1.length(), s2.length());
        
        int pre = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for (int i = len-1; i >= 0; i--) {
            int curr = (s1[i]-'0') + (s2[i]-'0') + pre;
            if (curr >= 10) {
                pre = 1;
                curr %= 10;
            } else pre = 0;
            ListNode *node = new ListNode(curr);
            tail->next = node;
            tail = tail->next;
        }
        if (pre != 0) {
            ListNode *node = new ListNode(pre);
            tail->next = node;
            tail = tail->next;
        }
        return dummy->next;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
