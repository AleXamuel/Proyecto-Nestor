//https://vjudge.net/problem/SPOJ-FASTFLOW
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner();
        int n=sc.nextInt()+1;
        int m=sc.nextInt();
        DinicMaxFlow d=new DinicMaxFlow(n);
        for (int i = 0; i < m ; i++) {
            int u=sc.nextInt(),v=sc.nextInt(),w=sc.nextInt();
            d.addEdge(u,v,w);
            d.addEdge(v,u,w);
        }
        System.out.println(d.maxFlow(1,n-1));
    }
    static class Edge {
        int to, rev;
        long cap, flow;

        Edge(int to, int rev, long cap) {
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

        long dfs(int s, int t, long flow) {
            if (s == t) {
                return flow;
            }
            for (; ptr[s] < adj[s].size(); ptr[s]++) {
                Edge edge = adj[s].get(ptr[s]);
                if (level[edge.to] == level[s] + 1 && edge.flow < edge.cap) {
                    long pushed = dfs(edge.to, t, Math.min(flow, edge.cap - edge.flow));
                    if (pushed > 0) {
                        edge.flow += pushed;
                        adj[edge.to].get(edge.rev).flow -= pushed;
                        return pushed;
                    }
                }
            }
            return 0;
        }

        long maxFlow(int s, int t) {
            long flow = 0;
            while (bfs(s, t)) {
                Arrays.fill(ptr, 0);
                long pushed;
                while ((pushed = dfs(s, t, Long.MAX_VALUE)) != 0) {
                    flow += pushed;
                }
            }
            return flow;
        }
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        char nextChar() throws IOException {
            return (char) br.read();
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() throws Exception {
            return br.readLine();
        }

        public void close() throws IOException {
            br.close();
        }

        public boolean hasNext() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (Exception e) {
                return false;
            }
            return true;
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }

}
