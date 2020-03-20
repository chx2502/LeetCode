#include <iostream>
#include <vector>
#include <map>

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
    /*
     * 使用字典解法
     * 核心思路：
     * 将 <原链表节点， 新链表节点> 作为 <Key, Value> 存起来
     * 先复制链表，再逐一处理 random
     */

    Node* copyRandomList(Node* head) {
        // 处理空链表的情况
        if (!head) return NULL;

        // 设置哨兵结点，方便记录头结点和尾插
        Node *dummy = new Node(MIN);
        Node *tail = dummy;
        Node *p = head;
        map<Node*, Node*> M;
        // 尾插法复制生成新链表，同时将 <原链表节点，新链表节点> 作为键值对存入 map
        while (p) {
            Node *node = new Node(p->val);
            M[p] = node;
            tail->next = node;
            tail = node;
            p = p->next;
        }
        p = head;
        Node *q = dummy->next;
        while (p) {
            // 当 p->random 存在时，取出 p->random 节点对应的新链表节点，赋值给 q->random
            if (p->random) q->random = M[p->random];
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
    const int MIN = -10001;
    /*
     * 解法 1：
     * 先构建新链表，然后再单独处理 random 指针，无需字典。
     * 构建新链表后，两个指针 p, q 分别指向 原链表 和 新链表。
     * 当 p->random != NULL 时，在 p 的左右两边逐步寻找 random，同步更新 q 的左右两边指针。
     * 找到后将 q->random 赋值为找到的那一侧指针。
     * 逐一更新所有元素的 random 指针后返回。
     * 可优化的地方：左右两边的寻找过程可以分开写，左边找不到再找右边，减少指针越界判断次数。
     * */
//    Node* copyRandomList(Node* head) {
//        // 处理空链表的情况
//        if (!head) return NULL;
//
//        // 设置哨兵结点，方便记录头结点和尾插
//        Node *dummy = new Node(MIN);
//        Node *tail = dummy;
//        Node *p = head;
//        // 尾插法复制生成新链表
//        while (p) {
//            Node *node = new Node(p->val);
//            tail->next = node;
//            tail = node;
//            p = p->next;
//        }
//
//        // 开始更新 random 指针值
//        Node *q = dummy->next;
//        p = head;
//        while (p) {
//            // 在旧链表的当前结点 p->random != NULL 时，
//            // 开始从左右两边寻找 random，并同步更新新链表的左右两侧指针
//            if (p->random != nullptr) {
//                Node *origin_left, *origin_right, *new_left, *new_right;
//                origin_left = head;
//                origin_right = p;
//                new_left = dummy->next;
//                new_right = q;
//                // 循环持续条件为：左边没找到 且 右边没找到
//                while (origin_left != p->random && origin_right != p->random) {
//                    if (origin_left) origin_left = origin_left->next;
//                    if (origin_right) origin_right = origin_right->next;
//                    if (new_left) new_left = new_left->next;
//                    if (new_right) new_right = new_right->next;
//                }
//                // 将 q->random 更新为找到 random 一侧的指针值
//                if (p->random == origin_left) q->random = new_left;
//                if (p->random == origin_right) q->random = new_right;
//            }
//            // 更新下一个结点的 random
//            p = p->next;
//            q = q->next;
//        }
//        return dummy->next;
//    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
