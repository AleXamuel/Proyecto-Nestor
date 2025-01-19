const int MOD = 1000000007;

long long mod_exp(int base, int exp, int mod) {
    long long result = 1;
    long long power = base % mod; 

    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * power) % mod; 
        }
        power = (power * power) % mod; 
        exp /= 2; 
    }
    return result;
}
