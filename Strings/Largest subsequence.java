//https://codeforces.com/problemset/problem/1905/C
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner();
        int t=sc.nextInt();
        for (int times = 0; times < t; times++) {
            int n=sc.nextInt();
            String r="!"+sc.next();
            char[] s=r.toCharArray();
            Stack<Integer> q=new Stack<>();
            for (int i = 1; i <= n; i++) {
                while (!q.isEmpty()&&s[q.peek()]<s[i])
                    q.pop();
                q.add(i);
            }
            int[] arr=new int[q.size()];
            for (int i = q.size()-1; i >=0; i--) {
                int a=q.pop();
                arr[i] = a;
            }
            int ans=0;
            int m=arr.length-1;
            while (ans<=m&&s[arr[ans]]==s[arr[0]])
                ans++;
            ans=m-ans+1;
            for (int i = 0; i <= m; i++) {
                if(i<m-i){
                    char aux=s[arr[i]];
                    s[arr[i]]=s[arr[m-i]];
                    s[arr[m-i]]=aux;
                }
            }
            for (int i =1;i<s.length-1;i++)
                if(s[i]>s[i+1]){
                    ans=-1;
                    break;
                }
            System.out.println(ans);
        }
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
        char nextChar() throws IOException {
            return (char) br.read();
        }

    }

}
