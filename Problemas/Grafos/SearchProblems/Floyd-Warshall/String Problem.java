//https://codeforces.com/contest/33/problem/B
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String args[]) {
        Scanner sc=new Scanner();
        String s=sc.next();
        String t=sc.next();
        int m=sc.nextInt();
        int[][] madj=new int[26][26];
        for(int[] i:madj)
            Arrays.fill(i,Integer.MAX_VALUE);
        for(int i =0; i<26;i++)
            madj[i][i]=0;
        for(int i =0;i<m;i++){
            int u=sc.nextChar()-'a';
            int v=sc.nextChar()-'a';
            int w=sc.nextInt();
            madj[u][v]=Math.min(madj[u][v],w);
        }
        if(s.length()!=t.length()){
            System.out.println(-1);
            return;
        }
        floydWarshall(madj);
        StringBuilder ans= new StringBuilder();
        int c=0;
        for(int i =0;i<s.length();i++){
            int u = s.charAt(i)-'a';
            int v = t.charAt(i)-'a';
            if(u==v) {
                ans.append(s.charAt(i));
                continue;
            }
            int w=Integer.MAX_VALUE;
            int k=-1;
            for (int j = 0; j < 26; j++) {
                if(madj[u][j]!=Integer.MAX_VALUE&&madj[v][j]!=Integer.MAX_VALUE&&madj[u][j]+madj[v][j]<w){
                    w=Math.min(w,madj[u][j]+madj[v][j]);
                    k=j;
                }
            }
            if(w==Integer.MAX_VALUE){
                System.out.println(-1);
                return;
            }
            ans.append((char) (k + 'a'));
            c+=w;
        }
        System.out.println(c);
        System.out.println(ans);


    }
    static void floydWarshall(int[][] res) {
        int N=res.length;
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (res[i][k] < Integer.MAX_VALUE && res[k][j] < Integer.MAX_VALUE)
                        res[i][j] = Math.min(res[i][j], res[i][k] + res[k][j]);

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

        char Char() throws IOException {
            return (char) br.read();
        }
        char nextChar(){
            return next().charAt(0);
        }

    }
}
