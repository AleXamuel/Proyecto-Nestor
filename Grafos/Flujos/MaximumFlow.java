import java.util.*;
import java.io.*;
class MaximunFLow {
    static int INF = Integer.MAX_VALUE;
    static int n;
    static int[][] capacity;
    static int[][] flowEdges;
    static ArrayList<Integer>[] adj;
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] l1 = bf.readLine().split(" ");
        n = Integer.parseInt(l1[0]);
        int m = Integer.parseInt(l1[1]);
        int s = Integer.parseInt(l1[2]);
        int t = Integer.parseInt(l1[3]);
        adj=new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i]=new ArrayList<>();
        capacity=new int[n][n];
        flowEdges=new int[n][n];
        for (int i = 0; i < m; i++) {
            String[] l2 = bf.readLine().split(" ");
            int a = Integer.parseInt(l2[0]);
            int b = Integer.parseInt(l2[1]);
            int c = Integer.parseInt(l2[2]);
            adj[a].add(b);
            adj[b].add(a);
            capacity[a][b]=c;

        }
        int res=maxflow(s,t);
        LinkedList<int[]> l=new LinkedList<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(flowEdges[i][j]>0)
                    l.add(new int[]{i,j,flowEdges[i][j]});
        System.out.println(n+" "+res+" "+l.size());
        for (int[] i:l)
            System.out.println(i[0]+" "+i[1]+" "+i[2]);

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
                flowEdges[p][cur] += flow;
                flowEdges[cur][p] -= flow;
                capacity[p][cur] -= flow;
                capacity[cur][p] += flow;
            }

            maxflow += flow;
        }
        return maxflow;
    }
}
