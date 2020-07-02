//
//  main.cpp
//  LeetCode_378
//
//  Created by chx on 2020/7/2.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 暴力法
//    int kthSmallest(vector<vector<int>>& matrix, int k) {
//        int m = (int)matrix.size();
//        if (m == 0) return 0;
//        int n = (int)matrix[0].size();
//        if (n == 0) return 0;
//
//        priority_queue<int, vector<int>, greater<int>> heap;
//        for (int row = 0; row < m; ++row)
//            for (int col = 0; col < n; ++col)
//                heap.push(matrix[row][col]);
//        k -= 1;
//        while (k--) heap.pop();
//        return heap.top();
//    }
    
    // 维护最小候选者
    struct Point {
        int row;
        int col;
        int value;
        Point(int x, int y, int v): row(x), col(y), value(v) { }
        
        /*
         当priority_queue在调用我们所写的重载比较函数时，输入的参数为const的student对象。
         只有const成员函数才能访问const对象中的数据，而非const成员函数不能。
         原文链接：https://blog.csdn.net/weixin_43837435/java/article/details/104177460
         */
        bool operator > (const Point& a) const{ return this->value > a.value; }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = (int)matrix.size();
        if (n == 0) return 0;
        
        priority_queue<int, vector<Point>, greater<Point>> heap;
        for (int i = 0; i < n; ++i) {
            Point p = Point(0, i, matrix[0][i]);
            heap.push(p);
        }
        k -= 1;
        while (k--) {
            Point temp = heap.top();
            heap.pop();
            if (temp.row < n-1) {
                Point newCandidate(temp.row+1, temp.col, matrix[temp.row+1][temp.col]);
                heap.push(newCandidate);
            }
        }
        return heap.top().value;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
