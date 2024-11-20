//https://www.spoj.com/problems/POTHOLE/
import java.io.*;
import java.util.*;
public class Main {
    static long[][] capacity;
    static ArrayList<Integer>[] adj;
    static int INF = Integer.MAX_VALUE;
    static int n;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        for (int tim = 0; tim < t; tim++) {
            n=sc.nextInt();
            adj = new ArrayList[n];
            capacity = new long[n][n];
            for (int i = 0; i < n; i++)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < n-1; i++) {
                int j = sc.nextInt();
                for (int k = 0; k < j; k++) {
                    int v = sc.nextInt()-1;
                    adj[i].add(v);
                    adj[v].add(i);
                    capacity[i][v]=INF;
                    if(i==0||v==n-1)
                        capacity[i][v]=1;
                }
            }
            System.out.println(maxflow(0,n-1));
        }


    }

    static boolean bfs(int s, int t, int[] parent) {
        boolean[] visited = new boolean[n];
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

    static long maxflow(int s, int t) {
        int[] pi = new int[n];
        long maxflow = 0;
        while (bfs(s, t, pi)) {
            long flow = INF;
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
