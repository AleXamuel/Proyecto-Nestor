#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define sz(v) (int)((v).size())


vector<int> primos;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            ans.push_back(i);
        if (is_prime[i] && (ll) i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    return ans;
}

vector<int> decompose(int n)
{
    vector<int> ans;
    for (int i : primos)
    {
        if ((ll)i * i > n)
            break;
        while (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}
