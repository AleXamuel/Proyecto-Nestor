static boolean[] state;
static ArrayList<Edge>[] adj;
static int[] d;
static int INF =Integer.MAX_VALUE;


static void dijkstra(int s, int t) {
    Arrays.fill(d, INF);
    Arrays.fill(pi,-1);
    d[s] = 0;
    TreeSet<Edge> Q = new TreeSet<Edge>();
    Q.add(new Edge(s, d[s]));
    while (!Q.isEmpty()) {
        Edge e = Q.pollFirst();
        int u = e.vertex;
        if (!state[u]) {
            state[u] = true;
            for (Edge ee : adj[u]) {
                int v = ee.vertex;
                int w = ee.weight;
                if (!state[v])
                    if (d[u] + w < d[v]) {
                        d[v] = d[u] + w;
                        pi[v]=u;
                        Q.add(new Edge(v, d[v]));
                    }
            }
        }
    }
}
static class Edge implements Comparable<Edge> {
    int vertex;
    int weight;

    public Edge(int v, int w) {
        this.vertex = v;
        this.weight = w;
    }

    public int compareTo(Edge o) {
        if (weight < o.weight)
            return -1;
        if (weight > o.weight)
            return 1;
        if (vertex < o.vertex)
            return -1;
        if (vertex > o.vertex)
            return 1;
        return 0;
    }
}
