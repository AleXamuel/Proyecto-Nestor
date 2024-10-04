//https://vjudge.net/problem/UVA-10685
import java.util.*;
import java.io.*;
public class Main {
    static int[] pi;
    static int[] size;
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        PrintWriter pw = new PrintWriter(System.out);
        while (true){
            int n=sc.nextInt();
            int m=sc.nextInt();
            pi=new int[n];
            size=new int[n];
            if(n==0)break;
            HashMap<String,Integer> map=new HashMap<>();
            for(int i =0;i<n;i++) {
                map.put(sc.next(), i);
                pi[i]=i;
                size[i]=1;
            }
            for (int i = 0; i < m; i++)
                union(map.get(sc.next()),map.get(sc.next()));
            int ans=0;
            for (int i = 0; i < n; i++)
                ans=Math.max(ans,size[i]);
            System.out.println(ans);
        }
    }
    static int find(int x){
        int y=x;
        while(x!=pi[x])
            x=pi[x];
        while (y!=pi[y]){
            y=pi[y];
            pi[y]=x;
        }
        return x;
    }
    static void union(int a, int b){
        int x=find(a),y=find(b);
        if (x==y)
            return;
        if(size[x]<size[y]){
            pi[x]=y;
            size[y]+=size[x];
        }
        else {
            pi[y]=x;
            size[x]+=size[y];
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
