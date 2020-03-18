#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    //
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        const int downLeftX = 0;
        const int downLeftY = 1;
        const int upRightX = 2;
        const int upRightY = 3;
        return !(
                rec1[upRightX] <= rec2[downLeftX] ||
                rec1[downLeftX] >= rec2[upRightX] ||
                rec1[downLeftY] >= rec2[upRightY] ||
                rec1[upRightY] <= rec2[downLeftY]
                );
    }
    // 检查 X，Y 轴上中心点的距离
//    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
//        const int downLeftX = 0;
//        const int downLeftY = 1;
//        const int upRightX = 2;
//        const int upRightY = 3;
//        float midX1 = (float)(rec1[upRightX] + rec1[downLeftX]) / 2;
//        float midX2 = (float)(rec2[upRightX] + rec2[downLeftX]) / 2;
//        float midY1 = (float)(rec1[upRightY] + rec1[downLeftY]) / 2;
//        float midY2 = (float)(rec2[upRightY] + rec2[downLeftY]) / 2;
//
//        float distanceX = abs(midX2 - midX1);
//        float distanceY = abs(midY2 - midY1);
//
//        float radiusX1 = (float)(rec1[upRightX] - rec1[downLeftX]) / 2;
//        float radiusX2 = (float)(rec2[upRightX] - rec2[downLeftX]) / 2;
//        float radiusY1 = (float)(rec1[upRightY] - rec1[downLeftY]) / 2;
//        float radiusY2 = (float)(rec2[upRightY] - rec2[downLeftY]) / 2;
//        return !(distanceX >= (radiusX1 + radiusX2) || distanceY >= (radiusY1 + radiusY2));
//    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
