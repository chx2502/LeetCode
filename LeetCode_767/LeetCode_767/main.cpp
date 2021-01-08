//
//  main.cpp
//  LeetCode_767
//
//  Created by chx on 2020/11/30.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include "math.h"

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int length = (int)S.length();
        if (length == 0) return "";
        
        unordered_map<char, int> charMap;
        for (auto c : S) {
            charMap[c]++;
            if (charMap[c] > ceil(length/2.0)) return "";
        }
        auto cmp = [&](char a, char b) {
            if (charMap[a] == charMap[b]) return (a < b);
            else return charMap[a] > charMap[b];
        };
        sort(S.begin(), S.end(), cmp);
        string result(length, '0');
        int index = 0;
        for (int i = 0; i < length; i+=2) {
            result[i] = S[index++];
        }
        for (int i = 1; i < length; i+=2) {
            result[i] = S[index++];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string S = "tndsewnllhrtwsvxenkscbivijfqnysamckzoyfnapuotmdexzkkrpmppttficzerdndssuveompqkemtbwbodrhwsfpbmkafpwyedpcowruntvymxtyyejqtajkcjakghtdwmuygecjncxzcxezgecrxonnszmqmecgvqqkdagvaaucewelchsmebikscciegzoiamovdojrmmwgbxeygibxxltemfgpogjkhobmhwquizuwvhfaiavsxhiknysdghcawcrphaykyashchyomklvghkyabxatmrkmrfsppfhgrwywtlxebgzmevefcqquvhvgounldxkdzndwybxhtycmlybhaaqvodntsvfhwcuhvuccwcsxelafyzushjhfyklvghpfvknprfouevsxmcuhiiiewcluehpmzrjzffnrptwbuhnyahrbzqvirvmffbxvrmynfcnupnukayjghpusewdwrbkhvjnveuiionefmnfxao";
    string result = s.reorganizeString(S);
    return 0;
}
