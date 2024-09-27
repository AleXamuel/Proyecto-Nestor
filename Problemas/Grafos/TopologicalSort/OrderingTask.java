/* https://vjudge.net/problem/UVA-10305 */

import java.io.*;
import java.util.*;

public class OrderingTasks {

    static int n;
    static int time;
    static ArrayList<Integer>[] adj;
    static boolean[] state;
    static int[] d; //tiempo descubrimiento de cada vertice
    static int[] t; //tiempo de finalizacion de cada vertice(vecinos ya visitads del vertice actual)
    static  Stack<Integer>Toposort;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while (true){
            StringTokenizer st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if(n==0 && m ==0) break;
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(in.readLine());
                int a = Integer.parseInt(st.nextToken()) -1;
                int b = Integer.parseInt(st.nextToken()) -1;
                adj[a].add(b);
            }
            System.out.println(String.join(" ",TopSort()));

        }
    }

    static void dfs(int s){
        d[s] = time;
        time++;
        state[s] = true;
        for(int v: adj[s])
            if(!state[v])
                dfs(v);
        t[s] = time;
        time++;
        Toposort.push(s);
    }

    static String[] TopSort() {
        time = 1;
        d = new int[n];
        t = new int[n];
        state = new boolean[n];
        Toposort = new Stack<>();
        for (int i = 0; i < n; i++)
            if (!state[i]) dfs(i);
        String[] ans = new String[n];
        for (int i = 0;i<n;i++)
            ans[i] = String.valueOf(Toposort.pop() + 1);
        return ans;
    }
}
