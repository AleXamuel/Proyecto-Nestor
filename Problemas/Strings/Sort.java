//https://codeforces.com/contest/1996/problem/C
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Pruebas {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        int ti=sc.nextInt();
        for (int times = 0; times < ti; times++) {
            int n=sc.nextInt();
            int q=sc.nextInt();
            String s=sc.next();
            String t=sc.next();
            int[][] prefixS=prefix(s,n);
            int[][] prefixT=prefix(t,n);
            /*for (int[] i:prefixS)
                System.out.println(Arrays.toString(i));
            System.out.println("sf");
            for (int[] i:prefixS)
                System.out.println(Arrays.toString(i));*/
            for (int i = 0; i < q; i++) {
                int ans=0;
                int l=sc.nextInt()-1;
                int r=sc.nextInt()-1;
                for (int j = 0; j < 26; j++) {
                    int a;
                    int b;
                    if(l==0){
                        a=prefixS[r][j];
                        b=prefixT[r][j];
                    }
                    else{
                        //System.out.println(l);
                        a=prefixS[r][j]-prefixS[l-1][j];
                        b=prefixT[r][j]-prefixT[l-1][j];
                    }
                    ans+=Math.abs(a-b);
                }
                System.out.println(ans/2);
            }
        }
    }
    static int[][] prefix(String s, int n){
        int[][] prefix=new int[n][26];
        for (int i = 0; i < s.length(); i++) {
            prefix[i][s.charAt(i)-'a']++;
            if(i>0)
                for (int j = 0; j < 26; j++)
                    prefix[i][j]+=prefix[i-1][j];
        }
        return prefix;
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
