//https://vjudge.net/problem/EOlymp-8930
using namespace std;
#include <iostream>
#include <vector>

vector<int> primos;

vector<int> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
        if (is_prime[i] && (long long)i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    vector<int> ans;
    for (int i = 2; i < n + 1; i++)
        if (is_prime[i])
            ans.push_back(i);
    return ans;
}

vector<int> solve(int n)
{
    vector<int> ans;
    for (int i : primos)
    {
        if ((long long)i * i > n)
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    primos = sieve(1 << 13);
    int n;
    cin >> n;
    for (const auto &i : solve(n))
        cout << i << "\n";
    return 0;
}
