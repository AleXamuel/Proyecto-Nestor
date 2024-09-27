import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class MazeMovement {
    static int INF = Integer.MAX_VALUE;

    static int n;
    static int[][] capacity;
    static ArrayList<Integer>[] adj;
    public static void main(String[] args)throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(bf.readLine());
        int[] datos=new int[n];
        TreeMap<Integer,Integer> indices=new TreeMap<>();
        adj=new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        capacity=new int[n][n];
        for (int i = 0; i < n; i++) {
            int v=Integer.parseInt(bf.readLine());
            datos[i] = v;
            indices.put(v,i);
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int v=gcd(datos[i],datos[j]);
                if(v>1){
                    adj[i].add(j);
                    adj[j].add(i);
                    capacity[i][j]=v;
                    capacity[j][i]=v;
                }

            }
        }
        int min=indices.pollFirstEntry().getValue();
        int max=indices.pollLastEntry().getValue();
        //System.out.println(Arrays.toString(adj));
        System.out.println(maxflow(min,max));

    }
    static int gcd(int n1, int n2) {
        if (n2 == 0) {
            return n1;
        }
        return gcd(n2, n1 % n2);
    }
    static boolean bfs(int s, int t, int[] parent){
        boolean[] visited=new boolean[n];
        Queue<Integer> q=new LinkedList<>();
        q.add(s);
        parent[s]=-1;
        visited[s]=true;
        while (!q.isEmpty()){
            int cur=q.poll();
            for(int n:adj[cur]){
                if(!visited[n]&&capacity[cur][n]>0){
                    parent[n]=cur;
                    visited[n]=true;
                    q.add(n);
                    if(n==t)
                        return true;
                }
            }
        }
        return false;
    }
    static int maxflow(int s, int t){
        int[] pi=new int[n];
        int maxflow=0;
        while (bfs(s,t,pi)){
            int flow=INF;
            for(int cur=t;cur!=s;cur=pi[cur]){
                int p=pi[cur];
                flow=Math.min(flow,capacity[p][cur]);
            }
            for (int cur = t; cur != s; cur = pi[cur]) {
                int p = pi[cur];
                capacity[p][cur] -= flow;
                capacity[cur][p] += flow;
            }

            maxflow += flow;
        }
        return maxflow;
    }


}
