static boolean bfs() {
        boolean[] color = new boolean[n];
        boolean[] visited = new boolean[n];
        color[0] = true;
        Queue<Integer> Q = new LinkedList<>();
        Q.add(0);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            if (!visited[u]) {
                visited[u] = true;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        if (!color[v])
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
