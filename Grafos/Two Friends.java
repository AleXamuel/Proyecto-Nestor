

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TwoFriends {
    static HashSet<Integer>[] adjList;
    static boolean[] state;
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(bf.readLine());
        for (int times = 0; times < t; times++) {
            int n=Integer.parseInt(bf.readLine());
            adjList=new HashSet[n+1];
            state=new boolean[n+1];
            for (int i = 1; i <= n; i++)
                adjList[i]=new HashSet<>();
            String[] l1=bf.readLine().split(" ");
            for (int i = 1; i <=n ; i++) {
                int a=Integer.parseInt(l1[i-1]);
                addEdge(i,a);
            }
            TreeSet<Integer> ans= new TreeSet<>();
            boolean f=false;
            for (int i = 1; i <=n ; i++) {
                if(!state[i]){
                    int a=bfs(i);
                    if(a==2){
                        System.out.println(2);
                        f=true;
                        break;
                    }
                    ans.add(a);
                }
            }
            if(!f)
                System.out.println(ans.pollFirst());
        }
    }
    static int bfs(int s) {
        state[s] = true;
        Queue<Integer> Q = new LinkedList<Integer>();
        Q.add(s);
        while (!Q.isEmpty()) {
            int u = Q.poll();
            for(int v : adjList[u]) {
                if(adjList[v].contains(u))
                    return 2;
                if (!state[v]) {
                    state[v] =true;
                    Q.add(v);
                }
            }
            state[u] = true;
        }
        return 3;
    }
    static void addEdge(int a, int b){
        adjList[a].add(b);
    }
}
