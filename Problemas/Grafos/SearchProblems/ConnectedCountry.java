// https://vjudge.net/problem/SPOJ-CONGRAPH
import java.util.*;
import java.io.*;

public class Main {

	static int n, m;
	static ArrayList<Integer>[] adjList;
	static char state[];

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		adjList = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adjList[i] = new ArrayList<>();
		state = new char[n];
		Arrays.fill(state, 'N');
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			addEdge(a, b);
		}
		System.out.println(solve(0));

	}

	static int solve(int s) {
		int ans = 0;
		dfs(s);
		for (int i = 0; i < state.length; i++)
			if (state[i] == 'N') {
				ans++;
				bfs(i);
			}
		return ans;

	}

	static void bfs(int s) {
		state[s] = 'D';
		Queue<Integer> Q = new LinkedList<Integer>();
		Q.add(s);
		while (!Q.isEmpty()) {
			int u = Q.poll();
			for (int v : adjList[u])
				if (state[v] == 'N') {
					state[v] = 'D';
					Q.add(v);
				}
			state[u] = 'E';
		}
	}

	static void addEdge(int a, int b) {
		adjList[a].add(b);
		adjList[b].add(a);
	}

}
