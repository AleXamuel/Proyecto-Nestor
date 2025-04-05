import java.io.*;
import java.util.*;
import java.awt.geom.*;

public class Logo {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int test = in.nextInt();
		for (int cases = 0; cases < test; cases++) {
			int n = in.nextInt();
			Point2D.Double origen = new Point2D.Double(0, 0);
			Point2D.Double destino = new Point2D.Double(0, 0);
			double angle = 0;
			for (int i = 0; i < n; i++) {
				String dir = in.next();
				int unit = in.nextInt();
				if (dir.equals("fd"))
					destino.setLocation(destino.x + unit * Math.cos(Math.toRadians(angle)),
							destino.y + unit * Math.sin(Math.toRadians(angle)));
				else if (dir.equals("bk"))
					destino.setLocation(destino.x - unit * Math.cos(Math.toRadians(angle)),
							destino.y - unit * Math.sin(Math.toRadians(angle)));
				else if (dir.equals("lt"))
					angle += unit;
				else
					angle -= unit;
			}
			System.out.println(Math.round(origen.distance(destino)));
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() throws Exception {
			return br.readLine();
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

	}
}
