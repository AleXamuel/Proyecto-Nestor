//https://codeforces.com/problemset/problem/242/C
import java.util.*;
import java.io.*;

public class KingsPath {

	static HashMap<Integer, HashSet<Intervalo>> allowed;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		Pair s = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		Pair t = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		int n = Integer.parseInt(in.readLine());
		allowed = new HashMap<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			int row = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			if (!allowed.containsKey(row))
				allowed.put(row, new HashSet<>());
			allowed.get(row).add(new Intervalo(l, r));
		}
		System.out.println(bfs(s, t));

	}

	static int bfs(Pair s, Pair t) {
		HashMap<Pair, Integer> d = new HashMap<>();
		HashMap<Pair, Boolean> visited = new HashMap<>();
		Queue<Pair> Q = new LinkedList<>();
		Q.add(s);
		d.put(s, 0);
		visited.put(s, true);
		while (!Q.isEmpty()) {
			Pair u = Q.poll();
			int r = u.x;
			int c = u.y;
			if (allowed.containsKey(r - 1)) {
				Pair v1 = new Pair(r - 1, c);
				Pair v2 = new Pair(r - 1, c - 1);
				Pair v3 = new Pair(r - 1, c + 1);
				for (Intervalo i : allowed.get(r - 1)) {
					if (isin(i.l, i.r, c) && visited.get(v1) == null) {
						visited.put(v1, true);
						d.put(v1, d.get(u) + 1);
						Q.add(v1);
					}
					if (isin(i.l, i.r, c - 1) && visited.get(v2) == null) {
						visited.put(v2, true);
						d.put(v2, d.get(u) + 1);
						Q.add(v2);
					}
					if (isin(i.l, i.r, c + 1) && visited.get(v3) == null) {
						visited.put(v3, true);
						d.put(v3, d.get(u) + 1);
						Q.add(v3);
					}
				}
			}
			if (allowed.containsKey(r + 1)) {
				Pair v1 = new Pair(r + 1, c);
				Pair v2 = new Pair(r + 1, c - 1);
				Pair v3 = new Pair(r + 1, c + 1);
				for (Intervalo i : allowed.get(r + 1)) {
					if (isin(i.l, i.r, c) && visited.get(v1) == null) {
						visited.put(v1, true);
						d.put(v1, d.get(u) + 1);
						Q.add(v1);
					}
					if (isin(i.l, i.r, c - 1) && visited.get(v2) == null) {
						visited.put(v2, true);
						d.put(v2, d.get(u) + 1);
						Q.add(v2);
					}
					if (isin(i.l, i.r, c + 1) && visited.get(v3) == null) {
						visited.put(v3, true);
						d.put(v3, d.get(u) + 1);
						Q.add(v3);
					}
				}
			}
			Pair v1 = new Pair(r, c + 1);
			Pair v2 = new Pair(r, c - 1);
			for (Intervalo i : allowed.get(r)) {
				if (isin(i.l, i.r, c + 1) && visited.get(v1) == null) {
					visited.put(v1, true);
					d.put(v1, d.get(u) + 1);
					Q.add(v1);
				}
				if (isin(i.l, i.r, c - 1) && visited.get(v2) == null) {
					visited.put(v2, true);
					d.put(v2, d.get(u) + 1);
					Q.add(v2);
				}
			}
		}
		return d.get(t) != null ? d.get(t) : -1;

	}

	static boolean isin(int l, int r, int x) {
		return l <= x && x <= r;
	}

	static class Intervalo {
		int l, r;

		Intervalo(int l, int r) {
			this.l = l;
			this.r = r;
		}

		public int hashCode() {
			return Objects.hash(l, r);
		}

		public boolean equals(Object o) {
			Intervalo op = (Intervalo) o;
			return r == op.r && l == op.l;
		}
	}

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int hashCode() {
			return Objects.hash(x, y);
		}

		public boolean equals(Object o) {
			Pair op = (Pair) o;
			return x == op.x && y == op.y;
		}
	}

}
