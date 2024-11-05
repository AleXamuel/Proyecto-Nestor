//https://vjudge.net/problem/UVA-1112
import java.io.*;
import java.util.*;

public class MiceAndMaze {
	static int n;
	static int[][] adj;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		for (int cases = 0; cases < T; cases++) {
			in.readLine();
			n = Integer.parseInt(in.readLine());
			int s = Integer.parseInt(in.readLine()) - 1;
			int time = Integer.parseInt(in.readLine());
			int m = Integer.parseInt(in.readLine());
			adj = new int[n][n];
			for (int[] i : adj)
				Arrays.fill(i, Integer.MAX_VALUE);
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1;
				int b = Integer.parseInt(st.nextToken()) - 1;
				int w = Integer.parseInt(st.nextToken());
				adj[a][b] = w;
			}
			floydWarshall();
			int c = 0;
			for (int i = 0; i < n; i++)
				if (adj[i][s] <= time)
					c++;
			out.println(c);
			if (cases < T - 1)
				out.println();
		}
		out.flush();

	}

	static void floydWarshall() {
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (adj[i][k] < Integer.MAX_VALUE && adj[k][j] < Integer.MAX_VALUE)
						adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);

	}
}
