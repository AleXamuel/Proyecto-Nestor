//https://vjudge.net/problem/SPOJ-LCS
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        int[] sum=new int[2];
        String s=sc.next()+'$';
        sum[0]=s.length();
        s+=sc.next()+'$';
        sum[1]=s.length();
        int[] p=suffix_array_construction(s);
        int[] lcp=lcpConstruction(s,p);
        int ans=0;
        //System.out.println(Arrays.toString(p));
        //System.out.println(Arrays.toString(lcp));
        for (int i = 2; i < p.length-1; i++)
            if(search(sum,p[i])!=search(sum,p[i+1])) {
                //System.out.println("akjbsdj");
                ans = Math.max(ans, lcp[i]);
            }
        System.out.println(ans);

    }
    static int search(int[] arr,int x){
        for (int i = 0; i < arr.length; i++) {
            if(x<arr[i])
                return i;
        }
        return arr.length-1;
    }

    static int[] suffix_array_construction(String s) {
        return sortCyclicShifts(s);
        //return Arrays.copyOfRange(sorted_shifts, 1, sorted_shifts.length);
    }

    public static int[] lcpConstruction(String s, int[] p) {
        int n = s.length();
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            rank[p[i]] = i;
        }
        int k = 0;
        int[] lcp = new int[n - 1];
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = p[rank[i] + 1];
            while (i + k < n && j + k < n && s.charAt(i + k) == s.charAt(j + k)) {
                k++;
            }
            lcp[rank[i]] = k;
            if (k > 0) {
                k--;
            }
        }
        return lcp;
    }

    public static int[] sortCyclicShifts(String s) {
        int n = s.length();
        int alphabet = 256;
        int[] p = new int[n];
        int[] c = new int[n];
        int[] cnt = new int[Math.max(alphabet, n)];
        for (int i = 0; i < n; i++)
            cnt[s.charAt(i)]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++)
            p[--cnt[s.charAt(i)]] = i;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(p[i]) != s.charAt(p[i - 1])) {
                classes++;
            }
            c[p[i]] = classes - 1;
        }

        int[] pn = new int[n];
        int[] cn = new int[n];
        for (int h = 0; (1 << h) < n; h++) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0) {
                    pn[i] += n;
                }
            }
            Arrays.fill(cnt, 0, classes, 0);
            for (int i = 0; i < n; i++) {
                cnt[c[pn[i]]]++;
            }
            for (int i = 1; i < classes; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                p[--cnt[c[pn[i]]]] = pn[i];
            }
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                int cur1 = c[p[i]];
                int cur2 = c[(p[i] + (1 << h)) % n];
                int prev1 = c[p[i - 1]];
                int prev2 = c[(p[i - 1] + (1 << h)) % n];
                if (cur1 != prev1 || cur2 != prev2) {
                    classes++;
                }
                cn[p[i]] = classes - 1;
            }
            int[] temp = c;
            c = cn;
            cn = temp;
        }
        return p;
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

        char nextChar() throws IOException {
            return (char) br.read();
        }

    }
}
