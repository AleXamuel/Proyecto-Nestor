static ArrayList<Integer>[] adj;
static boolean[] state;
static int[] d;
static int[] pi;
static void bfs(int s){
    pi[s]=-1;
    d[s]=0;
    state[s]=true;
    Queue<Integer> q=new LinkedList<>();
    q.add(s);
    while(!q.isEmpty()){
        int u=q.poll();
        for(int v:adj[u]){
            if(!state[v]){
                pi[v]=u;
                d[v]=d[u]+1;
                state[v]=true;
                q.add(v);
            }
        }
    }
}
