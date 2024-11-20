//https://vjudge.net/problem/CSES-1711
import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static int n;
    static final int INF = Integer.MAX_VALUE;
    static int[][] capacity;
    static int[][] flo;

    public static void main(String[] args) {
        Scanner sc=new Scanner();
        PrintWriter out=new PrintWriter(System.out);
        n=sc.nextInt();
        int m=sc.nextInt();
        adj=new ArrayList[n];
        capacity=new int[n][n];
        flo=new int[n][n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1,v=sc.nextInt()-1;
            adj[u].add(v);
            adj[v].add(u);
            capacity[u][v]=1;
        }
        int flow=maxflow(0,n-1);
        out.println(flow);
        for(int i =0;i<flow;i++){
            StringBuilder sb=new StringBuilder();
            int k=n-1;
            int c=1;
            while(k>0){
                sb.insert(0,(k+1)+" ");
                for (int j = 0; j < n; j++) {
                    if(flo[j][k]==1){
                        flo[j][k]=0;
                        k=j;
                        c++;
                        break;
                    }
                }
            }
            sb.insert(0,1+" ");
            out.println(c);
            out.println(sb);
        }
        out.close();
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

    static int maxflow(int s, int t) {
        int[] pi = new int[n];
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
                flo[p][cur] += flow;
                flo[cur][p] -= flow;
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
