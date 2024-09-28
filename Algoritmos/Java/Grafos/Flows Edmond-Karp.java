static int INF = Integer.MAX_VALUE;
static int n;
static int[][] capacity;
static ArrayList<Integer>[] adj;
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
