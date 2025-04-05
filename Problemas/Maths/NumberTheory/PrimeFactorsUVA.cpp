//https://vjudge.net/problem/UVA-583
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

vector<ll> primos;

void precompute() {
    int n = 46341; //El factor primo más grande un número será como máximo la raiz cuadrada de ese número,46341=sqrt((2^31)-1)
    primos.assign(4792, 0); //El número de primos entre 2 y (2^31)-1 es 4792
    int c = 1;
    primos[0] = 2;
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
            primos[c++] = i;
        }
    }
}

void solve() {
    precompute();
    while (true) {
        ll n;
        cin >> n;
        if (n == 0)
            break;
        cout << n << " = ";
        if (n < 0) {
            cout << "-1 x ";
            n *= -1;
        }
        vector<string> ans;
        for (const auto &i: primos) {
            if (i > n)
                break;
            while (n % i == 0) {
                ans.push_back(to_string(i));
                ans.emplace_back(" x ");
                n /= i;
            }
        }

        if (ans.empty())
            cout << n;
        else {
            ans.pop_back();
            for (const auto &s: ans)
                cout << s;
        }
        cout << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
