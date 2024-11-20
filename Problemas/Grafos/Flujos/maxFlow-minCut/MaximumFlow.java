//https://open.kattis.com/problems/maxflow
import java.io.*;
import java.util.*;
class Main {
    static long c=0;
    static int[][] capacity;
    static int[][] fEdges;
    static ArrayList<Integer>[] adj;
    static int INF = Integer.MAX_VALUE;
    static int n;
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner();
        PrintWriter out=new PrintWriter(System.out);
        n=sc.nextInt();
        int m=sc.nextInt(),s=sc.nextInt(),t=sc.nextInt();
        capacity=new int[n][n];
        fEdges=new int[n][n];
        adj=new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt(),v=sc.nextInt(),w=sc.nextInt();
            adj[u].add(v);
            adj[v].add(u);
            capacity[u][v]=w;
        }
        int f=maxflow(s,t);
        LinkedList<int[]> list=new LinkedList<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if(fEdges[i][j]>0)
                    list.add(new int[]{i,j});
            }
        out.println(n+" "+f+" "+list.size());
        for (int[] i:list)
            out.println(i[0]+" "+i[1]+" "+fEdges[i[0]][i[1]]);
        out.close();


    }
    static boolean bfs(int s, int t, int[] parent){
        boolean[] visited=new boolean[n];
        Queue<Integer> q=new LinkedList<>();
        q.add(s);
        parent[s]=-1;
        visited[s]=true;
        while (!q.isEmpty()){
            int cur=q.poll();
            for(int n:adj[cur]){
                if(!visited[n]&&capacity[cur][n]>0){
                    parent[n]=cur;
                    visited[n]=true;
                    q.add(n);
                    if(n==t)
                        return true;
                }
            }
        }
        return false;
    }
    static int maxflow(int s, int t){
        int[] pi=new int[n];
        int maxflow=0;
        while (bfs(s,t,pi)){
            int flow=INF;
            for(int cur=t;cur!=s;cur=pi[cur]){
                int p=pi[cur];
                flow=Math.min(flow,capacity[p][cur]);
            }
            for (int cur = t; cur != s; cur = pi[cur]) {
                int p = pi[cur];
                capacity[p][cur] -= flow;
                capacity[cur][p] += flow;
                fEdges[p][cur] += flow;
                fEdges[cur][p] -= flow;
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
