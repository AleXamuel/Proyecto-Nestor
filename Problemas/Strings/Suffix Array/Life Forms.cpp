//https://open.kattis.com/problems/lifeforms
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define dll double long
#define ll long long
#define Pair pair<ll,ll>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
//vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1000000007;
const int inf = 500;
//solution
vector<int> sort_cyclic_shifts(vector<int> const& s) {
    int n = s.size();
    const int alphabet = 556;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(vector<int>& s) {
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    return sorted_shifts;
}
vector<int> lcp_construction(vector<int> const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
class ST {
private:
    vector<ll> t;
    int n;

    void buildST(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            buildST(a, v * 2, tl, tm);
            buildST(a, v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll sumST(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 1e18;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return min(sumST(v * 2, tl, tm, l, min(r, tm)),
                   sumST(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void updateST(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v] = min(new_val,t[v]);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateST(v * 2, tl, tm, pos, new_val);
            else
                updateST(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    ST(vector<int>& a) {
        n = a.size();
        t.resize(4 * n);
        buildST(a, 1, 0, n - 1);
    }

    ll query(int l, int r) {
        return sumST(1, 0, n - 1, l, r);
    }

    void update(int pos, int x) {
        updateST(1, 0, n - 1, pos, x);
    }
};
vector<int> sz;
vector<int> idx;
set<int> str;
int getS(int i) {
    int l=0, r=sz.size()-1,ans=-1;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(i<sz[mid]) {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
void add(int i, int c) {
    int j=getS(c);
    int cur=idx[j];
    idx[j]=i;
    if(cur==-1)
        str.insert(i);
    else {
        str.erase(cur);
        str.insert(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cs=0;
    while(true) {
        int n;cin>>n;
        int m=(n>>1)+1;
        if(n==0)break;
        if(cs)cout<<ln;
        if(n==1) {
            string s;cin>>s;
            cout<<s<<ln;
            continue;
        }
        int ch=27;
        vector<int> s;
        sz.resize(n);
        str.clear();
        idx.assign(n,-1);
        For(i,0,n) {
            string t;cin>>t;
            for(char c:t)
                s.pb(c-'a');
            s.pb(ch++);
            sz[i]=s.size();
        }
        auto p=suffix_array_construction(s);
        auto lcp=lcp_construction(s,p);
        ST st(lcp);
        vector<int> ans;
        int mx=0;
        For(i,0,s.size()-1) {
            add(i,p[i]);
            if(str.size()>m)
                str.erase(str.begin());
            if(str.size()==m) {
                int act=st.query(*str.begin(),i-1);
                if(act>mx) {
                    ans.clear();
                    mx=act;
                    ans.pb(p[i]);
                }
                else if(act==mx)
                    ans.pb(p[i]);
            }
        }
        if(mx==0)
            cout<<"?"<<ln;
        else {
            set<string>uniq;
            for(int j:ans) {
                string r;
                For(i,j,j+mx)
                    r.pb(char(s[i]+'a'));
                uniq.insert(r);
            }
            for(const string& r:uniq)
                cout<<r<<ln;
        }
        cs++;
    }
    return 0;
}
