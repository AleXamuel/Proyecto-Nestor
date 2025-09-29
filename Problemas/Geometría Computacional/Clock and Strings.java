//https://codeforces.com/problemset/problem/1971/C
import java.io.*;
import java.util.*;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter((System.out));
		StringTokenizer st;
		HashMap<Integer, Point2D.Double> H = new HashMap<>();
		int i = 1;
		for (int a = 0; a <= 360; a += 30)
			H.put(i++, new Point2D.Double(Math.cos(Math.toRadians(a)), Math.sin(Math.toRadians(a))));
		int T = Integer.parseInt(in.readLine());
		while (T-- > 0) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			Line2D l1 = new Line2D.Double(H.get(a), H.get(b));
			Line2D l2 = new Line2D.Double(H.get(c), H.get(d));
			out.println(l1.intersectsLine(l2) ? "YES" : "NO");
		}
		out.close();
	}
}
