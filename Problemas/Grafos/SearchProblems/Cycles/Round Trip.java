//https://vjudge.net/problem/CSES-1669
import java.util.*;
import java.io.*;
public class Main {
    static int n;
    static ArrayList<Integer>[] adj;
    static boolean[] state;
    static int[] pi;
    static int cycleStart, cycleEnd;
    public static void main(String args[]) {
        Scanner sc=new Scanner();
        PrintWriter pw=new PrintWriter(System.out);
        n=sc.nextInt();
        int m=sc.nextInt();
        adj=new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        LinkedList<Integer> ans=cycle();
        if(ans==null){
            System.out.println("IMPOSSIBLE");
            return;
        }
        pw.println(ans.size());
        pw.print(ans.removeFirst()+1);
        for(int i : ans)
            pw.print(" "+(i+1));
        pw.close();


    }
    static boolean dfs(int u, int par){
        state[u]=true;
        for (int v:adj[u]){
            if(v==par) continue;
            if(state[v]){
                cycleStart=v;
                cycleEnd=u;
                return true;
            }
            pi[v]=u;
            if(dfs(v,u)) return true;
        }
        return false;
    }
    static LinkedList<Integer> cycle(){
        LinkedList<Integer> ans=new LinkedList<>();
        state=new boolean[n];
        pi=new int[n];
        Arrays.fill(pi,-1);
        cycleStart=-1;
        for (int u = 0; u < n; u++)
            if(!state[u]&&dfs(u,pi[u]))
                break;
        if(cycleStart==-1)
            return null;
        ans.add(cycleStart);
        for(int u=cycleEnd; u!=cycleStart; u=pi[u])
            ans.add(u);
        ans.add(cycleStart);
        return ans;

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
        char nextChar(){
            return next().charAt(0);
        }

    }
}
