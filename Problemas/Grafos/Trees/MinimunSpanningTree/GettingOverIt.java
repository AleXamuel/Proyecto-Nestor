//Private contest
import java.util.*;
import java.io.*;
import java.awt.Point;

public class GettingOverIt {
	static List<Point> puntos;
	static HashMap<Point, Double> d;
	static HashMap<Point, Boolean> visited;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(in.readLine());
		puntos = new ArrayList<>();
		d = new HashMap<>();
		visited = new HashMap<>();
		Point s = new Point(0, 0);
		puntos.add(s);
		d.put(s, 0d);
		visited.put(s, false);
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			Point p = new Point(x, y);
			puntos.add(p);
			d.put(p, Double.POSITIVE_INFINITY);
			visited.put(p, false);
		}
		prim(s);
		long ans = 0;
		for (double cost : d.values())
			ans += cost;
		System.out.println(ans);

	}

	static void prim(Point s) {
		TreeSet<Edge> Q = new TreeSet<>();
		Q.add(new Edge(s, 0d));
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			Point u = e.vertex;
			if (!visited.get(u)) {
				visited.put(u, true);
				for (Point v : puntos) {
					if (visited.get(v))
						continue;
					double w = Math.pow(u.x - v.x, 2) + Math.pow(u.y - v.y, 2);
					if (w < d.get(v)) {
						d.put(v, w);
						Q.add(new Edge(v, w));
					}
				}
			}
		}
	}

	static class Edge implements Comparable<Edge> {
		Point vertex;
		double weight;

		Edge(Point v, double w) {
			this.vertex = v;
			this.weight = w;
		}

		public int compareTo(Edge e) {
			if (weight < e.weight)
				return -1;
			if (weight > e.weight)
				return 1;
			if (vertex.x == e.vertex.x)
				return vertex.y - e.vertex.y;
			return vertex.x - e.vertex.x;
		}
	}

}
