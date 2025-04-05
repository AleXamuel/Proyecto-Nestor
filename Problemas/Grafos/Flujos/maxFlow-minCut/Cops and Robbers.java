//https://open.kattis.com/problems/copsandrobbers
import java.io.*;
import java.util.*;

class Main {
    static HashSet<Integer>[] adj;
    static int n;
    static final int INF = 1<<30;
    static int[][] capacity;
    public static void main(String[] args) {
        Scanner sc=new Scanner();
        int m=sc.nextInt(),N=sc.nextInt(),c=sc.nextInt();
        n=N*m*2+2;
        adj=new HashSet[n];
        for(int i=0;i<n;i++)
            adj[i]=new HashSet<>();
        capacity=new int[n][n];
        char[][] map=new char[N][m];
        for (int i = 0; i < N; i++)
            map[i]=sc.next().toCharArray();
        int[] dx={0,0,1,-1};
        int[] dy={1,-1,0,0};
        int s=n-2;
        int t=n-1;
        int[] pesos=new int[c];
        for (int i = 0; i < c; i++)
            pesos[i]=sc.nextInt();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < m; j++) {
                int u=index(N,m,i,j,0);
                int v=index(N,m,i,j,1);
                if(map[i][j]=='B'){
                    adj[s].add(v);
                    adj[v].add(s);
                    capacity[s][v]=INF;
                }
                else if(map[i][j]=='.'){
                    adj[u].add(v);
                    adj[v].add(u);
                    capacity[u][v]=INF;
                }
                else{
                    adj[u].add(v);
                    adj[v].add(u);
                    capacity[u][v]=pesos[map[i][j]-'a'];
                }
                for (int k = 0; k < 4; k++) {
                    int ii=i+dx[k];
                    int jj=j+dy[k];
                    if(ii>=0&&ii<N&&jj>=0&&jj<m){
                        int w=index(N,m,ii,jj,0);
                        adj[v].add(w);
                        adj[w].add(v);
                        capacity[v][w]=INF;
                    }
                    else{
                        adj[v].add(t);
                        adj[t].add(v);
                        capacity[v][t]=INF;
                    }
                }
            }
        }
        int ans=maxflow(s,t);
        System.out.println(ans>=INF?-1:ans);
    }
    static int index(int n, int m,int i, int j, int d){
        return d==0 ? i*m+j:i*m+j+n*m;
    }
    static int maxflow(int s, int t) {
        int[] pi = new int[n];
        int maxflow = 0;
        while (bfs(s, t, pi)) {
            int flow = INF;
            for (int u = t; u != s; u = pi[u]) {
                int p = pi[u];
                flow = Math.min(flow, capacity[p][u]);
            }
            for (int u = t; u != s; u = pi[u]) {
                int p = pi[u];
                capacity[p][u] -= flow;
                capacity[u][p] += flow;
            }
            maxflow += flow;
        }
        return maxflow;
    }

    static boolean bfs(int s, int t, int[] pi) {
        boolean[] visited = new boolean[n];
        Queue<Integer> Q = new LinkedList<>();
        Q.add(s);
        pi[s] = -1;
        visited[s] = true;
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for (int v : adj[u])
                if (!visited[v] && capacity[u][v] > 0) {
                    pi[v] = u;
                    visited[v] = true;
                    if (v == t)
                        return true;
                    Q.add(v);
                }
        }
        return false;
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
