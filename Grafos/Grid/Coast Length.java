//https://open.kattis.com/problems/coast
import java.io.*;
import java.util.*;

class Main{
    static int[][] map;
    static boolean[][] sea;
    static int n,m;
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner();
        n=sc.nextInt();
        m=sc.nextInt();
        map=new int[n][m];
        sea=new boolean[n][m];
        for (int i = 0; i <n ; i++) {
            for (int j = 0; j < m; j++)
                map[i][j]=sc.nextChar()-'0';
            sc.nextLine();
        }
        for (int i = 0; i < m; i++)
            if(!sea[0][i]&&map[0][i]==0)
                bfsSea(0,i);
        for (int i = 0; i < m; i++)
            if(!sea[n-1][i]&&map[n-1][i]==0)
                bfsSea(n-1,i);
        for (int i = 0; i < n; i++)
            if(!sea[i][0]&&map[i][0]==0)
                bfsSea(i,0);
        for (int i = 0; i < n; i++)
            if(!sea[i][m-1]&&map[i][m-1]==0)
                bfsSea(i,m-1);
        int c=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j]==1){
                    if(i+1<n&&sea[i+1][j])
                        c++;
                    if(j+1<m&&sea[i][j+1])
                        c++;
                    if(i-1>=0&&sea[i-1][j])
                        c++;
                    if(j-1>=0&&sea[i][j-1])
                        c++;
                    if(i+1==n)
                        c++;
                    if(j+1==m)
                        c++;
                    if(i-1<0)
                        c++;
                    if(j-1<0)
                        c++;
                }
            }
        }

        System.out.println(c);
    }
    static void bfsSea(int a, int b){
        int[] s={a,b};
        sea[a][b]=true;
        Queue<int[]> q=new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()){
            int[] u=q.poll();
            int i=u[0];
            int j=u[1];
            if(i+1<n&&map[i+1][j]==0&&!sea[i+1][j]){
                sea[i+1][j]=true;
                q.add(new int[]{i+1,j});
            }
            if(j+1<m&&map[i][j+1]==0&&!sea[i][j+1]){
                sea[i][j+1]=true;
                q.add(new int[]{i,j+1});
            }
            if(i-1>=0&&map[i-1][j]==0&&!sea[i-1][j]){
                sea[i-1][j]=true;
                q.add(new int[]{i-1,j});
            }
            if(j-1>=0&&map[i][j-1]==0&&!sea[i][j-1]){
                sea[i][j-1]=true;
                q.add(new int[]{i,j-1});
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
