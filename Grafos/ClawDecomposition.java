

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
    static int[] pi;
    static ArrayList<Integer>[] adjList;
    static boolean[] state;
    static boolean[] grupo;
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            int n = Integer.parseInt(bf.readLine());
            if (n == 0)
                break;
            state=new boolean[n];
            adjList=new ArrayList[n];
            pi=new int[n];
            grupo=new boolean[n];
            for (int i = 0; i < n; i++)
                adjList[i]=new ArrayList<>();
            while (true){
                StringTokenizer st = new StringTokenizer(bf.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if(a==0 && b==0)
                    break;
                addEdge(a-1,b-1);

            }
            if(bfs(0))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }


    static boolean bfs(int s) {
        state[s]=true;
        pi[s]=-1;
        grupo[s]=true;
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for (int v : adjList[u]) {
                if (!state[v]) {
                    state[v] = true;
                    grupo[v] = !grupo[u];
                    Q.add(v);
                    pi[v] = u;
                }
                if (state[v])
                    if(pi[v]!=u)
                        if(grupo[v]==grupo[u])
                            return false;

            }
            state[u] = true;
        }
        return true;
    }

    static void addEdge(int a, int b) {
        adjList[a].add(b);
        adjList[b].add(a);
    }
}
