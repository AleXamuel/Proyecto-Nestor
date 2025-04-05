//https://leetcode.com/problems/last-stone-weight-ii/description/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    int total = accumulate(stones.begin(), stones.end(), 0);
    int half = total / 2;
    vector<bool> dp(half + 1, false);
    dp[0] = true;

    for (int stone: stones) 
        for (int i = half; i >= stone; i--) 
            dp[i] = dp[i] || dp[i - stone];

    for (int i = half; i >= 0; i--)
        if (dp[i])
            return total - 2 * i;

    return 0;
    }
};
