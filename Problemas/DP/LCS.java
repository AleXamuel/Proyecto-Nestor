//https://vjudge.net/problem/AtCoder-dp_f
import java.io.*;
import java.util.*;
public class Main{
    static double[][] dp;
    static double[] p;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        String s=sc.nextLine();
        String t=sc.nextLine();
        System.out.println(findLCS(s,t));
    }
    public static String findLCS(String s1, String s2) {
        int m = s1.length();
        int k = s2.length();
        int[][] dp = new int[m + 1][k + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                if (s1.charAt(i-1)==s2.charAt(j-1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int index = dp[m][k];
        char[] lcs = new char[index];
        int i = m, j = k;

        while (i > 0 && j > 0) {
            if (s1.charAt(i-1)==s2.charAt(j-1))  {
                lcs[--index] = s1.charAt(i-1);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return new String(lcs);
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
