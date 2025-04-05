//https://codeforces.com/contest/579/problem/A
#include <iostream>
using namespace std;
int countSetBits(int n){
    int count = 0;
    while (n){
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    cout<<countSetBits(n);
}
