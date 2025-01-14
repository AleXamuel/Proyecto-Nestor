//https://codeforces.com/gym/105505/problem/D
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <string>
#define INF 1e9;
vector<vector<int>> adj;
vector<int> mt;
vector<bool> used;
bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> mp(n);
    for(int i=0;i<n;i++)
        cin>>mp[i];
    vector<vector<int>> colors(n,vector<int>(2,-1));
    vector<int> cnt(n,0);
    int col=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(mp[i][j]=='1') {
                vector<int> act={i,j};
                for(int k=0;k<n;k++) {
                    if(k!=i&&k!=j&&mp[i][k]=='1'&&mp[j][k]=='1')
                        act.push_back(k);
                }
                for(int u:act)
                    for(int v:act)
                        mp[u][v]=0;
                for(int u:act)
                    colors[u][cnt[u]++]=col;
                col++;
            }
        }
    }
    for(int i=0;i<n;i++)
        while(cnt[i]<2)
            colors[i][cnt[i]++]=col++;
    adj.assign(col,vector<int>());

    for(int i=0;i<n;i++) {
        adj[colors[i][0]].push_back(colors[i][1]);
        adj[colors[i][1]].push_back(colors[i][0]);
    }
    int c=0;
    mt.assign(col,-1);
    for(int i=0;i<col;i++) {
        used.assign(col,false);
        if(try_kuhn(i))
            c++;
    }
    cout<<c/2<<endl;

    return 0;
}
