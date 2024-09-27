//https://codeforces.com/contest/736/problem/B
import java.util.*;
import java.io.*;

public class Pruebas {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int n=sc.nextInt();
        if(isPrime(n))
            System.out.println(1);
        else if(n%2==0||isPrime(n-2))
            System.out.println(2);
        else
            System.out.println(3);
    }
    static boolean isPrime(int n){
        if(n<2)
            return false;
        if(n<4)
            return true;
        for (int i = 2; i*i <=n ; i++)
            if(n%i==0)
                return false;

        return true;
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
