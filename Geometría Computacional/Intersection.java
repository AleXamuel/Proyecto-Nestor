import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import java.io.*;
import java.util.*;

public class Intersection {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			int x3 = in.nextInt();
			int y3 = in.nextInt();
			int x4 = in.nextInt();
			int y4 = in.nextInt();
			Line2D.Double line = new Line2D.Double(x1, y1, x2, y2);
			int xmin = Math.min(x3, x4);
			int ymin = Math.min(y3, y4);
			Rectangle2D.Double rectangle = new Rectangle2D.Double(xmin, ymin, Math.abs(x3 - x4), Math.abs(y3 - y4));
			System.out.println(rectangle.intersectsLine(line) ? "T" : "F");
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
