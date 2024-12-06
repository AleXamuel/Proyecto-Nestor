//https://codeforces.com/gym/105505/problem/B

import java.util.*;
import java.io.*;

public class Biketopia {
    static ArrayList<pair>[] adj;
    static int d[];
    static int time;
    static int maxTime;
    static int U;
    static int V;
    static pair[] pi;
    static int maxEdge;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            adj[a].add(new pair(b, i + 1));
            adj[b].add(new pair(a, i + 1));
        }
        d = new int[n];
        time = 1;
        maxTime = -1;
        pi = new pair[n];
        maxEdge = -1;
        dfs(0, -1, -1);
        out.print(maxEdge + " ");
        int i = 1;
        while (V != U) {
            pair e = pi[V];
            V = e.first;
            maxEdge = e.second;
            i++;
            out.print(maxEdge + " ");
        }
        System.out.println(i);
        out.flush();
    }

    static void dfs(int u, int par, int edge) {
        pi[u] = new pair(par, edge);
        d[u] = time++;
        for (pair ee : adj[u]) {
            int v = ee.first;
            int e = ee.second;
            if (v == par)
                continue;
            if (d[v] == 0)
                dfs(v, u, e);
            else {
                int depth = Math.min(d[u], d[v]);
                if (depth > maxTime) {
                    maxTime = depth;
                    if (depth == d[u]) {
                        U = u;
                        V = v;
                    } else {
                        U = v;
                        V = u;
                    }
                    maxEdge = e;
                }
            }
        }
    }

    static class pair {
        int first;
        int second;

        pair(int f, int s) {
            this.first = f;
            this.second = s;
        }
    }
}
