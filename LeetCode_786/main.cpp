#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct fraction {
        double val;
        int i, j;
        fraction(double v, int x, int y) : val(v), i(x), j(y) {}
        bool operator > (const fraction& a) const { return this->val > a.val; }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        unsigned long size = arr.size();
        priority_queue<fraction, vector<fraction>,greater<fraction>> pq;

        for (int i = 0; i < size-1; i++) {
            pq.emplace(fraction((double)arr[i] / double(arr[size-1]), i, size-1));
            // cout << "push: " << arr[i] << "/" << arr[size-1] << endl;
        }

        for (int i = 0; i < k-1; i++) {
            fraction f = pq.top();
            pq.pop();
            // cout << "pop: " << arr[f.i] << "/" << arr[f.j] << endl;
            if (f.j > f.i+1) {
                pq.emplace((double)arr[f.i] / double(arr[f.j-1]), f.i, f.j-1);
                // cout << "push: " << arr[f.i] << "/" << arr[f.j-1] << endl;
            }
        }
        return { arr[pq.top().i], arr[pq.top().j] }; 
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> arr ={1, 13, 17, 59};
    int k = 6;
    vector<int> result = s.kthSmallestPrimeFraction(arr, k);
    cout << result[0] << " " << result[1] << endl;
}
