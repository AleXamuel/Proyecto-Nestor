//https://vjudge.net/problem/Gym-101606K    Problem K in the PDF
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
        PrintWriter pw=new PrintWriter(System.out);
        int m=sc.nextInt();
        int[][] gruas=new int[m][2];
        for (int i = 0; i < m; i++) {
            gruas[i][0] = sc.nextInt();
            gruas[i][1] = sc.nextInt();
        }
        int q=sc.nextInt();
        int[] queries=new int[q];
        HashMap<Integer,Integer> map=new HashMap<>();
        HashMap<Integer,Integer> map2=new HashMap<>();
        int cont=0;
        for (int i = 0; i < q; i++) {
            int u=sc.nextInt();
            queries[i]=u;
            if(!map.containsKey(u)) {
                map.put(u, cont);
                cont++;
            }
            if(!map2.containsKey(u))
                map2.put(u,1);
            else
                map2.put(u,map2.get(u)+1);
        }
        n=(m<<1)+map.size()+2;
        capacity=new int[n][n];
        flo=new int[n][n];
        int s=n-2;
        int t=n-1;
        adj=new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            adj[i].add(i+m);
            adj[i+m].add(i);
            capacity[i][i+m]=1;
        }
        for(int i=0;i<m;i++) {
            if(gruas[i][0]==0){
                adj[s].add(i);
                adj[i+m].add(s);
                capacity[s][i]=1;
            }
            for (int j = 0; j < m; j++) {
                if(i==j)continue;
                if(gruas[i][1]>=gruas[j][0]){
                    adj[i+m].add(j);
                    adj[j].add(i+m);
                    capacity[i+m][j]=1;
                }
            }
            for (int j = 0; j < q; j++) {
                if(gruas[i][1]>=queries[j]){
                    adj[i+m].add((m<<1)+map.get(queries[j]));
                    adj[(m<<1)+map.get(queries[j])].add(i+m);
                    capacity[i+m][(m<<1)+map.get(queries[j])]=1;
                }
            }
        }
        for(Map.Entry<Integer,Integer> entry:map.entrySet()) {
            adj[(m<<1)+entry.getValue()].add(t);
            adj[t].add((m<<1)+entry.getValue());
            capacity[(m<<1)+entry.getValue()][t]=map2.get(entry.getKey());
        }
        int flag=maxflow(s,t);
        if(flag<q){
            System.out.println("impossible");
            return;
        }
        for(int j:queries) {
            int k=(m<<1)+map.get(j);
            StringBuilder sb= new StringBuilder();
            boolean fl=false;
            while(k!=s){
                for(int i = 0;i<n;i++){
                    if(flo[i][k]==1){
                        flo[i][k]=0;
                        k=i;
                        if(fl){
                            sb.insert(0, (i+1) + " ");
                            break;
                        }
                    }
                }
                fl=!fl;
            }
            System.out.println(sb);
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
