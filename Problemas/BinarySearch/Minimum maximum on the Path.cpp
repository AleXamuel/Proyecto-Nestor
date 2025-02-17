//https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <string>
#define ll long long
int n,m,k;
typedef pair<int, int> Pair;
int INF=numeric_limits<int>::max();
vector<vector<Pair>> adj;
vector<int> bfs(int x) {
    vector<bool> state(n, false);
    vector<int> d(n,INF);
    vector<int> pi(n,-1);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    state[1] = true;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (Pair p : adj[u]) {
            int v=p.second;
            int w=p.first;
            if(!state[v]&&w<=x&&d[u]<k) {
                state[v]=true;
                q.push(v);
                d[v]=d[u]+1;
                pi[v]=u;
            }
        }
    }
    return pi;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("socdist.in", "r",stdin);
    //freopen("socdist.out", "w", stdout);
    cin>>n>>m>>k;
    n++;
    adj.assign(n, vector<Pair>());
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(w,v);
    }
    int l=0,r=1e9;
    vector<int> pi(n,-1);
    while(l<=r) {
        int mid=l+(r-l)/2;
        vector<int> act=bfs(mid);
        if(act[n-1]>-1) {
            pi=act;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(pi[n-1]==-1) {
        cout<<"-1"<<endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(n-1);
    for(int u=pi[n-1];u>-1;u=pi[u])
        ans.push_back(u);
    cout<<ans.size()-1<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
    return 0;
}
