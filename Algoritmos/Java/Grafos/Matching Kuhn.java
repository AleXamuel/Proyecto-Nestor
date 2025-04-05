static boolean tryKuhn(int u){
    if(state[u])
        return false;
    state[u]=true;
    for (int v:adj[u])
        if(mt[v]==-1||tryKuhn(mt[v])){
            mt[v]=u;
            return true;
        }
    return false;
}
