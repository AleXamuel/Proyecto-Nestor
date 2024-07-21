import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.util.*;

public class AbstractArt {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		Polygon[] poligonos = new Polygon[n];
		for (int i = 0; i < n; i++) {
			int m = in.nextInt();
			int[] x = new int[m];
			int[] y = new int[m];
			for (int j = 0; j < m; j++) {
				x[j] = in.nextInt();
				y[j] = in.nextInt();
			}
			poligonos[i] = new Polygon(x, y, m);
		}
		double ans = 0;
		Area a = new Area();
		for (Polygon p : poligonos) {
			Area aux = new Area(p);
			ans += Area(aux);
			a.add(aux);
		}
		System.out.print(ans);
		System.out.println(" " + Area(a));

	}

	static double Area(Area a) {
		double ans = 0;
		PathIterator it = a.getPathIterator(null);
		double[] coords = new double[6];
		double[] first = new double[2];
		double[] last = new double[2];
		while (!it.isDone()) {
			int val = it.currentSegment(coords);
			if (val == 0) {
				first[0] = coords[0];
				first[1] = coords[1];
				last[0] = coords[0];
				last[1] = coords[1];
			} else if (val == 1) {
				ans += (last[0] * coords[1] - last[1] * coords[0]);
				last[0] = coords[0];
				last[1] = coords[1];
			} else if (val == 4)
				ans += (last[0] * first[1] - last[1] * first[0]);

			it.next();
		}
		return Math.abs(ans) / 2;
	}

	static class Input {
		BufferedReader br;
		StringTokenizer st;

		Input(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}
