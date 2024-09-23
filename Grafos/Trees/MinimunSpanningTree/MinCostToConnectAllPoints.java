import java.util.*;

public class MinCostToConnectAllPoints {

	static int minCostConnectPoints(int[][] points) {
		return prim(points);
	}

	static int prim(int[][] points) {
		HashMap<Point, Integer> d = new HashMap<>();
		HashMap<Point, Boolean> visited = new HashMap<>();
		TreeSet<Edge> Q = new TreeSet<>();
		Point s = new Point(points[0][0], points[0][1]);
		d.put(s, 0);
		Q.add(new Edge(s, 0));
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			Point u = e.vertex;
			int ru = u.x;
			int cu = u.y;
			if (visited.get(u) == null) {
				visited.put(u, true);
				for (int[] ee : points) {
					Point v = new Point(ee[0], ee[1]);
					if (u.equals(v) || visited.get(v) != null)
						continue;
					int rv = v.x;
					int cv = v.y;
					int w = cost(ru, cu, rv, cv);
					if (d.get(v) == null || w < d.get(v)) {
						d.put(v, w);
						Q.add(new Edge(v, w));
					}
				}
			}

		}
		int ans = 0;
		for (int w : d.values())
			ans += w;
		return ans;
	}

	static int cost(int x1, int y1, int x2, int y2) {
		return Math.abs(x1 - x2) + Math.abs(y1 - y2);
	}

	static class Point {
		int x;
		int y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int hashCode() {
			return Objects.hash(x, y);
		}

		public boolean equals(Object o) {
			Point op = (Point) o;
			return x == op.x && y == op.y;
		}
	}

	static class Edge implements Comparable<Edge> {
		Point vertex;
		int weight;

		Edge(Point p, int w) {
			this.vertex = p;
			this.weight = w;
		}

		public int compareTo(Edge o) {
			if (weight < o.weight)
				return -1;
			if (weight > o.weight)
				return 1;
			if (vertex.y == o.vertex.y)
				return Integer.compare(vertex.x, o.vertex.x);
			return Integer.compare(vertex.y, o.vertex.y);

		}

	}

}
