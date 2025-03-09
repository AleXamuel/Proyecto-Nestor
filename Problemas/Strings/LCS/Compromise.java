//https://vjudge.net/problem/UVA-531
import java.io.*;
import java.util.*;
public class Main{
    static double[][] dp;
    static double[] p;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        while (true) {
            String s = sc.nextLine();
            if (s == null || s.isEmpty())
                return;
            while (true){
                String r=sc.nextLine();
                if(r.equals("#"))
                    break;
                s+=" "+r;
            }
            String t=sc.nextLine();
            while (true){
                String r=sc.nextLine();
                if(r.equals("#"))
                    break;
                t+=" "+r;
            }
            String[] s1=s.split(" ");
            String[] s2=t.split(" ");
            String[] ans=findLCS(s1,s2);
            for (int i = 0; i < ans.length; i++) {
                if(i==0)
                    System.out.print(ans[i]);
                else
                    System.out.print(" "+ans[i]);
            }
            System.out.println();
        }
    }
    public static String[] findLCS(String[] s1, String[] s2) {
        int m = s1.length;
        int k = s2.length;
        int[][] dp = new int[m + 1][k + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                if (s1[i - 1].equals(s2[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int index = dp[m][k];
        String[] lcs = new String[index];
        int i = m, j = k;

        while (i > 0 && j > 0) {
            if (s1[i - 1].equals(s2[j - 1])) {
                lcs[--index] = s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return lcs;
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
                    return "";
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
        char nextChar(){
            return next().charAt(0);
        }

    }
}
