static int n;
static ArrayList<Integer>[] adj;
static int[] state;
static int[] pi;
static int cycleStart, cycleEnd;
static boolean dfs(int u) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 0) {
            pi[v] = u;
            if (dfs(v)) return true;
        }else if (state[v] == 1) {
            cycleStart = v;
            cycleEnd = u;
            return true;
        }
    }
    state[u] = 2;
    return false;
}
static LinkedList<Integer> cycle() {
    LinkedList<Integer> ans = new LinkedList<>();
    state = new int[n];
    pi = new int[n];
    Arrays.fill(pi, -1);
    cycleStart = -1;
    for (int u = 0; u < n; u++)
        if (state[u] == 0 && dfs(u))
            break;
    if (cycleStart == -1)
        return null;
    ans.add(cycleStart);
    for (int u = cycleEnd; u != cycleStart; u = pi[u])
        ans.add(u);
    ans.add(cycleStart);
    return ans;
}
