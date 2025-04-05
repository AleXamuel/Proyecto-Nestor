//https://vjudge.net/problem/CSES-1633
import java.io.*;
import java.util.*;
public class Main {
    static final int mod=1000000007;
    static int[] dp;
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        int n=sc.nextInt();
        dp=new int[n+1];
        dp[0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=6;j++)
                if(i-j>=0) {
                    dp[i] += dp[i - j];
                    dp[i]%=mod;
                }
        System.out.println(dp[n]);

    }
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

        long nextLong() {
            return Long.parseLong(next());
        }

        char nextChar() throws IOException {
            return (char) br.read();
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() throws Exception {
            return br.readLine();
        }

        public void close() throws IOException {
            br.close();
        }

        public boolean hasNext() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (Exception e) {
                return false;
            }
            return true;
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }

}
