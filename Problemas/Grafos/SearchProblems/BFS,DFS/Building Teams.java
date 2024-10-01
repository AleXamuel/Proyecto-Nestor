//https://vjudge.net/problem/CSES-1668
import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static boolean[] state;
    static int[] d,pi;
    static int n;
    static Boolean[] color;
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        n=sc.nextInt();
        int m=sc.nextInt();
        adj=new ArrayList[n];
        state=new boolean[n];
        color = new Boolean[n];
        d=new int[n];
        pi=new int[n];
        Arrays.fill(pi,-1);
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u =sc.nextInt()-1;
            int v=sc.nextInt()-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        for (int i = 0; i < n; i++) {
            if(!state[i]){
                if(!bfs(i)){
                    System.out.println("IMPOSSIBLE");
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++)
            pw.print((color[i]? 1:2)+" ");
        pw.close();



    }
    static boolean bfs(int s) {
        color[s] = true;
        Queue<Integer> Q = new LinkedList<>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            if (!state[u]) {
                state[u] = true;
                for (int v : adj[u]) {
                    if (!state[v]) {
                        if (color[v]==null)
                            color[v] = !color[u];
                        if (color[v] == color[u])
                            return false;
                        Q.add(v);
                    }
                }
            }
        }
        return true;
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
