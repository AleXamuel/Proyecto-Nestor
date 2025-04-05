// https://leetcode.com/problems/prime-palindrome/description/?envType=problem-list-v2&envId=number-theory&difficulty=MEDIUM

#include <string>
using namespace std;

class Solution {
public:
    bool is_prime(int num){
        if (num < 2) return false;
        for (int i = 2; i*i <= num; ++i){
            if ( num % i == 0) return false;
        }
        return true;
    }
    bool palindrome(int num){
        string s = to_string(num);
        int l = 0;
        int r = s.size()-1;
        while (l < r){
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int primePalindrome(int n) {
        n = max(n, 2);
        while (true){
            // Saltar rangos específicos
            if ((n > 1e3 && n < 1e4) || 
                (n > 1e5 && n < 1e6) || 
                (n > 1e7 && n < 1e8)) {
                n = pow(10, ceil(log10(n))); //Saltar al siguiente rango
                continue;
            }

            if (is_prime(n) && palindrome(n)) return n;
            n++;
        }
    }
};
