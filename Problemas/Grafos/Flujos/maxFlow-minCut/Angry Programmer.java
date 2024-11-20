//https://vjudge.net/problem/UVA-11506
import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static int n;
    static final int INF = Integer.MAX_VALUE;
    static int[][] capacity;

    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter out = new PrintWriter(System.out);
        for (;;) {
            n = sc.nextInt();
            int m = sc.nextInt();
            if (n == 0 && m == 0)
                break;
            adj = new ArrayList[2 * n];
            capacity = new int[2 * n][2 * n];
            for (int i = 0; i < adj.length; i++)
                adj[i] = new ArrayList<>();

            capacity[0][n] = INF;
            capacity[n][0] = INF;
            capacity[n-1][2*n-1] = INF;
            capacity[2*n-1][n-1] = INF;
            addEdge(n, 0);
            addEdge(0, n);
            addEdge(n - 1, 2 * n - 1);
            addEdge(2 * n - 1, n - 1);
            for (int i = 0; i < n - 2; i++) {
                int a = sc.nextInt() - 1;
                int w = sc.nextInt();
                addEdge(a, a + n);
                addEdge(a + n, a);
                capacity[a][a+n] = w;

            }
            for (int i = 0; i < m; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                int w = sc.nextInt();
                addEdge(a+n,b);
                addEdge(b,a+n);
                capacity[a+n][b] = w;
                addEdge(b+n,a);
                addEdge(a,b+n);
                capacity[b+n][a] = w;
            }
            out.println(maxflow(0,n-1));
        }
        out.close();

    }

    static void addEdge(int a, int b) {
        adj[a].add(b);
    }

    static boolean bfs(int s, int t, int[] parent) {
        boolean[] visited = new boolean[n * 2];
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        parent[s] = -1;
        visited[s] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int n : adj[cur]) {
                if (!visited[n] && capacity[cur][n] > 0) {
                    parent[n] = cur;
                    visited[n] = true;
                    q.add(n);
                    if (n == t)
                        return true;
                }
            }
        }
        return false;
    }

    static int maxflow(int s, int t) {
        int[] pi = new int[2 * n];
        int maxflow = 0;
        while (bfs(s, t, pi)) {
            int flow = INF;
            for (int cur = t; cur != s; cur = pi[cur]) {
                int p = pi[cur];
                flow = Math.min(flow, capacity[p][cur]);
            }
            for (int cur = t; cur != s; cur = pi[cur]) {
                int p = pi[cur];
                capacity[p][cur] -= flow;
                capacity[cur][p] += flow;
            }

            maxflow += flow;
        }
        return maxflow;
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
