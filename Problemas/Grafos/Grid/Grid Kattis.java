//https://open.kattis.com/problems/grid
import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        int n=sc.nextInt(),m=sc.nextInt();
        int[][] map=new int[n][m];
        boolean[][] state=new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s=sc.next();
            for (int j = 0; j < m; j++)
                map[i][j]=s.charAt(j)-'0';

        }
        Edge s=new Edge(0,0,map[0][0],0);
        Queue<Edge> q=new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()){
            Edge u=q.poll();
            if(u.i==n-1 &&u.j==m-1) {
                System.out.println(u.d);
                return;
            }
            if(u.i-u.k>=0 && !state[u.i-u.k][u.j]){
                state[u.i-u.k][u.j]=true;
                q.add(new Edge(u.i-u.k,u.j,map[u.i-u.k][u.j],u.d+1));
            }
            if(u.j-u.k>=0 && !state[u.i][u.j-u.k]){
                state[u.i][u.j-u.k]=true;
                q.add(new Edge(u.i,u.j-u.k,map[u.i][u.j-u.k],u.d+1));
            }
            if(u.i+u.k<n && !state[u.i+u.k][u.j]){
                state[u.i+u.k][u.j]=true;
                q.add(new Edge(u.i+u.k,u.j,map[u.i+u.k][u.j],u.d+1));
            }
            if(u.j+u.k<m && !state[u.i][u.j+u.k]){
                state[u.i][u.j+u.k]=true;
                q.add(new Edge(u.i,u.j+u.k,map[u.i][u.j+u.k],u.d+1));
            }
        }
        System.out.println(-1);
    }
    static class Edge{
        int i,j,k,d;
        public Edge(int a, int b,int c, int di){
            i=a;
            j=b;
            k=c;
            d=di;
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
        char nextChar() throws IOException {
            return (char) br.read();
        }

    }

}
