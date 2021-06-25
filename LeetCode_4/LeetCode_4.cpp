#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
/**
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();

        int p, q;
        p = q = 0;
        int count = 0;
        int pre = 0;
        int curr = 0;
        while (p < size1 && q < size2) {
            if (nums1[p] <= nums2[q]) {
                pre = curr;
                curr = nums1[p];
                p++;
            } else {
                pre = curr;
                curr = nums2[q];
                q++;
            }
            count++;
            if (count == (size1 + size2)/2 + 1) {
                if ((size1+size2)&1) return curr;
                else return (pre+curr) / 2.0;
            }
        }
        while (p < size1) {
            pre = curr;
            curr = nums1[p];
            p++;
            count++;
            if (count == (size1 + size2)/2 + 1) break;
        }
        while (q < size2) {
            pre = curr;
            curr = nums2[q];
            q++;
            count++;
            if (count == (size1 + size2)/2 + 1) break;
        }
        if ((size1+size2)&1) return curr;
        else return (pre+curr) / 2.0;
    }
    */
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();

        if (size1 > size2) return findMedianSortedArrays(nums2, nums1);

        const int median = (size1 + size2 + 1) / 2;
        int left = 0;
        int right = size1;
        while (left < right) {
            int m1 = left + (right - left) / 2;
            int m2 = median - m1;
            if (nums1[m1] < nums2[m2-1]) {
                left = m1 + 1;
            } else {
                right = m1;
            }
        }
        int m1 = left;
        int m2 = median - m1;
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1], m2 <= 0 ? INT_MIN : nums2[m2-1]);
        int c2 = min(m1 >= size1 ? INT_MAX : nums1[m1], m2 >= size2 ? INT_MAX : nums2[m2]);
        if ((size1+size2)&1) return c1;
        return (c1 + c2) * 0.5;
   }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}