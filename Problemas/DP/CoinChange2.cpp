//https://leetcode.com/problems/coin-change-ii/description/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    unsigned long long change(int amount, vector<int>& coins) {
        
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin]; 
            }
        }

        return dp[amount];
    }
};
