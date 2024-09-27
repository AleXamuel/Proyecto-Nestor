// https://codeforces.com/problemset/problem/1985/H1
import java.io.*;
import java.util.*;

public class Main {
    static char[][] map;
    static boolean[][] state;
    static int[][] group;
    static HashMap<Integer,Integer> grupos=new HashMap<>();
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner();
        int t=sc.nextInt();
        for (int times = 0; times < t; times++) {
            int n=sc.nextInt();
            int m=sc.nextInt();
            map=new char[n][m];
            group=new int[n][m];
            state=new boolean[n][m];
            for (int i = 0; i < n; i++)
                map[i]=sc.next().toCharArray();
            int g=1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(map[i][j]=='#'&&!state[i][j]) {
                        bfs(i, j, g);
                        g++;
                    }
                }
            }
            int row=row();
            int column=column();

            System.out.println(Math.max(row,column));
        }
    }
    static int row(){
        int c=0;
        for (int i = 0; i < map.length; i++) {
            int r=0;
            HashSet<Integer> set=new HashSet<>();
            for (int j = 0; j < map[0].length; j++) {
                if(map[i][j]=='.')
                    r++;
                else if(!set.contains(group[i][j])) {
                    r += grupos.get(group[i][j]);
                    set.add(group[i][j]);
                }
                if(i-1>=0&&map[i-1][j]=='#'&&!set.contains(group[i-1][j])){
                    set.add(group[i-1][j]);
                    r+=grupos.get(group[i-1][j]);
                }
                if(i+1<map.length&&map[i+1][j]=='#'&&!set.contains(group[i+1][j])){
                    set.add(group[i+1][j]);
                    r+=grupos.get(group[i+1][j]);
                }
            }
            c= Math.max(c,r);
        }


        return c;
    }
    static int column(){
        int c=0;
        for (int i = 0; i < map[0].length; i++) {
            int r=0;
            HashSet<Integer> set=new HashSet<>();
            for (int j = 0; j < map.length; j++) {

                if(map[j][i]=='.')
                    r++;
                else if(!set.contains(group[j][i])) {
                    r += grupos.get(group[j][i]);
                    set.add(group[j][i]);
                }

                if(i-1>=0&&map[j][i-1]=='#'&&!set.contains(group[j][i-1])){
                    set.add(group[j][i-1]);
                    r+=grupos.get(group[j][i-1]);
                }
                if(i+1<map[0].length&&map[j][i+1]=='#'&&!set.contains(group[j][i+1])){
                    set.add(group[j][i+1]);
                    r+=grupos.get(group[j][i+1]);
                }
            }
            c= Math.max(c,r);
        }


        return c;
    }
    static void bfs(int a, int b, int g){
        int[] s={a,b};
        grupos.put(g,1);
        group[a][b]=g;
        state[a][b]=true;
        Queue<int[]> q=new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()){
            int[] u=q.poll();
            int i=u[0];
            int j=u[1];
            if(i+1<map.length&&map[i+1][j]=='#'&&!state[i+1][j]){
                state[i+1][j]=true;
                group[i+1][j]=g;
                grupos.put(g,grupos.get(g)+1);
                q.add(new int[]{i+1,j});
            }
            if(i-1>=0&&map[i-1][j]=='#'&&!state[i-1][j]){
                state[i-1][j]=true;
                group[i-1][j]=g;
                grupos.put(g,grupos.get(g)+1);
                q.add(new int[]{i-1,j});
            }
            if(j+1<map[0].length&&map[i][j+1]=='#'&&!state[i][j+1]){
                state[i][j+1]=true;
                group[i][j+1]=g;
                grupos.put(g,grupos.get(g)+1);
                q.add(new int[]{i,j+1});
            }
            if(j-1>=0&&map[i][j-1]=='#'&&!state[i][j-1]){
                state[i][j-1]=true;
                group[i][j-1]=g;
                grupos.put(g,grupos.get(g)+1);
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
