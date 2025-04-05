//https://vjudge.net/problem/UVA-10878
import java.util.*;
import java.io.*;
public class Main {
    static int[] pi;
    static int[] size;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        PrintWriter out = new PrintWriter(System.out);
        sc.nextLine();
        while (true){
            String s=sc.nextLine();
            if(s.charAt(0)=='_')
                break;
            String ans="";
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i)==' ')
                    ans+='0';
                else if (s.charAt(i)=='o')
                    ans+='1';
            }
            out.print((char)Integer.parseInt(ans,2));
        }
        out.close();

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

        char nextChar() {
            return next().charAt(0);
        }

    }
}
