#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int result = INT_MAX;
    int n;
public:
    void backTracking(vector<int>& jobs, vector<int>& workers, int idx, int assigned, int maxNum, int k) {
        if (maxNum >= result) return;
        if (idx == n) {
            result = maxNum;
            return;
        }

        if (assigned < k) {
            workers[assigned] = jobs[idx];
            int nextMaxNum = max(workers[assigned], maxNum);
            backTracking(jobs, workers, idx+1, assigned+1, nextMaxNum, k);
            workers[assigned] = 0;
        }

        for (int i = 0; i < assigned; i++) {
            workers[i] += jobs[idx];
            int nextMaxNum = max(workers[i], maxNum);
            backTracking(jobs, workers, idx+1, assigned, nextMaxNum, k);
            workers[i] -= jobs[idx];
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = (int)jobs.size();

        if (n == 0) return 0;
        if (n == k) return *max_element(jobs.begin(), jobs.end());
        vector<int> workers(k, 0); 
        backTracking(jobs, workers, 0, 0, 0, k);
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> jobs = {19, 12, 10};
    int k = 2;
    int result = s.minimumTimeRequired(jobs, k);
    cout << result << endl;
    return 0;
}