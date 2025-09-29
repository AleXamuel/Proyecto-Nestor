//https://codeforces.com/problemset/problem/1971/C
import java.io.*;
import java.util.*;
import java.awt.geom.Line2D;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter((System.out));
		StringTokenizer st;
		HashMap<Integer, Point> H = new HashMap<>();
		int i = 1;
		for (int a = 0; a <= 360; a += 30)
			H.put(i++, new Point(Math.cos(Math.toRadians(a)), Math.sin(Math.toRadians(a))));
		int T = Integer.parseInt(in.readLine());
		while (T-- > 0) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			double x1 = H.get(a).x;
			double y1 = H.get(a).y;
			double x2 = H.get(b).x;
			double y2 = H.get(b).y;

			double x3 = H.get(c).x;
			double y3 = H.get(c).y;
			double x4 = H.get(d).x;
			double y4 = H.get(d).y;
			out.println(Line2D.linesIntersect(x1, y1, x2, y2, x3, y3, x4, y4) ? "YES" : "NO");
		}
		out.close();
	}

	static class Point {
		double x, y;

		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}

}
