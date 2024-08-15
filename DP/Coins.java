// https://vjudge.net/problem/AtCoder-dp_i
import java.io.*;
import java.util.*;
public class Main{
    static double[][] dp;
    static double[] p;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int n=sc.nextInt();
        p=new double[n+1];
        for (int i = 1; i <= n; i++)
            p[i]=sc.nextDouble();
        //System.out.println("popote");
        dp=new double[n+1][n+1];
        dp[0][0]=1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <=i ; j++) {
                if(j==0)
                    dp[i][j]=dp[i-1][j]*(1-p[i]);
                else
                    dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
            }
        }
        double c=0;
        for (int i = n; i >n/2 ; i--)
            c+=dp[n][i];
        System.out.println(c);
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
        char nextChar(){
            return next().charAt(0);
        }

    }
}
