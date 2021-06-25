#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
private:
    vector<int> lessHeap;
    vector<int> greaterHeap;

    void pop_greater() {
        pop_heap(greaterHeap.begin(), greaterHeap.end(), less<int>());
        greaterHeap.pop_back();
    }

    void pop_less() {
        pop_heap(lessHeap.begin(), lessHeap.end(), greater<int>());
        lessHeap.pop_back();
    }

    void push_greater(int num) {
        greaterHeap.push_back(num);
        push_heap(greaterHeap.begin(), greaterHeap.end(), less<int>());
    }

    void push_less(int num) {
        lessHeap.push_back(num);
        push_heap(lessHeap.begin(), lessHeap.end(), greater<int>());
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        push_greater(num);
        push_less(greaterHeap.front());
        pop_greater();

        if (lessHeap.size() > greaterHeap.size()) {
            push_greater(lessHeap.front());
            pop_less();
        }
    }
    
    double findMedian() {
        if (greaterHeap.size() > lessHeap.size()) return (double)greaterHeap.front();
        else return ((double)greaterHeap.front() + (double)lessHeap.front()) * 0.5;
    }
};