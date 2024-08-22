#https://codeforces.com/problemset/problem/939/A
#Samu:
n=int(input())
adj=[int(i) for i in input().split()]
r=False
for i in range(n):
    a=adj[i]-1
    b=adj[a]-1
    c=adj[b]-1
    if(c==i):
        r=True
print("YES" if r else "NO")

#Ian:
public class LoveTriangle {
	static ArrayList<Integer> adj[];

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		int[] vertex = new int[n];
		for (int i = 0; i < n; i++)
			vertex[i] = in.nextInt();
		for (int i = 0; i < n; i++) {
			int u = vertex[i];
			adj[u - 1].add(vertex[u - 1] - 1);
		}
		boolean[] visited = new boolean[n];
		for (int i = 0; i < n; i++)
			if (!visited[i])
				if (bfs(i, visited)) {
					System.out.println("YES");
					return;
				}
		System.out.println("NO");

	}

	static boolean bfs(int s, boolean[] visited) {
		ArrayList<Integer> ciclos = new ArrayList<>();
		Queue<Integer> Q = new LinkedList<>();
		Stack<Integer> S = new Stack<>();
		Q.add(s);
		visited[s] = true;
		while (!Q.isEmpty()) {
			int u = Q.poll();
			S.push(u);
			for (int v : adj[u])
				if (!visited[v]) {
					visited[v] = true;
					Q.add(v);
				} else if (S.contains(v)) {
					int t = S.pop();
					ciclos.add(t);
					while (t != v) {
						t = S.pop();
						ciclos.add(t);
					}
					if (ciclos.size() == 3)
						return true;
					else
						ciclos.clear();
				}
		}
		return false;
	}
}
