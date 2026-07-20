//this code solve the problem: counting all paths in the tree with length exactly K
vector<int> adj[MAX];
bool removed[MAX];
int subtree_size[MAX];
int K,n;
ll answer = 0;
int get_subtree_size(int v, int p = -1) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u == p || removed[u]) continue;
        subtree_size[v] += get_subtree_size(u, v);
    }
    return subtree_size[v];
}

int get_centroid(int v, int tree_size, int p = -1) {
    for (int u : adj[v]) {
        if (u == p || removed[u]) continue;
        if (subtree_size[u] * 2 > tree_size)
            return get_centroid(u, tree_size, v);
    }
    return v;
}

void get_distances(int v, int p, int dist, vector<int>& distances) {
    if (dist > K) return;
    distances.push_back(dist);
    for (int u : adj[v]) {
        if (u == p || removed[u]) continue;
        get_distances(u, v, dist + 1, distances);
    }
}
int F[MAX];
void process_centroid(int centroid) {
    vector<int>used;
    used.reserve(n);
    F[0]=1;
    used.pb(0);
    for (int u : adj[centroid]) {
        if (removed[u])
            continue;
        vector<int> current_distances;
        get_distances(u, centroid, 1, current_distances);
        for (int d : current_distances) {
            if (K - d >= 0) {
                answer += F[K-d];
            }
        }

        for (int d : current_distances) {
            if (F[d]==0)
                used.pb(d);
            F[d]++;
        }
    }
    for (int x:used)
        F[x]=0;
}

void decompose(int v) {
    int tree_size = get_subtree_size(v);
    int centroid = get_centroid(v, tree_size);
    process_centroid(centroid);
    removed[centroid] = true;
    for (int u : adj[centroid]) {
        if (!removed[u]) {
            decompose(u);
        }
    }
}
