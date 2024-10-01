//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1363
import java.util.*;
import java.io.*;

public class KnightsInFEN {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int n = Integer.parseInt(in.readLine());
		HashMap<Grid, Integer> d = bfs(new Grid(new char[][] { { '1', '1', '1', '1', '1' }, { '0', '1', '1', '1', '1' },
				{ '0', '0', ' ', '1', '1' }, { '0', '0', '0', '0', '1' }, { '0', '0', '0', '0', '0' } }));
		for (int i = 0; i < n; i++) {
			char[][] grid = new char[5][5];
			for (int j = 0; j < 5; j++)
				grid[j] = in.readLine().toCharArray();
			Grid t = new Grid(grid);
			if (!d.containsKey(t) || d.get(t) > 10)
				out.println("Unsolvable in less than 11 move(s).");
			else
				out.println("Solvable in " + d.get(t) + " move(s).");
		}
		out.flush();

	}

	static HashMap<Grid, Integer> bfs(Grid s) {
		Queue<Grid> Q = new LinkedList<>();
		HashMap<Grid, Boolean> visited = new HashMap<>();
		HashMap<Grid, Integer> d = new HashMap<>();
		d.put(s, 0);
		visited.put(s, true);
		Q.add(s);
		while (!Q.isEmpty()) {
			Grid u = Q.poll();
			if (d.get(u) > 10)
				continue;
			for (Grid v : getVecinos(u))
				if (visited.get(v) == null) {
					visited.put(v, true);
					d.put(v, d.get(u) + 1);
					Q.add(v);
				}
		}
		return d;
	}

	static ArrayList<Grid> getVecinos(Grid u) {
		ArrayList<Grid> ans = new ArrayList<>();
		int[] hueco = findHueco(u);
		int i = hueco[0];
		int j = hueco[1];
		if (i - 2 >= 0 && j + 1 < 5) {
			char knight = u.grid[i - 2][j + 1];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i - 2][j + 1] = ' ';
			ans.add(v);
		}
		if (i - 2 >= 0 && j - 1 >= 0) {
			char knight = u.grid[i - 2][j - 1];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i - 2][j - 1] = ' ';
			ans.add(v);
		}
		if (i - 1 >= 0 && j - 2 >= 0) {
			char knight = u.grid[i - 1][j - 2];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i - 1][j - 2] = ' ';
			ans.add(v);
		}
		if (i - 1 >= 0 && j + 2 < 5) {
			char knight = u.grid[i - 1][j + 2];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i - 1][j + 2] = ' ';
			ans.add(v);
		}
		if (i + 2 < 5 && j + 1 < 5) {
			char knight = u.grid[i + 2][j + 1];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i + 2][j + 1] = ' ';
			ans.add(v);
		}
		if (i + 2 < 5 && j - 1 >= 0) {
			char knight = u.grid[i + 2][j - 1];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i + 2][j - 1] = ' ';
			ans.add(v);
		}
		if (i + 1 < 5 && j + 2 < 5) {
			char knight = u.grid[i + 1][j + 2];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i + 1][j + 2] = ' ';
			ans.add(v);
		}
		if (i + 1 < 5 && j - 2 >= 0) {
			char knight = u.grid[i + 1][j - 2];
			Grid v = copy(u);
			v.grid[i][j] = knight;
			v.grid[i + 1][j - 2] = ' ';
			ans.add(v);
		}
		return ans;

	}

	static Grid copy(Grid a) {
		Grid b = new Grid(new char[5][5]);
		for (int i = 0; i < 5; i++)
			b.grid[i] = a.grid[i].clone();
		return b;
	}

	static int[] findHueco(Grid u) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (u.grid[i][j] == ' ')
					return new int[] { i, j };
		return new int[] {};
	}

	static class Grid {
		char[][] grid;

		Grid(char[][] g) {
			this.grid = g;
		}

		public int hashCode() {
			int ans = 1;
			for (int i = 0; i < 5; i++)
				ans = 499 * ans + Arrays.hashCode(grid[i]);
			return ans;
		}

		public boolean equals(Object o) {
			Grid op = (Grid) o;
			for (int i = 0; i < 5; i++)
				if (!Arrays.equals(grid[i], op.grid[i]))
					return false;
			return true;
		}

		public String toString() {
			StringBuffer res = new StringBuffer();
			for (char[] i : grid)
				res.append(Arrays.toString(i) + "\n");
			return new String(res);
		}
	}
}
