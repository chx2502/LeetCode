#include <iostream>
#include <vector>

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
    const int MIN = -10001;
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *dummy = new Node(MIN);
        Node *tail = dummy;
        Node *p = head;
        while (p) {
            Node *node = new Node(p->val);
            tail->next = node;
            tail = node;
            p = p->next;
        }
        Node *q = dummy->next;
        p = head;
        while (p) {
            if (p->random != nullptr) {
                Node *origin_left, *origin_right, *new_left, *new_right;
                origin_left = head;
                origin_right = p;
                new_left = dummy->next;
                new_right = q;
                while (origin_left != p->random && origin_right != p->random) {
                    if (origin_left) origin_left = origin_left->next;
                    if (origin_right) origin_right = origin_right->next;
                    if (new_left) new_left = new_left->next;
                    if (new_right) new_right = new_right->next;
                }
                if (p->random == origin_left) q->random = new_left;
                if (p->random == origin_right) q->random = new_right;
            }
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
