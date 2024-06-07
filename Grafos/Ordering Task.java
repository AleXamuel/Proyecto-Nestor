import java.io.*;
import java.util.*;

public class OrderingTasks {
	static ArrayList<Integer>[] adj;
	static int[] d, t;
	static int N;
	static int time;
	static Stack<Integer> tsort;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			if (N == 0 && m == 0)
				break;
			adj = new ArrayList[N];
			for (int i = 0; i < N; i++)
				adj[i] = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				adj[Integer.parseInt(st.nextToken()) - 1].add(Integer.parseInt(st.nextToken()) - 1);
			}

			System.out.println(String.join(" ", top_sort()));

		}

	}

	static void dfs(int u) {
		d[u] = time++;
		for (int v : adj[u]) {
			if (d[v] != 0)
				continue;
			dfs(v);
		}
		t[u] = time++;
		tsort.add(u);
	}

	static String[] top_sort() {
		d = new int[N];
		t = new int[N];
		time = 1;
		tsort = new Stack<>();
		for (int u = 0; u < N; u++)
			if (d[u] == 0)
				dfs(u);
		String[] tsort_arr = new String[N];
		for (int i = 0; i < N; i++)
			tsort_arr[i] = String.valueOf(tsort.pop() + 1);
		return tsort_arr;
	}

}
