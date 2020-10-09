//
//  main.cpp
//  Huawei_2021
//
//  Created by chx on 2020/9/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;


string feature_value(string s, int limit) {
    string result = "";
    for (auto c : s) {
        if (c-'0' < limit) result = result + c;
    }
    return result;
}

int main() {
    string s;
    int limit = -1;
    vector<string> s_array;
    while (getline(cin, s)) {
        if (s.length() == 0) break;
        if (s.length() == 1) limit = s[0] - '0';
        else s_array.push_back(s);
    }
    string feature = feature_value(s_array.back(), limit);
    for (int i = 0; i < s_array.size()-1; i++) {
        string temp = feature_value(s_array[i], limit);
        if (temp.find(feature) != string::npos) cout << s_array[i] << endl;
    }
    return 0;
}

/*
135682318
23457
14282123
14231728
3
1724153
 **/
