//https://codeforces.com/problemset/problem/52/C
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF=214745077900;
ll *t, *lazy;
void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2] , t[v * 2 + 1]);
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
        t[v * 2] += lazy[v] ;
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, ll addend) {
    if (l > r) return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        t[v] = min(t[v * 2] , t[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l == tl && tr == r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm)) ,
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
vector<string> tokenize(string s, string del = " "){
    int start, end = -1*del.size();
    vector<string> ans(0);
    do {
        start = end + del.size();
        end = s.find(del, start);
        ans.push_back(s.substr(start, end - start));
    } while (end != -1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    ll* a = new ll[n]();
    for(int i =0; i < n; i++)
        cin>>a[i];
    t = new ll[4 * n]();
    lazy = new ll[4 * n]();
    build(a, 1, 0, n - 1);
    cin>>q;
    cin.ignore();
    string line;
    for (int i = 0; i < q; i++) {
        getline(cin,line);
        vector<string> tokens = tokenize(line, " ");
        if(tokens.size() == 3) {
            int l = stoi(tokens[0]);
            int r = stoi(tokens[1]);
            ll x = stoi(tokens[2]);
            if(l<=r)
                update(1,0,n-1,l,r,x);
            else {
                update(1,0,n-1,l,n-1,x);
                update(1,0,n-1,0,r,x);
            }
        }
        else {
            int l = stoi(tokens[0]);
            int r = stoi(tokens[1]);
            if(l<=r)
                cout<<query(1,0,n-1,l,r)<<"\n";
            else
                cout<<min(query(1,0,n-1,l,n-1),query(1,0,n-1,0,r))<<"\n";
        }
    }
    delete[] a;
    delete[] t;
    delete[] lazy;

    return 0;
}
