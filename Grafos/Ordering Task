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
			String line = in.readLine();
			StringTokenizer st = new StringTokenizer(line, " ");
			N = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			if (N == 0 && m == 0)
				break;
			adj = new ArrayList[N + 1];
			for (int i = 0; i < N + 1; i++)
				adj[i] = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				String edges = in.readLine();
				st = new StringTokenizer(edges, " ");
				adj[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
			}

			System.out.println(ans(top_sort()));

		}

	}

	static String ans(int[] arr) {
		String solve = "";
		for (int i : arr)
			if (i != 0)
				solve += i+" ";
		return solve;

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

	static int[] top_sort() {
		d = new int[N + 1];
		t = new int[N + 1];
		time = 1;
		tsort = new Stack<>();
		for (int u = 0; u < N + 1; u++)
			if (d[u] == 0)
				dfs(u);
		int[] tsort_arr = new int[N + 1];
		for (int i = 0; i < N + 1; i++)
			tsort_arr[i] = tsort.pop();
		return tsort_arr;
	}

}
