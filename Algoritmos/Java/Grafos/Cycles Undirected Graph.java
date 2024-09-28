static int n;
static ArrayList<Integer>[] adj;
static boolean[] state;
static int[] pi;
static int cycleStart, cycleEnd;
static boolean dfs(int u, int par) {
    state[u] = true;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (state[v]) {
            cycleStart = v;
            cycleEnd = u;
            return true;
        }
        pi[v] = u;
        if (dfs(v, u)) return true;
    }
    return false;
}

static LinkedList<Integer> cycle() {
    LinkedList<Integer> ans = new LinkedList<>();
    state = new boolean[n];
    pi = new int[n];
    Arrays.fill(pi, -1);
    cycleStart = -1;
    for (int u = 0; u < n; u++)
        if (!state[u] && dfs(u, pi[u]))
            break;
    if (cycleStart == -1)
        return null;
    ans.add(cycleStart);
    for (int u = cycleEnd; u != cycleStart; u = pi[u])
        ans.add(u);
    ans.add(cycleStart);
    return ans;

}
