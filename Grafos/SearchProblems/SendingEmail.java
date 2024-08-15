/* https://vjudge.net/problem/UVA-10986 */

import java.util.*;
import java.io.*;

public class SendingEmail {
    static int n;
    static ArrayList<Edge>[] adj;
    static boolean[] state;
    static int[] pi;
    static int[] d;

    public static void main(String[] args) throws Exception {
        Input in = new Input(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            n = in.nextInt();
            adj = new ArrayList[n];
            int m = in.nextInt();
            int S = in.nextInt();
            int T = in.nextInt();
            for (int j = 0; j < n; j++)
                adj[j] = new ArrayList<>();
            for (int k = 0; k < m; k++) {
                int a = in.nextInt();
                int b = in.nextInt();
                int w = in.nextInt();
                adj[a].add(new Edge(b, w));
                adj[b].add(new Edge(a, w));
            }
            Dijkstra(S);
            if (!state[T]) System.out.println("Case #" + (i + 1) + ": unreachable");
            else {
                System.out.println("Case #" + (i + 1) + ": " + d[T]);
            }
        }
    }

    static void Dijkstra(int s) {
        pi = new int[n];
        d = new int[n];
        state = new boolean[n];
        pi[s] = -1;
        Arrays.fill(d, Integer.MAX_VALUE);
        d[s] = 0;
        TreeSet<Edge> Q = new TreeSet<>();
        Q.add(new Edge(s, 0));
        while (!Q.isEmpty()) {
            Edge e = Q.pollFirst();
            assert e != null;
            int u = e.vertex;
            if (!state[u]) {
                for (Edge ee : adj[u]) {
                    int v = ee.vertex;
                    if (!state[v]) {
                        int w = ee.weight;
                        if (d[u] + w < d[v]) {
                            d[v] = d[u] + w;
                            pi[v] = u;
                            Q.add(new Edge(v, d[v]));
                        }
                    }
                }
                state[u] = true;
            }
        }
    }

    public static class Edge implements Comparable<Edge> {
        int vertex;
        int weight;

        public Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }

        public int compareTo(Edge a) {
            if (weight < a.weight)
                return -1;
            if (weight > a.weight)
                return 1;
            return Integer.compare(vertex, a.vertex);
        }

        public String toString() {
            return "(" + vertex + ", " + weight + ")";
        }
    }

    static class Input {
        BufferedReader br;
        StringTokenizer st;

        public Input(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() throws Exception {
            return br.readLine();
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
    }
}
