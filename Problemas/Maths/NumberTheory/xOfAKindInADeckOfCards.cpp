//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/?envType=problem-list-v2&envId=number-theory&difficulty=EASY

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() == 1){
            return false;
        }                

        unordered_map<int, int> countMap;
        for (int num: deck){
            countMap[num]++;
        }

        int gcdValue = 0;
        for (const auto& pair: countMap){
            gcdValue = gcd(gcdValue, pair.second);
        }

        return gcdValue > 1;
    }
};
