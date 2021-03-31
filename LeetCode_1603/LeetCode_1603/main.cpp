//
//  main.cpp
//  LeetCode_1603
//
//  Created by chx on 2021/3/19.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class ParkingSystem {
private:
    int LCapacity, MCapacity, SCapacity;
    bool parking(int carType) {
        bool result = true;
        switch (carType) {
            case 1:
                LCapacity > 0 ? LCapacity-- : result = false;
                break;
            case 2:
                MCapacity > 0 ? MCapacity-- : result = false;
                break;
            case 3:
                SCapacity > 0 ? SCapacity-- : result = false;
                break;
            default:
                result = false;
                break;
        }
        return result;
    }
public:
    ParkingSystem(int big, int medium, int small) {
        LCapacity = big;
        MCapacity = medium;
        SCapacity = small;
    }
    
    bool addCar(int carType) {
        return parking(carType);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
