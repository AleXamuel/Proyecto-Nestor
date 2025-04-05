// https://vjudge.net/problem/SPOJ-COUNTISL
import java.io.*;
import java.util.*;
public class Main{
    static boolean[][] state;
    static char[][] map;
    static int n;
    static int m;

    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner();
        int t=sc.nextInt();
        for (int times = 0; times < t; times++) {
            n=sc.nextInt();
            m=sc.nextInt();
            state=new boolean[n][m];
            map=new char[n][m];
            for (int i = 0; i < n; i++)
                map[i]=sc.next().toCharArray();
            int c=0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j <m ; j++)
                    if(!state[i][j]&&map[i][j]=='#'){
                        c++;
                        bfs(i,j);
                    }
            System.out.println(c);

        }
    }
    static void bfs(int a, int b){
        int[] s={a,b};
        Queue<int[]> q=new LinkedList<>();
        q.add(s);
        int[][] moves={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while (!q.isEmpty()){
            int[] act=q.poll();
            int i=act[0];
            int j=act[1];
            for (int[] mov:moves){
                int ni=i+mov[0];
                int nj=j+mov[1];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&!state[ni][nj]&&map[ni][nj]=='#'){
                    state[ni][nj]=true;
                    q.add(new int[]{ni,nj});
                }
            }
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
        char nextChar(){
            return next().charAt(0);
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
    }



}
