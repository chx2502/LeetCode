#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 使用最大堆的解法
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        if (k == 0) return result;
        priority_queue<int> heap;
        for (auto &num : arr) {
            if (heap.size() < k) heap.push(num);
            else {
                if (num < heap.top()) {
                    heap.pop();
                    heap.push(num);
                }
            }
        }
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
    /*
     * 不断更新返回数组使之保持当前 k 个最小
     * */
//    vector<int> getLeastNumbers(vector<int>& arr, int k) {
//        vector<int> result;
//        if (k == 0) return result;
//        int max_idx = 0;
//        for (auto &num : arr) {
//            if (result.size() < k) {
//                result.push_back(num);
//                if (result[max_idx] < num)
//                    max_idx = result.size()-1;
//            } else {
//                if (num < result[max_idx]) {
//                    result[max_idx] = num;
//                    for (int i = 0; i < k; ++i) {
//                        max_idx = result[i] > result[max_idx] ? i : max_idx;
//                    }
//                }
//            }
//        }
//        return result;
//    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
