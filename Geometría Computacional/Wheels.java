import java.util.*;
import java.io.*;

public class Wheels {
	static int n;
	static HashMap<Point, ArrayList<Point>> adj;
	static HashMap<Point, Racional> fracciones;
	static HashMap<Point, Boolean> colores;
	static HashMap<Point, Boolean> visited;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(in.readLine());
		for (int cases = 0; cases < t; cases++) {
			n = Integer.parseInt(in.readLine());
			adj = new HashMap<>();
			Point[] circulos = new Point[n];
			Point s = null;
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				if (i == 0)
					s = new Point(i, x, y, r);
				circulos[i] = new Point(i, x, y, r);
			}
			TreeSet<Point> circles = new TreeSet<>(List.of(circulos));
			buildGraph(s, circulos);
			bfs(s);
			Map<Boolean, String> sentido = Map.of(true, "clockwise", false, "counterclockwise");
			for (Point p : circles) {
				if (fracciones.containsKey(p)) {
					Racional frac = fracciones.get(p);
					frac.simplificar();
					System.out.println(frac + " " + sentido.get(colores.get(p)));
				} else
					System.out.println("not moving");
			}

		}

	}

	static void buildGraph(Point s, Point[] circulos) {
		visited = new HashMap<>();
		Stack<Point> pila = new Stack<>();
		pila.push(s);
		visited.put(s, true);
		while (!pila.isEmpty()) {
			Point u = pila.pop();
			for (int i = 0; i < n; i++) {
				Point v = circulos[i];
				if (visited.get(v) == null)
					if (seTocan(u, v)) {
						visited.put(v, true);
						addEdge(u, v);
						pila.push(v);
					}

			}
		}
	}

	static void bfs(Point s) {
		visited = new HashMap<>();
		colores = new HashMap<>();
		fracciones = new HashMap<>();
		Queue<Point> Q = new LinkedList<>();
		Q.add(s);
		fracciones.put(s, new Racional(1, 1));
		visited.put(s, true);
		colores.put(s, true);
		while (!Q.isEmpty()) {
			Point u = Q.poll();
			if (adj.get(u) == null)
				continue;
			for (Point v : adj.get(u)) {
				if (visited.get(v) == null) {
					colores.put(v, !colores.get(u));
					fracciones.put(v, new Racional(s.r, v.r));
					visited.put(v, true);
					Q.add(v);
				}
			}
		}

	}

	static void addEdge(Point c1, Point c2) {
		if (adj.get(c1) == null)
			adj.put(c1, new ArrayList<>());
		adj.get(c1).add(c2);

	}

	static boolean seTocan(Point c1, Point c2) {
		return Math.sqrt(Math.pow(c2.x - c1.x, 2) + Math.pow(c2.y - c1.y, 2)) == c2.r + c1.r;
	}

	static class Point implements Comparable<Point> {
		int prioridad;
		int x;
		int y;
		int r;

		Point(int prioridad, int x, int y, int r) {
			this.prioridad = prioridad;
			this.x = x;
			this.y = y;
			this.r = r;
		}

		public int compareTo(Point c) {
			return Integer.compare(prioridad, c.prioridad);
		}

		public int hashCode() {
			return x * 10007 + y * 499 + r;
		}

		public boolean equals(Object o) {
			Point op = (Point) o;
			return x == op.x && y == op.y && r == op.r;
		}

		public String toString() {
			return "(" + x + ", " + y + ", " + r + ")";
		}

	}

	static class Racional {
		private long numerador;
		private long denominador;

		Racional(long numerador, long denominador) {
			if (denominador == 0)
				denominador = 1;
			this.numerador = numerador;
			this.denominador = denominador;

		}

		public void simplificar() {
			if (mcd(numerador, denominador) != 1) {
				long div = mcd(numerador, denominador);
				numerador /= div;
				denominador /= div;
			}
		}

		public String toString() {
			if (denominador == 1)
				return String.valueOf(numerador);
			else
				return numerador + "/" + denominador;
		}

		private long mcd(long a, long b) {
			if (a % b == 0)
				return b;
			else
				return mcd(b, a % b);
		}
	}

}
