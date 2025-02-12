//https://vjudge.net/problem/SPOJ-MATCHING
#include <bits/stdc++.h>
using namespace std;
#define MAX 150007
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==0) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[0] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=0) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[0]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=0) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==0 && dfs(i))
                matching++;
    return matching;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int edges ;
    cin>>n>>m>>edges;
    for(int i=0; i<edges; i++) {
        int u, v;
        cin>>u>>v;
        G[u].push_back(v+n);
        G[v+n].push_back(u);
    }
    cout<<hopcroft_karp();
}
