#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MaxQueue {
private:
    int capacity;
    int max;
    queue<int> Q;
    deque<int> dq;
    bool isEmpty() {
        return capacity == 0;
    }
public:
    MaxQueue() {
        capacity = 0;
        max = 0;
    }

    int max_value() {
        if (isEmpty()) return -1;
        else return dq.front();
    }

    void push_back(int value) {
        capacity++;
        Q.push(value);
        while (!dq.empty() && dq.back() < value) dq.pop_back();
        dq.push_back(value);
    }

    int pop_front() {
        if (isEmpty()) return -1;
        capacity--;
        int res = Q.front();
        if (res == dq.front()) {
            dq.pop_front();
        }
        Q.pop();
        return res;
    }
};

int main() {
    MaxQueue q;
    vector<int> cases = {1, 6, 4, 3, 5};
    for (auto &num : cases) {
        q.push_back(num);
    }
    int pop1 = q.pop_front();
    int max1 = q.max_value();

    return 0;
}
