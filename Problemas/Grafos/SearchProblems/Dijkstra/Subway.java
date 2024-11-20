//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1330
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Subway {

	static HashMap<Point, ArrayList<Edge>> adj;
	static HashMap<Point, Double> d;
	static HashMap<Point, Boolean> visited;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		in.readLine();
		for (int i = 0; i < T; i++) {
			st = new StringTokenizer(in.readLine());
			Point s = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			Point t = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			adj = new HashMap<>();
			d = new HashMap<>();
			visited = new HashMap<>();
			adj.put(s, new ArrayList<>());
			adj.put(t, new ArrayList<>());
			d.put(s, Double.POSITIVE_INFINITY);
			d.put(t, Double.POSITIVE_INFINITY);
			visited.put(s, false);
			visited.put(t, false);
			List<List<Point>> lines = new ArrayList<>();
			List<Point> l = new ArrayList<>();
			while (true) {
				try {
					st = new StringTokenizer(in.readLine());
				} catch (Exception e) {
					break;
				}
				if (!st.hasMoreTokens())
					break;
				while (st.hasMoreTokens()) {
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					if (x == -1 && y == -1) {
						lines.add(l);
						l = new ArrayList<>();
						break;
					}
					Point p = new Point(x, y);
					l.add(p);
					adj.put(p, new ArrayList<>());
					d.put(p, Double.MAX_VALUE);
					visited.put(p, false);
				}
			}
			for (Point p1 : adj.keySet())
				for (Point p2 : adj.keySet())
					addEdge(p1, p2, p1.distance(p2) / (10 / 3.6));

			for (List<Point> list : lines)
				for (int j = 0; j < list.size() - 1; j++) {
					Point p1 = list.get(j);
					Point p2 = list.get(j + 1);
					addEdge(p1, p2, p1.distance(p2) / (40 / 3.6));
				}

			dijkstra(s);
			out.println(Math.round(d.get(t) / 60));
			if (i != T - 1)
				out.println();
		}
		out.flush();
	}

	static void dijkstra(Point s) {
		TreeSet<Edge> Q = new TreeSet<>();
		d.put(s, 0.0);
		Q.add(new Edge(s, 0.0));
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			Point u = e.vertex;
			if (!visited.get(u)) {
				visited.put(u, true);
				for (Edge ee : adj.get(u)) {
					Point v = ee.vertex;
					double w = ee.weight;
					double cost = d.get(u) + w;
					if (!visited.get(v) && cost < d.get(v)) {
						d.put(v, cost);
						Q.add(new Edge(v, cost));
					}
				}
			}
		}
	}

	static void addEdge(Point a, Point b, double cost) {
		adj.get(a).add(new Edge(b, cost));
		adj.get(b).add(new Edge(a, cost));
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
