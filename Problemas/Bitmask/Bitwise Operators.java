//https://vjudge.net/problem/CodeChef-NXS2
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter out = new PrintWriter(System.out);
        int tim = sc.nextInt();
        for (int times = 0; times < tim; times++) {
            int n=sc.nextInt();
            int aux=n;
            if(n%2!=0)
                System.out.println(1+" "+(n-1));
            else{
                int i=0;
                while (true){
                    n=n>>1;
                    i++;
                    if(n%2==1)
                        break;
                }
                if(1<<i==aux)
                    System.out.println(-1);
                else
                    System.out.println((1<<i)+" "+((n>>1)<<i+1));
            }


        }


    }

    public static int llcs(String pat, String alph) {
        int m = pat.length();
        int n = alph.length();
        int[][] lcs = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pat.charAt(i - 1) == alph.charAt(j - 1))
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                else
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        return lcs[m][n];
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        char nextChar() {
            return next().charAt(0);
        }

    }
}
