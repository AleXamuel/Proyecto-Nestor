//https://codeforces.com/problemset/problem/489/B
import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] adj;
    static int[] mt;
    static boolean[] state;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter pw=new PrintWriter(System.out);
        int n=sc.nextInt();
        int[] b=new int[n];
        for (int i = 0; i < n; i++)
            b[i]=sc.nextInt();
        int m=sc.nextInt();
        int[] g=new int[m];
        for (int i = 0; i < m; i++)
            g[i]=sc.nextInt();
        adj=new ArrayList[n+m];
        for (int i = 0; i < n+m; i++)
            adj[i]=new ArrayList<>();
        mt=new int[n+m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(Math.abs(b[i]-g[j])<=1){
                    adj[i].add(j+n);
                    //adj[j+n].add(i);
                }
        int c=0;
        Arrays.fill(mt,-1);
        for (int i = 0; i < n+m; i++) {
            state=new boolean[n+m];
            if(tryKuhn(i))
                c++;
        }
        System.out.println(c);
        //System.out.println(Arrays.toString(adj));
        pw.close();
    }
    static boolean tryKuhn(int u){
        if(state[u])
            return false;
        state[u]=true;
        for (int v:adj[u])
            if(mt[v]==-1||tryKuhn(mt[v])){
                mt[v]=u;
                return true;
            }
        return false;
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
