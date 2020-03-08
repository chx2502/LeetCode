#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * 官方题解实现的。
     * 思路：
     * 令 quarter = size() / 4，则在[0, quarter-1], [quarter, 2*quarter-1] ...[n*quarter, size-1] 区间中，
     * 必有一个区间的起点是出现超过 quarter 次的，否则不存在超过 25% 出现次数的解。
     * 依次找到这些区间起点值在数组中的位置，向两边数次数，次数加起来超过 quarter 即返回该元素。
     * 很有意思的一题，评论区有更多大开脑洞的方法。
     *
     */

    int binarySearch(vector<int> &arr, int begin, int end, int target) {
        if (begin > end) return -1;
        int mid = (begin + end) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, begin, mid-1, target);
        else return binarySearch(arr, mid+1, end, target);
    }
    int findSpecialInteger(vector<int>& arr) {
        int length = (int)arr.size();
        int quarter = length/4;
        int i = 0;

        while (i < length) {
            int target = arr[i];
            int index = binarySearch(arr, 0, length-1, target);
            if (index != -1) {
                int left, right;
                left = index-1;
                right = index+1;
                int count = 1;
                while (left > 0 && arr[left--] == target) count++;
                while (right < length && arr[right++] == target) count++;
                if (count > quarter) return target;
            }
            i += quarter;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
