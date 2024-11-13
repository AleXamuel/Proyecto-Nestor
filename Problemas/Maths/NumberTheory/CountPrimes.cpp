// https://leetcode.com/problems/count-primes/description/?envType=problem-list-v2&envId=number-theory&difficulty=MEDIUM

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for ( int i = 2; i*i < n; i++){
            if (isPrime[i]){
                for (int j = i*i; j < n; j += i){ // Marca todos los múltiplos de i como no primos
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++){
            if (isPrime[i]){
                count++;
            }
        }
        return count;
    }
};
