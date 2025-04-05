import java.io.*;
import java.util.*;
static ArrayList<Integer>[] adj;
static int[] d, pi;
static int INF = 1 << 30;
static ArrayList<edge> Edges=new ArrayList<>();
static void shortest_path(int n, int s) {
    boolean[] state = new boolean[n];
    Arrays.fill(pi, -1);
    Arrays.fill(d, INF);
    d[s] = 0;
    Queue<Integer> q = new LinkedList<>();
    q.add(s);
    while (!q.isEmpty()) {
        int u = q.poll();
        state[u] = false;
        for (int i = 0; i < adj[u].size(); i++) {
            int id = adj[u].get(i);
            int v = Edges.get(id).to;
            if (Edges.get(id).flow > 0 && d[v] > d[u] + Edges.get(id).cost) {
                pi[v] = id;
                d[v] = d[u] + Edges.get(id).cost;
                if (!state[v]) {
                    state[v] = true;
                    q.add(v);
                }
            }
        }
    }
}
static int min_cost_flow(int n, int k, int s, int t) {
    int flow = 0, ret = 0;
    while (flow < k) {
        shortest_path(n, s);
        if (d[t] == INF) return -1;
        int f = k - flow, cur = t;
        while (cur != s) {
            f = Math.min(f, Edges.get(pi[cur]).flow);
            cur = Edges.get(pi[cur]).from;
        }
        flow += f;
        ret += f * d[t];
        cur = t;
        while (cur != s) {
            Edges.get(pi[cur]).flow -= f;
            Edges.get(pi[cur] ^ 1).flow += f;
            cur = Edges.get(pi[cur]).from;
        }
    }
    return flow<k?-1:ret;
}
static void addEdge(int u, int v, int f, int c) {
    adj[u].add(Edges.size());
    Edges.add(new edge(u, v, f, c));
    adj[v].add(Edges.size());
    Edges.add(new edge(v, u, 0, -c));

}
static class edge {
    int from, to, flow, cost;
    public edge(int from, int to, int flow, int cost) {
        this.from = from;
        this.to = to;
        this.flow = flow;
        this.cost = cost;
    }
}
