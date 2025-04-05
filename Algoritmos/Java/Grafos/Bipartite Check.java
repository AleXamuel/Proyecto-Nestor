static Boolean[] color;
static ArrayList<Integer>[] adj;
static boolean[] state;
static boolean bfs(int s) {
color[s] = true;
Queue<Integer> Q = new LinkedList<>();
Q.add(s);
while (!Q.isEmpty()) {
    int u = Q.poll();
    if (!state[u]) {
        state[u] = true;
        for (int v : adj[u]) {
            if (!state[v]) {
                if (color[v]==null)
                    color[v] = !color[u];
                if (color[v] == color[u])
                    return false;
                Q.add(v);
            }
        }
    }
}
return true;
}
