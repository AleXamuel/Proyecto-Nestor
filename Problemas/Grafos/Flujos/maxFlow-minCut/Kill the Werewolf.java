//https://www.acmicpc.net/problem/13876
import java.io.*;
import java.util.*;
public class Main {
    static ArrayList<Integer>[] adj;
    static int n;
    static final int INF = Integer.MAX_VALUE;
    static int[][] capacity;
    public static void main(String[] args) {
        Scanner sc=new Scanner();
        int m=sc.nextInt();
        int[][] votes=new int[m][2];
        for (int i = 0; i < m; i++) {
            votes[i][0]=sc.nextInt()-1;
            votes[i][1]=sc.nextInt()-1;
        }
        int ans=0;
        for (int i = 0; i < m; i++) {
            int p=0;
            n=(m<<1)+2;
            adj=new ArrayList[n];
            capacity=new int[n][n];
            for (int j = 0; j < n; j++)
                adj[j]=new ArrayList<>();
            int s=n-2;
            int t=n-1;
            for (int j = 0; j < m; j++)
                if(votes[j][0]==i||votes[j][1]==i)
                    p++;
            for (int j = 0; j < m; j++) {
                if(i==j) continue;
                if(votes[j][0]!=i&&votes[j][1]!=i){
                    adj[s].add(j);
                    adj[j].add(s);
                    capacity[s][j]=1;
                    adj[votes[j][0]+m].add(j);
                    adj[j].add(votes[j][0]+m);
                    capacity[j][votes[j][0]+m]=1;
                    adj[votes[j][1]+m].add(j);
                    adj[j].add(votes[j][1]+m);
                    capacity[j][votes[j][1]+m]=1;
                    adj[votes[j][0]+m].add(t);
                    adj[t].add(votes[j][0]+m);
                    capacity[votes[j][0]+m][t]=p-1;
                    adj[votes[j][1]+m].add(t);
                    adj[t].add(votes[j][1]+m);
                    capacity[votes[j][1]+m][t]=p-1;
                }
            }
            capacity[votes[i][0]+m][t]--;
            capacity[votes[i][1]+m][t]--;
            if(maxflow(s,t)<m-p-1)
                ans++;
        }
        System.out.println(ans);

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
