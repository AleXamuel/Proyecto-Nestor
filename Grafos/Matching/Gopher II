//https://open.kattis.com/problems/gopher2
import java.io.*;
import java.util.*;
class Ma{
    static ArrayList<Integer>[] adj;
    static int[] mt;
    static boolean[] state;

    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        while (sc.ready()){
            int n=sc.nextInt();
            int m=sc.nextInt();
            int s=sc.nextInt();
            int v=sc.nextInt();
            adj=new ArrayList[n];
            mt=new int[n];
            for (int i = 0; i < n; i++)
                adj[i]=new ArrayList<>();
            Punto[] ratas=new Punto[n];
            Punto[] huecos=new Punto[m];
            for (int i = 0; i < n; i++)
                ratas[i]=new Punto(sc.nextDouble(),sc.nextDouble());
            for (int i = 0; i < m; i++)
                huecos[i]=new Punto(sc.nextDouble(),sc.nextDouble());

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(ratas[i].d(huecos[j])/v<=s)
                        adj[i].add(j);
                }
            }
            int c=0;
            Arrays.fill(mt,-1);
            for (int i = 0; i < n; i++) {
                state=new boolean[n];
                if(tryKuhn(i))
                    c++;
            }

            System.out.println(n-c);
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
    static class Punto{
        double x;
        double y;
        public Punto(double a, double b){
            x=a;
            y=b;
        }
        public double d(Punto p){
            return Math.hypot(x-p.x,y-p.y);
        }
        public String toString(){
            return "("+x+", "+y+")";
        }
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
        double nextDouble(){
            return Double.parseDouble(next());
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
    }



}
