//https://codeforces.com/problemset/problem/2010/C1
import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner();
        String s=sc.next();
        int n=s.length();
        if(n<3){
            System.out.println("NO");
            return;
        }
        int i=s.length()/2,j=s.length()/2;
        if(n%2==0)
            i--;
        for (int k=0;k<n/2;k++) {
            if(i==0)
                break;
            if(s.substring(0,j+1).equals(s.substring(i,n))){
                System.out.println("YES");
                System.out.println(s.substring(0,j+1));
                return;
            }
            i--;
            j++;
        }
        System.out.println("NO");
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
