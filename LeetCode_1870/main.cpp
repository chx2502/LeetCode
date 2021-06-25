#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool onTime(vector<int>& dist, double hour, double speed, int size) { 
        double cost = 0.0; 
        for (int i = 0; i < size; i++) {
            if (i != size-1) cost += ceil(dist[i] / speed);
            else cost += dist[i] / speed;
            if (cost > hour) return false;
        }
        return true;
    } 
     
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long totalDist = 0;
        int size = (int)dist.size();
        if (hour <= size-1) return -1;
        for (const int &d : dist) totalDist += d;
        double minSpeed = ceil(totalDist / hour);
        double maxSpeed = 1e7;
        double speed;
        int result = -1;
        while (minSpeed <= maxSpeed) {
            cout << "minSpeed = " << minSpeed << " maxSpeed = " << maxSpeed;
            speed = ceil((maxSpeed + minSpeed) / 2.0);
            cout << " speed = " << speed << endl; 
            if (onTime(dist, hour, speed, size)) {
                result = (int)speed;
                maxSpeed = speed - 1.0;
            } else minSpeed = speed + 1.0;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> dist = {5, 3, 4, 6, 2, 2, 7};
    double hour = 10.92; 
    int result = s.minSpeedOnTime(dist, hour);
    cout << result << endl;
}