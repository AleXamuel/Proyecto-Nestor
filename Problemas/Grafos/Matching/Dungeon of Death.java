//https://vjudge.net/problem/SPOJ-QUEST4
import java.io.*;
import java.util.*;
public class Main {
    static ArrayList<Integer>[] adj;
    static int[] mt;
    static boolean[] state;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        PrintWriter out = new PrintWriter(System.out);
        int ti = sc.nextInt();
        for (int tim = 0; tim < ti; tim++) {
            int m=sc.nextInt();
            adj = new ArrayList[120];
            mt=new int[120];
            for (int i = 0; i < 120; i++)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                adj[sc.nextInt()].add(sc.nextInt());
            }
            int c=0;
            Arrays.fill(mt,-1);
            for (int i = 0; i < 120; i++) {
                state = new boolean[120];
                if (tryKuhn(i))
                    c++;
            }
            System.out.println(c);

        }


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
