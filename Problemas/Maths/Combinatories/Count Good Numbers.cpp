//https://leetcode.com/problems/count-good-numbers/description/
class Solution {
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    long long countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long evenCount = (n + 1) >> 1;
        long long oddCount = n >> 1;

        long long fivePow = binpow(5, evenCount, MOD);
        long long fourPow = binpow(4, oddCount, MOD);

        long long ans = (fivePow * fourPow) % MOD;
        return ans;
    }
};
