//https://vjudge.net/problem/UVA-11512
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        int ti = sc.nextInt();
        for (int times = 0; times < ti; times++) {
            String s=sc.next();
            int[] p=suffix_array_construction(s);
            int[] ans=lcpConstruction(s,p);
            int max=0,rep=-1,j=-1;
            for (int i = 0; i < ans.length; i++) {
                if(ans[i]>max){
                    max=ans[i];
                    j=i;
                    rep=2;
                    while (i<ans.length-1 && ans[i+1]==max){
                        rep++;
                        i++;
                    }
                }
            }
            if(rep==-1)
                pw.println("No repetitions found!");
            else
                pw.println(s.substring(p[j],p[j]+max)+" "+rep);
        }
        pw.close();
    }

    static int[] suffix_array_construction(String s) {
        s += "$";
        int[] sorted_shifts = sortCyclicShifts(s);
        return Arrays.copyOfRange(sorted_shifts, 1, sorted_shifts.length);
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
