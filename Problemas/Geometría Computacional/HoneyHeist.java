import java.util.*;
import java.io.*;

public class HoneyHeist {
	static HashSet<Integer> blocked;
	static int[][] matrix;
	static int r;
	static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		r = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());
		blocked = new HashSet<>();
		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < X; i++)
			blocked.add(Integer.parseInt(st.nextToken()));
		buildMatrix();
		int ans = bfs(A, B, N);
		System.out.println(ans > 0 ? ans : "NO");

	}

	static int bfs(int s, int t, int pasos) {
		boolean[] visited = new boolean[n];
		int[] d = new int[n];
		visited[s] = true;
		d[s] = 0;
		Queue<Integer> Q = new LinkedList<>();
		Q.add(s);
		while (!Q.isEmpty()) {
			int u = Q.poll();
			for (int v : getVecinos(u))
				if (blocked.contains(v))
					visited[v] = true;
				else if (!visited[v]) {
					visited[v] = true;
					d[v] = d[u] + 1;
					Q.add(v);
				}

		}
		if (d[t] > pasos)
			return -1;
		else
			return d[t];

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

}
