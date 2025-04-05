//https://vjudge.net/problem/CSES-1667
import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static boolean[] state;
    static int[] d,pi;
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        int n=sc.nextInt();
        int m=sc.nextInt();
        adj=new ArrayList[n];
        state=new boolean[n];
        d=new int[n];
        pi=new int[n];
        Arrays.fill(pi,-1);
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u =sc.nextInt()-1;
            int v=sc.nextInt()-1;
            addEdge(u,v);
        }
        bfs(0);
        if(pi[n-1]==-1){
            System.out.println("IMPOSSIBLE");
            return;
        }
        LinkedList<Integer> list=new LinkedList<>();
        for (int v=n-1;v!=0;v=pi[v])
            list.addFirst(v);
        pw.println(list.size()+1);
        pw.print(1);
        for(int i : list)
            pw.print(" "+(i+1));
        pw.close();
    }
    static void bfs(int s){
        d[s]=0;
        state[s]=true;
        Queue<Integer> q=new LinkedList<>();
        q.add(s);
        while(!q.isEmpty()){
            int u=q.poll();
            for(int v:adj[u]){
                if(!state[v]){
                    pi[v]=u;
                    d[v]=d[u]+1;
                    state[v]=true;
                    q.add(v);
                }
            }
        }
    }
    static void addEdge(int u, int v){
        adj[u].add(v);
        adj[v].add(u);
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
