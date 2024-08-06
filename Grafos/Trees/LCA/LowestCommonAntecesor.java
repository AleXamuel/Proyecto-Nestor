//https://www.spoj.com/problems/LCASQ/
import java.util.*;
import java.io.*;

public class LowestCommonAncestor {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int m = in.nextInt();
			for (int j = 0; j < m; j++)
				adj[i].add(in.nextInt());
		}
		LCA me = new LCA(adj, 0);
		int q = in.nextInt();
		for (int i = 0; i < q; i++)
			System.out.println(me.getLCA(in.nextInt(), in.nextInt()));

	}

	static class LCA {
		int[] H, E, L;
		SegmentTreeArray tree;

		int getLCA(int a, int b) {
			int ma = Math.min(H[a], H[b]);
			int mb = H[a] + H[b] - ma;
			int pos = tree.getPosMin(ma, mb);
			return E[pos];
		}

		LCA(ArrayList<Integer>[] adjList, int raiz) {
			int n = adjList.length;
			ArrayList<Integer> EL = new ArrayList<Integer>();
			ArrayList<Integer> LL = new ArrayList<Integer>();
			H = new int[n];
			Arrays.fill(H, -1);
			preprocess(EL, LL, H, adjList, raiz, 0);
			E = new int[EL.size()];
			L = new int[LL.size()];
			int k = 0;
			for (Integer x : EL) {
				E[k] = x;
				k++;
			}
			k = 0;
			for (Integer x : LL) {
				L[k] = x;
				k++;
			}
			tree = new SegmentTreeArray(L);
		}

		void preprocess(ArrayList<Integer> EL, ArrayList<Integer> LL, int[] H, ArrayList<Integer>[] adjList, int raiz,
				int nivel) {
			EL.add(raiz);
			if (H[raiz] == -1)
				H[raiz] = EL.size() - 1;
			LL.add(nivel);
			for (Integer s : adjList[raiz]) {
				preprocess(EL, LL, H, adjList, s, nivel + 1);
				EL.add(raiz);
				LL.add(nivel);
			}
		}

	}

	static class SegmentTreeArray {
		int[] start, end, posMin, A;
		int n;

		public SegmentTreeArray(int[] A) {
			this.A = A;
			n = A.length;
			start = new int[4 * n];
			end = new int[4 * n];
			posMin = new int[4 * n];
			// start[i] == -1 significa que no existe el nodo
			Arrays.fill(start, -1);
			initSegmentTree(A);
		}

		void initSegmentTree(int[] A) {
			createTree(0, 0, n - 1);
			computePosMin(A, 0);
		}

		int computePosMin(int[] A, int node) {
			if (start[node] == -1)
				return -1;
			if (start[node] == end[node]) {
				posMin[node] = start[node];
				return posMin[node];
			}
			if (A[computePosMin(A, 2 * node + 1)] < A[computePosMin(A, 2 * node + 2)])
				posMin[node] = computePosMin(A, 2 * node + 1);
			else
				posMin[node] = computePosMin(A, 2 * node + 2);
			return posMin[node];
		}

		void createTree(int node, int s, int e) {
			if (s > e)
				return;
			start[node] = s;
			end[node] = e;
			if (s == e) {
				return;
			}
			int mid = (s + e) / 2;
			createTree(2 * node + 1, s, mid);
			createTree(2 * node + 2, mid + 1, e);
		}

		void set(int pos, int value) {
			set(pos, value, 0);
		}

		void set(int pos, int value, int node) {
			if (start[node] == -1 || start[node] > pos || end[node] < pos)
				return;
			if (start[node] == end[node]) {
				posMin[node] = start[node];
				A[posMin[node]] = value;
				return;
			}
			int mid = (start[node] + end[node]) / 2;
			if (pos <= mid)
				set(pos, value, 2 * node + 1);
			else
				set(pos, value, 2 * node + 2);
			if (A[posMin[2 * node + 1]] < A[posMin[2 * node + 2]])
				posMin[node] = posMin[2 * node + 1];
			else
				posMin[node] = posMin[2 * node + 2];
		}

		int getPosMin(int low, int high) {
			return getPosMin(low, high, 0);
		}

		int getPosMin(int low, int high, int node) {
			if (start[node] == -1)
				return -1;
			if (low == start[node] && high == end[node]) {
				return posMin[node];
			}
			int mid = (start[node] + end[node]) / 2;
			if (high <= mid)
				return getPosMin(low, high, 2 * node + 1);
			if (low > mid)
				return getPosMin(low, high, 2 * node + 2);
			int p, q;
			p = getPosMin(low, mid, 2 * node + 1);
			q = getPosMin(mid + 1, high, 2 * node + 2);
			if (A[p] < A[q])
				return p;
			else
				return q;
		}
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
