//https://open.kattis.com/problems/bookclub
import java.io.*;
import java.util.*;
class Ma{
    static ArrayList<Integer>[] adj;
    static int[] mt;
    static boolean[] state;
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        adj=new ArrayList[n];
        mt=new int[n];

        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++)
            adj[sc.nextInt()].add(sc.nextInt());
        Arrays.fill(mt,-1);
        for (int i = 0; i < n; i++) {
            state=new boolean[n];
            tryKuhn(i);
        }
        int c=0;
        for (int i:mt)
            if(i!=-1)
                c++;
        if(c==n)
            System.out.println("YES");
        else
            System.out.println("NO");

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

        public Scanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }
        public boolean ready() throws IOException {
            return br.ready();
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
    }



}
