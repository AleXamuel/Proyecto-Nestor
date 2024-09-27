//https://open.kattis.com/problems/birthday
import java.io.*;
import java.util.*;
class Main{
    static int N;
    static ArrayList<Integer>[] adj;
    static int[] d, f, low;
    static int time;
    static ArrayList<int[]> bridg;
    static boolean b;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter out=new PrintWriter(System.out);
        while (true){
            N=sc.nextInt();int m=sc.nextInt();
            if(N==0 && m==0)
                break;
            d=new int[N];
            low=new int[N];
            adj=new ArrayList[N];
            b=false;
            for (int i = 0; i < N; i++)
                adj[i]=new ArrayList<>();
            for (int i = 0; i < m ; i++) {
                int a=sc.nextInt();
                int b=sc.nextInt();
                adj[a].add(b);
                adj[b].add(a);
            }
            if(!bfs())
                System.out.println("YES");
            else{
                get_bridges();
                System.out.println(b ? "YES":"NO");
            }

        }
    }
    static boolean bfs(){
        boolean[] state=new boolean[N];
        Queue<Integer> q=new LinkedList<>();
        int c=1;
        state[0]=true;
        q.add(0);
        while (!q.isEmpty()){
            int u=q.poll();
            for(int v:adj[u]){
                if(!state[v]){
                    state[v]=true;
                    c++;
                    q.add(v);
                }
            }
        }
        return c==N;
    }
    static void dfs(int u, int par) {
        if(b)
            return;
        d[u] = time++;
        low[u] = d[u];
        for(int v:adj[u]) {
            if (v==par) continue;
            else if (d[v]>0)
                low[u] = Math.min(low[u], d[v]);
            else {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (low[v]>d[u])b=true;
            }
        }

    }

    static void get_bridges() {
        d = new int[N];
        low = new int[N];
        time = 1;
        bridg = new ArrayList<int[]>();
        dfs(0, -1);
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        public boolean ready() throws IOException {
            return br.ready();
        }
        String nextLine() throws IOException {
            return br.readLine();
        }
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    return "";
                }
            }
            return st.nextToken();
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        char nextChar(){
            return next().charAt(0);
        }

    }
}
