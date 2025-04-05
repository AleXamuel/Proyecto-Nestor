import java.io.*;
import java.util.*;

public class BeeHousePerimeter {
	static int[][] matrix;
	static int r;
	static int n;
	static HashSet<Integer> casa;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		r = in.nextInt();
		int k = in.nextInt();
		casa = new HashSet<>();
		for (int i = 0; i < k; i++)
			casa.add(in.nextInt());
		buildMatrix();
		boolean[] visited = new boolean[n];
		int ans = 0;
		for (int i = 0; i < matrix[0].length; i++) {
			int cell = matrix[0][i];
			if (!visited[cell])
				ans += bfs(cell, visited);
		}
		for (int i = 0; i < matrix[matrix.length - 1].length; i++) {
			int cell = matrix[matrix.length - 1][i];
			if (!visited[cell])
				ans += bfs(cell, visited);
		}
		for (int i = 0; i < matrix.length; i++) {
			int cell = matrix[i][0];
			if (!visited[cell])
				ans += bfs(cell, visited);
		}
		for (int i = 0; i < matrix.length; i++) {
			int cell = matrix[i][matrix[i].length - 1];
			if (!visited[cell])
				ans += bfs(cell, visited);
		}
		System.out.println(ans);
	}

	static int bfs(int s, boolean[] visited) {
		if (casa.contains(s)) {
			visited[s] = true;
			return 6 - deg(s);
		}
		Queue<Integer> Q = new LinkedList<>();
		Q.add(s);
		visited[s] = true;
		int ans = 0;
		while (!Q.isEmpty()) {
			int u = Q.poll();
			for (int v : getVecinos(u))
				if (casa.contains(v))
					ans++;
				else if (!visited[v]) {
					visited[v] = true;
					Q.add(v);
				}
		}
		return ans;
	}

	static int deg(int u) {
		return getVecinos(u).size();
	}

	static ArrayList<Integer> getVecinos(int u) {
		ArrayList<Integer> vecinos = new ArrayList<>();
		int indiceFila = 0;
		int indiceColumna = 0;
		for (int i = 0; i < matrix.length; i++) {
			int val = Arrays.binarySearch(matrix[i], u);
			if (val >= 0) {
				indiceFila = i;
				indiceColumna = val;
				break;
			}
		}
		if (indiceColumna == 0) {
			if (indiceFila == 0) {
				vecinos.add(matrix[0][1]);
				vecinos.add(matrix[1][0]);
				vecinos.add(matrix[1][1]);
				return vecinos;
			}
			if (indiceFila == (r - 1)) {
				vecinos.add(matrix[r - 2][0]);
				vecinos.add(matrix[r - 1][1]);
				vecinos.add(matrix[r][0]);
				return vecinos;
			}
			if (indiceFila == matrix.length - 1) {
				vecinos.add(matrix[indiceFila - 1][indiceColumna]);
				vecinos.add(matrix[indiceFila - 1][indiceColumna + 1]);
				vecinos.add(matrix[indiceFila][indiceColumna + 1]);
				return vecinos;
			} else {
				if (indiceFila < (r - 1)) {
					vecinos.add(matrix[indiceFila - 1][indiceColumna]);
					vecinos.add(matrix[indiceFila][indiceColumna + 1]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna + 1]);
					return vecinos;
				} else {
					vecinos.add(matrix[indiceFila - 1][indiceColumna]);
					vecinos.add(matrix[indiceFila][indiceColumna + 1]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna]);
					vecinos.add(matrix[indiceFila - 1][indiceColumna + 1]);
					return vecinos;
				}
			}
		}
		if (indiceColumna == matrix[indiceFila].length - 1) {
			if (indiceFila == 0) {
				vecinos.add(matrix[0][matrix[indiceFila].length - 2]);
				vecinos.add(matrix[1][matrix[indiceFila].length - 1]);
				vecinos.add(matrix[1][matrix[indiceFila].length]);
				return vecinos;
			}
			if (indiceFila == (r - 1)) {
				vecinos.add(matrix[r - 2][matrix[indiceFila].length - 2]);
				vecinos.add(matrix[r - 1][matrix[indiceFila].length - 2]);
				vecinos.add(matrix[r][matrix[indiceFila].length - 2]);
				return vecinos;
			}
			if (indiceFila == matrix.length - 1) {
				vecinos.add(matrix[matrix.length - 2][indiceColumna]);
				vecinos.add(matrix[matrix.length - 2][indiceColumna + 1]);
				vecinos.add(matrix[matrix.length - 1][indiceColumna - 1]);
				return vecinos;
			} else {
				if (indiceFila < r - 1) {
					vecinos.add(matrix[indiceFila - 1][indiceColumna - 1]);
					vecinos.add(matrix[indiceFila][indiceColumna - 1]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna + 1]);
					return vecinos;
				} else {
					vecinos.add(matrix[indiceFila - 1][indiceColumna + 1]);
					vecinos.add(matrix[indiceFila - 1][indiceColumna]);
					vecinos.add(matrix[indiceFila][indiceColumna - 1]);
					vecinos.add(matrix[indiceFila + 1][indiceColumna - 1]);
					return vecinos;
				}
			}
		}
		if (indiceFila == 0) {
			vecinos.add(matrix[indiceFila][indiceColumna - 1]);
			vecinos.add(matrix[indiceFila][indiceColumna + 1]);
			vecinos.add(matrix[indiceFila + 1][indiceColumna]);
			vecinos.add(matrix[indiceFila + 1][indiceColumna + 1]);
			return vecinos;
		}
		if (indiceFila == matrix.length - 1) {
			vecinos.add(matrix[indiceFila][indiceColumna - 1]);
			vecinos.add(matrix[indiceFila][indiceColumna + 1]);
			vecinos.add(matrix[indiceFila - 1][indiceColumna]);
			vecinos.add(matrix[indiceFila - 1][indiceColumna + 1]);
			return vecinos;
		} else {
			vecinos.add(matrix[indiceFila][indiceColumna - 1]);
			vecinos.add(matrix[indiceFila][indiceColumna + 1]);
			if (indiceFila < (r - 1)) {
				vecinos.add(matrix[indiceFila - 1][indiceColumna - 1]);
				vecinos.add(matrix[indiceFila - 1][indiceColumna]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna + 1]);
			} else if (indiceFila == (r - 1)) {
				vecinos.add(matrix[indiceFila - 1][indiceColumna - 1]);
				vecinos.add(matrix[indiceFila - 1][indiceColumna]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna - 1]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna]);
			} else {
				vecinos.add(matrix[indiceFila - 1][indiceColumna]);
				vecinos.add(matrix[indiceFila - 1][indiceColumna + 1]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna - 1]);
				vecinos.add(matrix[indiceFila + 1][indiceColumna]);
			}
			return vecinos;
		}

	}

	static void buildMatrix() {
		int nrows = (r * 2) - 1;
		int ncol = r;
		int num = 1;
		boolean cond = true;
		matrix = new int[nrows][];
		for (int i = 0; i < nrows; i++) {
			int[] row = new int[ncol];
			for (int j = 0; j < ncol; j++) {
				row[j] = num;
				num++;
			}
			matrix[i] = row;
			if (cond)
				ncol++;
			else
				ncol--;
			if (i + 1 == r) {
				ncol -= 2;
				cond = false;
			}

		}
		n = num;
	}

	static class Input {
		BufferedReader br;
		StringTokenizer st;

		public Input(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() throws Exception {
			return br.readLine();
		}

		public void close() throws IOException {
			br.close();
		}

		public boolean hasNext() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (Exception e) {
				return false;
			}
			return true;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}
}
