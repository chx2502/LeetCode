#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int curr = first;
        vector<int> result;
        result.push_back(first);
        for (const int num : encoded) {
            int next = curr^num;
            result.push_back(next);
            curr = next;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> encoded = {6, 2, 7, 3};
    int first = 4;
    vector<int> result = s.decode(encoded, first);
    for (const int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
