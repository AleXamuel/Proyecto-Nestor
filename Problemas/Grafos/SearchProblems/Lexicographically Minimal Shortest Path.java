//https://codeforces.com/gym/102569/problem/D
import java.util.*;
import java.io.*;

public class Main {
    static boolean[] state;
    static PrintWriter pw = new PrintWriter(System.out);
    static int[] pi;
    static int[] d;
    static int n;
    static String[] cost;
    static ArrayList<Edge>[] adj;
    public static void main(String[] args) {
        Scanner sc = new Scanner();

        n=sc.nextInt();
        int m=sc.nextInt();
        d=new int[n];
        state=new boolean[n];
        adj=new ArrayList[n];
        pi=new int[n];
        Arrays.fill(pi,-1);
        cost=new String[n];

        for (int i = 0; i < n; i++) 
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            char w=sc.next().charAt(0);
            adj[u].add(new Edge(v,w));
            adj[v].add(new Edge(u,w));
        }
        ans();
        pw.close();
    }
    static void ans(){
        bfs();
        boolean b=true;
        LinkedList<Integer> q=new LinkedList<>();
        q.add(0);
        String s="";
        while (b){
            char min='z';
            for (int u: q)
                for (Edge v: adj[u])
                    if(d[v.a]+1==d[u])
                        min= (char)Math.min(min,v.w);
            LinkedList<Integer> qq=new LinkedList<>();
            for (int u:q)
                for (Edge v:adj[u])
                    if(d[v.a]+1==d[u]){
                        if(pi[v.a]==-1&&v.w==min) {
                            pi[v.a] = u;
                            qq.add(v.a);
                            if (v.a == n - 1)
                                b = false;
                        }
                    }
            s+=min;
            q=qq;

        }
        int t=n-1;
        ArrayList<Integer> path= new ArrayList<>();
        path.add(n-1);
        while (t>0){
            t=pi[t];
            if(t==-1)
                break;
            path.addFirst((t));
        }
        pw.println(path.size()-1);
        for (int i:path)
            pw.print((i+1)+" ");
        pw.println();
        pw.println(s);
    }
    static void bfs() {
        d[n-1]=0;
        state[n-1]=true;
        Queue<Integer> q=new LinkedList<>();
        q.add(n-1);
        while (!q.isEmpty()){
            int u=q.poll();
            for (Edge v:adj[u]){
                if(!state[v.a]){
                    state[v.a]=true;
                    d[v.a]=d[u]+1;
                    q.add(v.a);
                }
            }
        }
    }



    private static class Edge implements Comparable<Edge>{
        int a;
        char w;
        public Edge(int u, char c){
            a=u;
            w=c;
        }
        public int compareTo(Edge o){
            if(w<o.w)
                return -1;
            if(w>o.w)
                return 1;
            if(a<o.a)
                return -1;
            if(a>o.a)
                return 1;
            return 0;
        }
        public String toString() {
            return "<"+a+", "+w+">";
        }
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
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        char nextChar() throws IOException {
            return (char) br.read();
        }

    }
}
