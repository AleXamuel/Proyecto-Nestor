/* https://vjudge.net/problem/SPOJ-SUBMERGE */

import java.io.*;
import java.util.*;

public class SubmergingIslands {
    static int n;
    static ArrayList<Integer>[] adj;
    static int[] d, low;
    static int time;
    static Boolean[] ap;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            StringTokenizer st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n==0 && m==0) break;
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(in.readLine());
                int a = Integer.parseInt(st.nextToken())-1;
                int b = Integer.parseInt(st.nextToken())-1;
                adj[a].add(b);
                adj[b].add(a);
            }
            get_articulation_points();
            System.out.println(Arrays.stream(ap).filter(x->x).count());
        }
    }

    static void dfs(int u, int par) {
        d[u] = time++;
        low[u] = d[u];
        int children = 0;
        for(int v:adj[u]) {
            if (v==par) continue;
            else if (d[v]>0)
                low[u] = Math.min(low[u], d[v]);
            else {
                children++;
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (par!=-1 && low[v]>=d[u]) ap[u] = true;
            }
        }
        if (par==-1 && children>1) ap[u] = true;
    }

    static void get_articulation_points() {
        d = new int[n];
        low = new int[n];
        time = 1;
        ap = new Boolean[n];
        Arrays.fill(ap,false);
        dfs(0, -1);
    }
}
