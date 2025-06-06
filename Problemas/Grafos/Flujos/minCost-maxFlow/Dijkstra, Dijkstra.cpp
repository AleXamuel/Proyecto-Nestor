//https://vjudge.net/problem/UVA-10806
#include <bits/stdc++.h>
using namespace std;
#define MAX 100007
#define INF (1<<30)
#define ll long long
#define nmax 101
typedef pair<int,int> pii;
struct edge {
    int from, to, flow, cost;
    edge(int fr, int t, int fl,int c) {
        from=fr;
        to=t;
        flow=fl;
        cost=c;
    }
};
vector<edge> Edges;
vector<int> adj[nmax];
int d[nmax],pi[nmax];
void addEdge(int u, int v, int f, int c) {
    adj[u].push_back(Edges.size());
    Edges.push_back(edge(u,v,f,c));
    adj[v].push_back(Edges.size());
    Edges.push_back(edge(v,u,0,-c));
}
void shortest_path(int n, int s) {
    bool state[nmax];
    for(int i=0;i<n;i++)
        d[i]=INF,pi[i]=-1,state[i]=0;
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        state[u]=0;
        for(int i=0;i<adj[u].size();i++) {
            int id=adj[u][i];
            int v=Edges[id].to;
            if(Edges[id].flow>0&&d[v]>d[u]+Edges[id].cost) {
                pi[v]=id;
                d[v]=d[u]+Edges[id].cost;
                if(!state[v]) state[v]=1,q.push(v);
            }
        }
    }
}
int min_cost_flow(int n,int k, int s, int t) {
    int flow=0,ret=0;
    while(flow<k) {
        shortest_path(n,s);
        if(d[t]==INF)return -1;
        int f=k-flow,cur=t;
        while(cur!=s) {
            f=min(f,Edges[pi[cur]].flow);
            cur=Edges[pi[cur]].from;
        }
        flow+=f;
        ret+=f*d[t];
        cur=t;
        while(cur!=s) {
            Edges[pi[cur]].flow-=f;
            Edges[pi[cur]^1].flow+=f;
            cur=Edges[pi[cur]].from;
        }
    }
    return flow<k?-1:ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n&&n) {
        Edges.clear();
        for(int i=0;i<n;i++)adj[i].clear();
        int m;
        cin>>m;
        for(int i=0;i<m;i++) {
            int u, v,w;
            cin>>u>>v>>w;
            addEdge(--u, --v, 1,w);
            addEdge(v, u, 1,w);
        }
        int ans=min_cost_flow(n, 2, 0, n-1);
        string sout=ans==-1?"Back to jail":to_string(ans);
        cout<<sout<< endl;
    }
}
