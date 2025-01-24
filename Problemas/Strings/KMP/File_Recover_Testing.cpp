//https://vjudge.net/contest/686598#problem/C
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <climits>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}

int computeLPSArray(string &pat, int M, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else{

                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[M - 1]; 
}

void solve() {
    while(true){
        int n; string s; cin >> n >> s;
        if (n == -1  && s == "*")
            return;
        if (n < s.size()){
            cout << 0 << "\n";
            continue;
        }
        vector<int> lps(s.size());
        int aux = computeLPSArray(s, s.size(), lps);
        int patternLength = s.size() - aux;
        
        cout << 1 + (n - s.size()) / patternLength << "\n";
    }
        
}

int main() {
    fast();
    solve();
    return 0;
}
