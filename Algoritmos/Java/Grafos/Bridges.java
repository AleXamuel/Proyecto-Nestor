static int N;
static ArrayList<Integer>[] adj;
static int[] d, f, low;
static int time;
static ArrayList<int[]> bridg;

static void dfs(int u, int par) {
    d[u] = time++;
    low[u] = d[u];
    for(int v:adj[u]) {
        if (v==par) continue;
        else if (d[v]>0) 
            low[u] = Math.min(low[u], d[v]);
        else {
            dfs(v, u); 
            low[u] = Math.min(low[u], low[v]);
            if (low[v]>d[u]) bridg.add(new int[]{u, v});
        }
    }
}
static void get_bridges() {
    d = new int[N];
    low = new int[N];        
    time = 1;
    bridg = new ArrayList<int[]>();
    dfs(0, -1);
}
