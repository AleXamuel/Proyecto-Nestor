//https://vjudge.net/problem/UVA-294
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

vector<int> primos;

void precompute(int cota) {
    int n = sqrt(cota);
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++)
        if (is_prime[i]) {
            primos.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
}

int decompose(int n) {
    int ans = 1;
    for (int i: primos) {
        if ((ll) i * i > n)
            break;
        int act = 1;
        while (n % i == 0) {
            act++;
            n /= i;
        }
        ans *= act;
    }
    if (n > 1)
        ans <<= 1;
    return ans;
}


void solve() {
    int l, r;
    cin >> l >> r;
    int ans = -1;
    int cur = 0;
    For(i, l, r+1) {
        int divs = decompose(i);
        if (divs > ans) {
            ans = divs;
            cur = i;
        }
    }
    cout << "Between " << l << " and " << r << ", " << cur << " has a maximum of " << ans << " divisors." << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute(1000000000);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

