import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class MazeMovement {
    public static void main(String[] args) throws IOException {
        //se utiliza el algoritmo de Dinic para hallar la flujo maximos
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(bf.readLine());
        DinicMaxFlow f = new DinicMaxFlow(n);
        int[] datos=new int[n];
        TreeMap<Integer,Integer> indices=new TreeMap<>();
        for (int i = 0; i < n; i++) {
            int v=Integer.parseInt(bf.readLine());
            datos[i] = v;
            indices.put(v,i);
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int v=gcd(datos[i],datos[j]);
                if(v>1){
                    f.addEdge(i,j,v);
                    f.addEdge(j,i,v);
                }
            }
        }
        int min=indices.pollFirstEntry().getValue();
        int max=indices.pollLastEntry().getValue();
        System.out.println(f.maxFlow(min, max));
    }
    static int gcd(int n1, int n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }
    static class Edge {
        int to, rev;
        int cap, flow;

        Edge(int to, int rev, int cap) {
            this.to = to;
            this.rev = rev;
            this.cap = cap;
            this.flow = 0;
        }
    }

    static class DinicMaxFlow {
        int n;
        List<Edge>[] adj;
        int[] level;
        int[] ptr;
        DinicMaxFlow(int n) {
            this.n = n;
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new ArrayList<>();
            }
            level = new int[n];
            ptr = new int[n];
        }

        void addEdge(int a, int b, int cap) {
            adj[a].add(new Edge(b, adj[b].size(), cap));
            adj[b].add(new Edge(a, adj[a].size() - 1, 0));
        }

        boolean bfs(int s, int t) {
            Arrays.fill(level, -1);
            Queue<Integer> queue = new LinkedList<>();
            queue.add(s);
            level[s] = 0;
            while (!queue.isEmpty()) {
                int v = queue.poll();
                for (Edge edge : adj[v]) {
                    if (level[edge.to] < 0 && edge.flow < edge.cap) {
                        level[edge.to] = level[v] + 1;
                        queue.add(edge.to);
                    }
                }
            }
            return level[t] >= 0;
        }

        int dfs(int s, int t, int flow) {
            if (s == t) {
                return flow;
            }
            for (; ptr[s] < adj[s].size(); ptr[s]++) {
                Edge edge = adj[s].get(ptr[s]);
                if (level[edge.to] == level[s] + 1 && edge.flow < edge.cap) {
                    int pushed = dfs(edge.to, t, Math.min(flow, edge.cap - edge.flow));
                    if (pushed > 0) {
                        edge.flow += pushed;
                        adj[edge.to].get(edge.rev).flow -= pushed;
                        return pushed;
                    }
                }
            }
            return 0;
        }

        int maxFlow(int s, int t) {
            int flow = 0;
            while (bfs(s, t)) {
                Arrays.fill(ptr, 0);
                int pushed;
                while ((pushed = dfs(s, t, Integer.MAX_VALUE)) != 0) {
                    flow += pushed;
                }
            }
            return flow;
        }
    }
}
