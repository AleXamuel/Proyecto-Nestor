static int n;
static ArrayList<Integer>[] adj;
static int[] d, low;
static int time;
static boolean[] ap;
static void dfs(int u, int par) {
    d[u] = time++;
    low[u] = d[u];
    int children = 0;
    for(int v : adj[u]) {
        if (v == par) continue;
        else if (d[v] > 0)
            low[u] = Math.min(low[u], d[v]);
        else {
            children++;
            dfs(v, u);
            low[u] = Math.min(low[u], low[v]);
            if (par != -1 && low[v] >= d[u]) ap[u] = true;
        }
    }
    if (par == -1 && children > 1) ap[u] = true;
}

static void get_articulation_points() {
    d = new int[n];
    low = new int[n];
    time = 1;
    ap = new boolean[n];
    Arrays.fill(ap, false);
    for (int i = 0; i < n; i++)
        if (d[i] == 0) dfs(i, -1);
}
