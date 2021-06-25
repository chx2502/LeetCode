//
//  main.cpp
//  offer_41
//
//  Created by chx on 2021/3/31.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> lessHeap;
    priority_queue<int, vector<int>, less<int>> greaterHeap;
    int lessWeight, greaterWeight;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lessWeight = 0;
        greaterWeight = 0;
    }
    
    void addNum(int num) {
        if (greaterHeap.size() == lessHeap.size()) {
            greaterHeap.push(num);
            lessHeap.push(greaterHeap.top());
            greaterHeap.pop();
            lessWeight++;
        } else {
            lessHeap.push(num);
            greaterHeap.push(lessHeap.top());
            lessHeap.pop();
            greaterWeight++;
        }
    }
    
    double findMedian() {
        if (lessWeight == greaterWeight) {
            return (lessHeap.top() + greaterHeap.top()) / 2.0;
        } else {
            return greaterWeight < lessWeight ? lessHeap.top() : greaterHeap.top();
        }
    }
};


int main(int argc, const char * argv[]) {
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    double res1 = finder.findMedian();
    finder.addNum(3);
    double res2 = finder.findMedian();
    return 0;
}
