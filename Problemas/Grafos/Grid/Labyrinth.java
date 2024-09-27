//https://vjudge.net/problem/UVA-1193
import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int m;
    static boolean[][] state;
    static int[][] d;
    static char[][] map;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        n = sc.nextInt();
        m = sc.nextInt();
        map = new char[n][m];
        int[] ini=new int[2];
        int[] fin=new int[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextChar();
                if(map[i][j]=='A')
                    ini=new int[]{i,j};
                if(map[i][j]=='B')
                    fin=new int[]{i,j};
            }
            sc.nextLine();
        }
        state=new boolean[n][m];
        char[][]ans=bfs(ini[0],ini[1]);
        if(!state[fin[0]][fin[1]])
            System.out.println("NO");
        else{
            int i=fin[0];
            int j=fin[1];
            int index=d[i][j];
            char[] r=new char[index];
            index--;
            while (index>=0){
                char c=ans[i][j];
                r[index]=c;
                index--;
                if(c=='U')
                    i++;
                else if(c=='D')
                    i--;
                else if(c=='R')
                    j--;
                else
                    j++;
            }
            System.out.println("YES");
            System.out.println(r.length);
            System.out.println(r);
        }

    }
    static char[][] bfs(int a, int b){
        int[] s={a,b};
        char[][] pi=new char[n][m];
        d=new int[n][m];
        pi[a][b]='+';
        Queue<int[]> q=new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()){
            int[] u=q.poll();
            int i=u[0];
            int j=u[1];
            if(i+1<n&&!state[i+1][j]&&map[i+1][j]!='#'){
                state[i+1][j]=true;
                pi[i+1][j]='D';
                d[i+1][j]=d[i][j]+1;
                q.add(new int[]{i+1,j});
            }
            if(j+1<m&&!state[i][j+1]&&map[i][j+1]!='#'){
                state[i][j+1]=true;
                pi[i][j+1]='R';
                d[i][j+1]=d[i][j]+1;
                q.add(new int[]{i,j+1});
            }
            if(i-1>=0&&!state[i-1][j]&&map[i-1][j]!='#'){
                state[i-1][j]=true;
                pi[i-1][j]='U';
                d[i-1][j]=d[i][j]+1;
                q.add(new int[]{i-1,j});
            }
            if(j-1>=0&&!state[i][j-1]&&map[i][j-1]!='#'){
                state[i][j-1]=true;
                pi[i][j-1]='L';
                d[i][j-1]=d[i][j]+1;
                q.add(new int[]{i,j-1});
            }
        }
        return pi;
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
