import java.io.*;
import java.util.*;

public class FindingLines {
	static int n;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(in.readLine());
		double p = Double.parseDouble(in.readLine());
		Point[] puntos = new Point[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			puntos[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		System.out.println(solve(puntos, p) ? "possible" : "impossible");

	}

	static boolean solve(Point[] puntos, double p) {
		if (n < 3)
			return true;
		Random rand = new Random();
		for (int i = 0; i < 250; i++) {
			Point p1 = puntos[rand.nextInt(0, n)];
			Point p2 = puntos[rand.nextInt(0, n)];
			if (p1 == p2 || p1.equals(p2))
				continue;
			double frac = 0;
			Point vector1 = restarVectores(p2, p1);
			for (Point point : puntos) {
				Point vector2 = restarVectores(point, p1);
				if (productoCruzado(vector2, vector1) == 0)
					frac++;
				if ((frac / n) >= (p / 100))
					return true;
			}
		}

		return false;
	}

	static Point restarVectores(Point p1, Point p2) {
		return new Point(p1.x - p2.x, p1.y - p2.y);
	}

	static int productoCruzado(Point p1, Point p2) {
		return p1.x * p2.y - p1.y * p2.x;
	}

	static class Point {
		int x;
		int y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

}
