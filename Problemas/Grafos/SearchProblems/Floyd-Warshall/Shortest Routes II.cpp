//https://vjudge.net/problem/CSES-1672
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define pb push_back
using namespace std;
typedef unsigned long long ll;
ll INF=18446744073709551615;
vector<vector<ll>> floydWarshall(vector<vector<ll>> madj) {
    int n = madj.size();
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (madj[i][k] < INF && madj[k][j] < INF)
                    madj[i][j] = min(madj[i][j], madj[i][k] + madj[k][j]);
    return madj;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> madj(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++)
        madj[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u-=1;
        v-=1;
        madj[u][v] = min(madj[u][v], w);
        madj[v][u] = min(madj[v][u], w);
    }
    madj=floydWarshall(madj);
    for (int i = 0; i < q; i++) {
        int u,v;
        cin>>u>>v;
        u-=1;
        v-=1;
        if(madj[u][v]==INF)
            cout<<"-1"<<endl;
        else
            cout<<madj[u][v]<<endl;
    }


    return 0;
}
