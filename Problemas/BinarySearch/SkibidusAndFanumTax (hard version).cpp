//https://codeforces.com/contest/2065/problem/C2
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

int m;
vector<int> B;


int binarySearch(int x) {
    int l = 0;
    int r = m - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (B[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}


void solve() {
    int n;
    cin >> n >> m;
    vector<int> A(n);
    fori(i, 0, n)
        cin >> A[i];
    B.assign(m, 0);
    fori(i, 0, m)
        cin >> B[i];
    sort(all(B));
    int first = A[0];
    fori(i, 0, m)
        first = min(first, B[i] - A[0]);
    A[0] = first;
    fori(i, 1, n) {
        int cur = A[i];
        int prev = A[i - 1];
        int x = binarySearch(cur + prev);
        if (x >= 0) {
            int copy = B[x] - A[i];
            if (cur < copy) {
                if (cur < A[i - 1]) {
                    if (copy < A[i - 1]) {
                        cout << "NO" << ln;
                        return;
                    }
                    A[i] = copy;
                }
            } else {
                if (copy >= A[i - 1])
                    A[i] = copy;
            }
        }
    }
    fori(i, 0, n-1)
        if (A[i] > A[i + 1]) {
            cout << "NO" << ln;
            return;
        }
    cout << "YES" << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
//This code also works for easy version
