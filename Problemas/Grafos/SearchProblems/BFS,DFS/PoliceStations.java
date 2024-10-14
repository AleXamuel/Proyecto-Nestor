//https://codeforces.com/problemset/problem/796/D
import java.util.*;
import java.awt.Point;
import java.io.*;

public class PoliceStations {
	static int n;
	static ArrayList<Point>[] adj;
	static Queue<Integer> Q;
	static boolean[] visited;
	static boolean[] edges;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		PrintWriter out = new PrintWriter(System.out);
		n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st.nextElement();
		Q = new LinkedList<>();
		visited = new boolean[n];
		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < k; i++) {
			int p = Integer.parseInt(st.nextToken()) - 1;
			Q.add(p);
			visited[p] = true;
		}
		adj = new ArrayList[n];
		edges = new boolean[n - 1];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adj[a].add(new Point(b, i));
			adj[b].add(new Point(a, i));
		}
		bfs();
		List<Integer> ans = new ArrayList<>();
		for (int i = 0; i < edges.length; i++)
			if (!edges[i])
				ans.add(i + 1);
		out.println(ans.size());
		ans.forEach(x -> out.print(x + " "));
		out.flush();
	}

	static void bfs() {
		while (!Q.isEmpty()) {
			int u = Q.poll();
			for (Point ee : adj[u]) {
				int v = ee.x;
				int index = ee.y;
				if (!visited[v]) {
					visited[v] = true;
					Q.add(v);
					edges[index] = true;
				}
			}
		}
	}

}
