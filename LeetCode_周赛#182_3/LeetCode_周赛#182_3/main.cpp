//
//  main.cpp
//  LeetCode_周赛#182_3
//
//  Created by chx on 2020/3/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class UndergroundSystem {
private:
    map<string, map<string, float>> time_cost;      // time_cost[A][B] 为 A 站 到 B 站的总时间花费
    map<string, map<string, int>> station_times;    // station_times[A][B] 为 A 站 到 B 站的总出行次数
    map<int, string> passenger_in;                  // 乘客 id 进站时的站名
    map<int, float> passenger_checkin_time;         // 乘客 id 站时的时刻
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        // 记录进站信息
        passenger_in[id] = stationName;
        passenger_checkin_time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        // 出站时取出该乘客进站信息，计算相关数据并更新
        float duration = t - passenger_checkin_time[id];
        string startStation = passenger_in[id];
        // 更新 起始站到终点站的总出行次数
        station_times[startStation][stationName] += 1;
        // 更新 起始站到终点站的总出行时间
        time_cost[startStation][stationName] += duration;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return time_cost[startStation][endStation] / station_times[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
