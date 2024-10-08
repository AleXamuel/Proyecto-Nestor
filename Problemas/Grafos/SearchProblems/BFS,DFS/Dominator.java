//https://vjudge.net/problem/UVA-11902
import java.util.*;
import java.io.*;
public class Main {
    static int n;
    static ArrayList<Integer>[] adj;
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int ti=sc.nextInt();
        for (int times = 1; times <= ti; times++) {
            n=sc.nextInt();
            adj=new ArrayList[n];
            for (int i = 0; i < n; i++)
                adj[i]=new ArrayList<>();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    int c = sc.nextInt();
                    if (c == 1)
                        adj[i].add(j);
                }
            out.println("Case " + times + ":");
            printFastidio();
            boolean[] state=bfs(0,-1);
            out.print("|");
            for (int i = 0; i < n; i++)
                out.print(state[i] ? "Y|" : "N|");
            out.println();
            printFastidio();
            for (int i = 1; i < n; i++) {
                out.print("|");
                boolean[] dom;
                if(state[i]) {
                    dom = bfs(0, i);
                    for (int j = 0; j < n; j++)
                        out.print((state[j] && !dom[j]) ? "Y|" : "N|");
                }
                else{
                    for (int j = 0; j < n; j++)
                        out.print("N|");
                }
                out.println();
                printFastidio();
            }
        }
        out.close();

    }
    static void printFastidio() {
        out.print("+");
        for (int i = 0; i < 2 * n - 1; i++)
            out.print("-");
        out.println("+");
    }

    static boolean[] bfs(int s,int skip){
        boolean[] state=new boolean[n];
        state[s]=true;
        Queue<Integer> q=new LinkedList<>();
        q.add(s);
        while(!q.isEmpty()){
            int u=q.poll();
            for (int v:adj[u]){
                if(!state[v]&&v!=skip){
                    state[v]=true;
                    q.add(v);
                }
            }
        }
        return state;
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
